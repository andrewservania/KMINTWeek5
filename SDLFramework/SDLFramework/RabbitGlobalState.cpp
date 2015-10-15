#include "RabbitGlobalState.h"


RabbitGlobalState::RabbitGlobalState()
{
}


RabbitGlobalState::~RabbitGlobalState()
{
}


void RabbitGlobalState::Enter(Rabbit* rabbit)
{
}


void RabbitGlobalState::Execute(Rabbit* rabbit)
{
	rabbit->SetPos(Vector2D(600, 600));
	rabbit->SetVelocity(Vector2D(0, 0));
}


void RabbitGlobalState::Exit(Rabbit* rabbit)
{
}



