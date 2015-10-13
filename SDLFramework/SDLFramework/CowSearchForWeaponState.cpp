#include "CowSearchForWeaponState.h"
#include "CowHidingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"

CowSearchForWeaponState::CowSearchForWeaponState()
{
}


CowSearchForWeaponState::~CowSearchForWeaponState()
{
}


void CowSearchForWeaponState::Enter(Cow* cow)
{
	cow->SetMaxSpeed(200.0);
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetWeapon()));
}
void CowSearchForWeaponState::Execute(Cow* cow)
{
	float distanceBetweenPillAndCow = cow->DistanceTo(cow->GetWeapon());
	if (distanceBetweenPillAndCow <= 50)
	{
		cow->GetWeapon()->SetOffset(rand() % 800, rand() % 600);
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
	float distanceBetweenCowAndRabbit = cow->DistanceTo(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit < 100)
	{
		cow->GetFSM()->ChangeState(CowFleeingState::Instance());
	}
}

void CowSearchForWeaponState::Exit(Cow* cow)
{

}

void CowSearchForWeaponState::Start(Cow* cow)
{

}
