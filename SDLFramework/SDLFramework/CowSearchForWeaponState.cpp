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
	//cow->SetMaxSpeed(200.0);
	cow->SetMaxSpeed(400.0);
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetWeapon()));
}
void CowSearchForWeaponState::Execute(Cow* cow)
{
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 300 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 300) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 300 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 300))
	{
		cow->GetFSM()->ChangeState(CowFleeingState::Instance());
	}
	float distanceBetweenPillAndCow = cow->DistanceTo(cow->GetWeapon());
	if (distanceBetweenPillAndCow <= 50)
	{
		cow->GetWeapon()->SetOffset(rand() % 800, rand() % 600);
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
}

void CowSearchForWeaponState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
}

void CowSearchForWeaponState::Start(Cow* cow)
{

}
