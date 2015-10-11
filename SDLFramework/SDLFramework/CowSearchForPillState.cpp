#include "CowSearchForPillState.h"


CowSearchForPillState::CowSearchForPillState()
{
}


CowSearchForPillState::~CowSearchForPillState()
{
}

void CowSearchForPillState::Enter(Cow* cow)
{
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetPill()));
}

void CowSearchForPillState::Execute(Cow* cow)
{
	float distanceBetweenPillAndCow = cow->DistanceTo(cow->GetPill());
	if (distanceBetweenPillAndCow <= 50)
		cow->GetPill()->SetOffset(rand() % 800, rand() % 600);
}

void CowSearchForPillState::Exit(Cow* cow)
{

}

void CowSearchForPillState::Start(Cow* cow)
{

}