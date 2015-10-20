#include "CowHidingState.h"
#include "Rabbit.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"

CowHidingState::CowHidingState()
{

}


CowHidingState::~CowHidingState()
{
}


void CowHidingState::Enter(Cow* cow)
{
	cow->SetVelocity(Vector2D(0, 0));
	
}

void CowHidingState::Execute(Cow* cow)
{

	cow->SetVelocity(Vector2D(0, 0));

	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 25 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 25 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 25))
	{
		if (cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForWeapon" ||
			cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForPill"
			)
		{
			cow->SetScore((cow->GetScore() + 1));
			Dashboard::Instance()->SetCowScore(cow->GetScore());
		}

		if (cow->GetFSM()->PreviousState()->GetStateName() == "Wandering")
		{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());
		}
		
		cow->GetEnemy()->Respawn();

			cow->SetPos(Vector2D(200, rand() % 600));
	}


	

}

void CowHidingState::Exit(Cow* cow)
{

}