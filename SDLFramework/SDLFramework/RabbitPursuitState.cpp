#include "RabbitPursuitState.h"
#include "Dashboard.h"

RabbitPursuitState::RabbitPursuitState()
{
	hasStarted = false;
}


RabbitPursuitState::~RabbitPursuitState()
{

}


void RabbitPursuitState::Enter(Rabbit* rabbit)
{
	Start(rabbit);
}

void RabbitPursuitState::Execute(Rabbit* rabbit)
{
	if (hasStarted == false) {
		Start(rabbit);
		hasStarted = true;
	}

	float distanceBetweenRabbitAndCow = rabbit->DistanceTo(&rabbit->GetEnemy());
	if (distanceBetweenRabbitAndCow <= 20)
	{
	
		rabbit->SetScore((rabbit->GetScore() + 10));
		Dashboard::Instance()->SetRabbitScore(rabbit->GetScore());
		rabbit->Respawn();
		(&rabbit->GetEnemy())->Respawn();
	}
}

void RabbitPursuitState::Exit(Rabbit* rabbit)
{
	hasStarted = false;
}

void RabbitPursuitState::Start(Rabbit* rabbit)
{
	rabbit->Steering()->PursuitOn(&rabbit->GetEnemy());
}

