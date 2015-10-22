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
	cow->DoesNotMove_On();
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 25 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 25 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 25))
	{
		if (cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForPill"
			)
		{
			cow->SetScore((cow->GetScore() + 1));
			cow->SetPos(Vector2D(200, rand() % 800));
		}

		if (cow->GetFSM()->PreviousState()->GetStateName() == "Wandering" ||
			cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForWeapon")
		{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());

				cow->SetPos(Vector2D(200, rand() % 800));
		}
		cow->GetEnemy()->Respawn();
	}


	

}

void CowHidingState::Exit(Cow* cow)
{
	cow->DoesNotMove_Off();
	cow->SetMaxSpeed(50.0);
	cow->SetVelocity(Vector2D(200, 100));

}