#include "CowFleeingState.h"
#include "CowWanderingState.h"
#include "Rabbit.h"
#include "CowSearchForPillState.h"
#include "CowSearchForWeaponState.h"

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

		// If the cow was already trying to catch a pill, instruct it to continue on trying to catch the pill
		if (cow->GetFSM()->PreviousState()->GetStateName() == "Search For Pill")
		{
			cow->GetFSM()->ChangeState(CowSearchForPillState::Instance());
		}
		else if (cow->GetFSM()->PreviousState()->GetStateName() == "Search For Weapon")
		{
			cow->GetFSM()->ChangeState(CowSearchForWeaponState::Instance());
		} else
		cow->GetFSM()->ChangeState(CowWanderingState::Instance());
	}
}

void CowFleeingState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	hasStarted = false;
}

void CowFleeingState::Start(Cow* cow)
{
	cow->Steering()->EvadeOn(reinterpret_cast<Vehicle*>(cow->GetEnemy()));
	cow->SetMaxSpeed(50000.0);
}

bool CowFleeingState::NoThreat(Cow* cow)
{
	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit > 300.0f)
		{
			return true; 
		}	
		else return false;
	
		return false;
}