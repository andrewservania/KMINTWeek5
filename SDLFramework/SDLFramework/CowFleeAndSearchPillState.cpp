#include "CowFleeAndSearchPillState.h"
#include "CowHidingState.h"
#include "Rabbit.h"
#include "CowFleeingState.h"
CowFleeAndSearchPillState::CowFleeAndSearchPillState()
{
}


CowFleeAndSearchPillState::~CowFleeAndSearchPillState()
{
}

void CowFleeAndSearchPillState::Enter(Cow* cow)
{
	
}

void CowFleeAndSearchPillState::Execute(Cow* cow)
{

	float distanceDistanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceDistanceBetweenCowAndRabbit < 300)
	{
		cow->SetMaxSpeed(38000.0);
		cow->Steering()->EvadeOn(cow->GetEnemy());
		cow->Steering()->PursuitOff();
	}
	else{
		cow->SetMaxSpeed(400.0);
		cow->Steering()->PursuitOn(cow->GetPill());
	}
	 if ((cow->Pos().x > cow->GetPill()->Pos().x - 25 &&
		cow->Pos().x < cow->GetPill()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetPill()->Pos().y - 25 &&
		cow->Pos().y < cow->GetPill()->Pos().y + 25))
	{
		cow->GetPill()->Respawn();
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
}

void CowFleeAndSearchPillState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	cow->Steering()->PursuitOff();
	
}

void CowFleeAndSearchPillState::Start(Cow* cow)
{

}