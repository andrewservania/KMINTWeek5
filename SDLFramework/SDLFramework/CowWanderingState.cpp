#include "CowWanderingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"
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

	if (IsThreadEminent(cow)) cow->GetFSM()->ChangeState(CowFleeingState::Instance());
}

void CowWanderingState::Exit(Cow* cow)
{
	hasStarted = false;
}

void CowWanderingState::Start(Cow* cow)
{
	cow->Steering()->WanderOn();
	cow->Steering()->CreateRandomPath(4, rand() % 100, rand() % 100, rand() % 1300, rand() % 700);
	cow->Steering()->FollowPathOn();
}

bool CowWanderingState::IsThreadEminent(Cow* cow)
{
	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit <= 200)
		return true; 
	else 
		return false;

	return false;
}