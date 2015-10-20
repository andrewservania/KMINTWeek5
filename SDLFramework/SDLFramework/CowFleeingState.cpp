#include "CowFleeingState.h"
#include "CowWanderingState.h"
#include "Rabbit.h"
#include "CowFleeAndSearchPillState.h"
#include "CowFleeAndSearchWeaponState.h"

CowFleeingState::CowFleeingState()
{
	hasStarted = false;

}


CowFleeingState::~CowFleeingState()
{
}

void CowFleeingState::Enter(Cow* cow)
{
	Start(cow);
}

void CowFleeingState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);

		hasStarted = true;
	}
	if (NoThreat(cow)){
		cow->GetFSM()->ChangeState(CowWanderingState::Instance());
	}
}

void CowFleeingState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(2000.0);
	cow->Steering()->EvadeOff();
	hasStarted = false;
}

void CowFleeingState::Start(Cow* cow)
{
	cow->SetMaxSpeed(27000.0);
	cow->Steering()->EvadeOn(reinterpret_cast<Vehicle*>(cow->GetEnemy()));
}

bool CowFleeingState::NoThreat(Cow* cow)
{
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 300  &&
		 cow->Pos().x < cow->GetEnemy()->Pos().x + 300) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 300  &&
		 cow->Pos().y < cow->GetEnemy()->Pos().y + 300))
	{
			return false; 
	}	
		else return true;
	
		return false;
}