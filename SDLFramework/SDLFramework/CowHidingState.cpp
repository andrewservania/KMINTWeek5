#include "CowHidingState.h"
#include "Rabbit.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"

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
	cow->SetPos(Vector2D(cowCurrentXpos,cowCurrentYpos));
	cow->SetVelocity(Vector2D(0, 0));

	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 25 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 25 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 25))
	{
		if (cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForWeapon")
		{
			cow->SetScore((cow->GetScore() + 1));
			Dashboard::Instance()->SetCowScore(cow->GetScore());
		}

		if (cow->GetFSM()->PreviousState()->GetStateName() == "Wandering")
		{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());
		}

		cow->GetEnemy()->Respawn();
		cowCurrentXpos = 200; 
		cowCurrentYpos = rand() % 600;
		cow->SetPos(Vector2D(cowCurrentXpos,cowCurrentYpos));
	}


	

}

void CowHidingState::Exit(Cow* cow)
{

}