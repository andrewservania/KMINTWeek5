#include "CowWanderingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"
#include "ProbabilityDistribution.h"
#include "CowSearchForPillState.h"
#include "CowSearchForWeaponState.h"

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
			cow->GetFSM()->ChangeState(CowSearchForWeaponState::Instance());
			break;
		case 3: 
			cow->GetFSM()->ChangeState(CowSearchForPillState::Instance());
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
	cow->Steering()->WanderOn();
	cow->Steering()->CreateRandomPath(1, rand() % 100, rand() % 100, rand() % 1300, rand() % 700);
	cow->Steering()->FollowPathOn();
}

bool CowWanderingState::IsThreadEminent(Cow* cow)
{
	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit <= 300)
		return true; 
	else 
		return false;

	return false;
}