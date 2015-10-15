#include "CowGlobalState.h"


CowGlobalState::CowGlobalState()
{
}


CowGlobalState::~CowGlobalState()
{
}

void CowGlobalState::Enter(Cow* cow)
{

}

void CowGlobalState::Execute(Cow* cow)
{
	cow->SetPos(Vector2D(200, 600));
	cow->SetVelocity(Vector2D(0, 0));
}

void CowGlobalState::Exit(Cow* cow)
{

}