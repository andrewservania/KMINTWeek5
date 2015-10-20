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
	cowCurrentXpos = cow->Pos().x;
	cowCurrentYpos = cow->Pos().y;

}

void CowHidingState::Execute(Cow* cow)
{

	cow->SetVelocity(Vector2D(0, 0));
	cow->SetPos(Vector2D(cowCurrentXpos, cowCurrentYpos));
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
			cowCurrentXpos = 200;
			cowCurrentYpos = rand() % 800;
			cow->SetPos(Vector2D(cowCurrentXpos, cowCurrentYpos));
		}

		if (cow->GetFSM()->PreviousState()->GetStateName() == "Wandering")
		{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());
			cowCurrentXpos = 200;
			cowCurrentYpos = rand() % 800;
			cow->SetPos(Vector2D(cowCurrentXpos, cowCurrentYpos));
		}
		cow->GetEnemy()->Respawn();
	}


	

}

void CowHidingState::Exit(Cow* cow)
{
	cow->SetVelocity(Vector2D(200, 100));
}