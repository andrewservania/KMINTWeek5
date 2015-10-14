#include "CowHidingState.h"
#include "Rabbit.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"
CowHidingState::CowHidingState()
{
	cowCurrentXpos = 0.0;
	cowCurrentYpos = 0.0;
}


CowHidingState::~CowHidingState()
{
}


void CowHidingState::Enter(Cow* cow)
{
	cowCurrentXpos = cow->Pos().x;
	cowCurrentYpos = cow->Pos().y;
	cow->SetVelocity(Vector2D(0, 0));
	
}

void CowHidingState::Execute(Cow* cow)
{

	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit < 50)
	{
		if (cow->GetFSM()->PreviousState()->GetStateName() == "Search For Weapon")
		{
			cow->SetScore((cow->GetScore() + 1));
			Dashboard::Instance()->SetCowScore(cow->GetScore());
		}

		cow->GetEnemy()->Respawn();
		cowCurrentXpos = 200; 
		cowCurrentYpos = rand() % 600;
		cow->SetPos(Vector2D(cowCurrentXpos,cowCurrentYpos));
	}
	cow->SetPos(Vector2D(cowCurrentXpos,cowCurrentYpos));
	cow->SetVelocity(Vector2D(0, 0));
	cow->Steering()->ArriveOn();
}

void CowHidingState::Exit(Cow* cow)
{

}