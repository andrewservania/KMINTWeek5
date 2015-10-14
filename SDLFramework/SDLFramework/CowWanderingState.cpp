#include "CowWanderingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"
#include "ProbabilityDistribution.h"
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

	if (IsThreadEminent(cow)){
		// Choose next action
		switch (ProbabilityDistribution::Instance()->GenerateRandomChoice())
		{
		case 1: 
			cow->GetFSM()->ChangeState(CowFleeingState::Instance());
			break;
		case 2: 
			cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());
			break;
		case 3: 
			cow->GetFSM()->ChangeState(CowFleeAndSearchPillState::Instance());
			break;
		case 4:
			cow->GetFSM()->ChangeState(CowHidingState::Instance());
			break;
		}
		
	}
		
}

void CowWanderingState::Exit(Cow* cow)
{
	hasStarted = false;
}

void CowWanderingState::Start(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	cow->SetVelocity(Vector2D(200, 100));
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