#include "CowWanderingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"
#include "CowFleeAndSearchPillState.h"
#include "CowFleeAndSearchWeaponState.h"
#include "CowHidingState.h"

CowWanderingState::CowWanderingState()
{

	hasStarted = false;
}


CowWanderingState::~CowWanderingState()
{
	
}

void CowWanderingState::Enter(Cow* cow)
{
	Start(cow);
}

void CowWanderingState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);
		hasStarted = true;
	}

	// Slowly normalize the speed of the cow after coming back to from the fleeing state
	if (cow->MaxSpeed() > 50.0){
		cow->SetMaxSpeed(cow->MaxSpeed() - 50.0);
		
	}
	if (cow->MaxSpeed() < 50.0)
	{
		cow->SetMaxSpeed(50.0);
	}

	if (IsThreadEminent(cow)){
		// Choose next action
		switch (cow->GetProbabilityDistribution()->GenerateRandomChoice())
		{
		case 1: 
			cow->GetFSM()->ChangeState(CowFleeingState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());
			break;
		case 2: 
			cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeingState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());

			break;
		case 3: 
			cow->GetFSM()->ChangeState(CowFleeAndSearchPillState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeingState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());
			break;
		case 4:
			cow->GetFSM()->ChangeState(CowHidingState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeingState::Instance());
			//cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());
			break;
		}
		
	}
		
}

void CowWanderingState::Exit(Cow* cow)
{
	hasStarted = false;
	cow->Steering()->WanderOff();
}

void CowWanderingState::Start(Cow* cow)
{
	cow->Steering()->WanderOn();
}

bool CowWanderingState::IsThreadEminent(Cow* cow)
{
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 300 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 300) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 300 &&
		cow->Pos().y <  cow->GetEnemy()->Pos().y + 300))
	{
		return true;
	}
	else return false;

	return false;
}