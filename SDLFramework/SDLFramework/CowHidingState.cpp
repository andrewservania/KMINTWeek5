#include "CowHidingState.h"
#include "Rabbit.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"
CowHidingState::CowHidingState()
{
}


CowHidingState::~CowHidingState()
{
}


void CowHidingState::Enter(Cow* cow)
{

	cow->DoesNotMove_On();
}

void CowHidingState::Execute(Cow* cow)
{

	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit < 50)
	{
		cow->SetScore((cow->GetScore() + 1));
		Dashboard::Instance()->SetCowScore(cow->GetScore());
		cow->GetEnemy()->Respawn();
		cow->Respawn();
		cow->GetEnemy()->GetFSM()->ChangeState(RabbitPursuitState::Instance());
	}

//	cow->SetVelocity(Vector2D(0, 0));
}

void CowHidingState::Exit(Cow* cow)
{

}