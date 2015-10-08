#include "RabbitPursuitState.h"


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
}

void RabbitPursuitState::Exit(Rabbit* rabbit)
{
	hasStarted = false;
}

void RabbitPursuitState::Start(Rabbit* rabbit)
{
	rabbit->Steering()->PursuitOn((&rabbit->GetEnemy()));
}

