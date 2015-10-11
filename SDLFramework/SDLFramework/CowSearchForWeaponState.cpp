#include "CowSearchForWeaponState.h"


CowSearchForWeaponState::CowSearchForWeaponState()
{
}


CowSearchForWeaponState::~CowSearchForWeaponState()
{
}


void CowSearchForWeaponState::Enter(Cow* cow)
{
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetWeapon()));
}
void CowSearchForWeaponState::Execute(Cow* cow)
{
	float distanceBetweenWeaponAndCow = cow->DistanceTo(cow->GetWeapon());
	if (distanceBetweenWeaponAndCow <= 50)
		cow->GetWeapon()->SetOffset(rand() % 800, rand() % 600);
}

void CowSearchForWeaponState::Exit(Cow* cow)
{

}

void CowSearchForWeaponState::Start(Cow* cow)
{

}
