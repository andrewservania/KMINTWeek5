#include "CowPursuitState.h"
#include "Arena.h"

CowPursuitState::CowPursuitState()
{

}


CowPursuitState::~CowPursuitState()
{

}

void CowPursuitState::Enter(Cow* cow)
{
	Start(cow);
}

// Execute the code corresponding to the Pursuit state for the cow
void CowPursuitState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);
		hasStarted = true;
	}
}

void CowPursuitState::Exit(Cow* cow)
{
	hasStarted = false;
}

void CowPursuitState::Start(Cow* cow)
{
	//cow->Steering()->PursuitOn(Arena::Instance()->rabbit);
}