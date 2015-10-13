#include "CowSearchForPillState.h"
#include "CowHidingState.h"
#include "Rabbit.h"
#include "CowFleeingState.h"
CowSearchForPillState::CowSearchForPillState()
{
}


CowSearchForPillState::~CowSearchForPillState()
{
}

void CowSearchForPillState::Enter(Cow* cow)
{
	cow->SetMaxSpeed(200.0);
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetPill()));
}

void CowSearchForPillState::Execute(Cow* cow)
{
	float distanceBetweenPillAndCow = cow->DistanceTo(cow->GetPill());
	if (distanceBetweenPillAndCow <= 50)
	{
		cow->GetPill()->SetOffset(rand() % 800, rand() % 600);
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit < 100)
	{
		cow->GetFSM()->ChangeState(CowFleeingState::Instance());
	}
}

void CowSearchForPillState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
}

void CowSearchForPillState::Start(Cow* cow)
{

}