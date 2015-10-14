#include "CowFleeAndSearchWeaponState.h"
#include "CowHidingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"

CowFleeAndSearchWeaponState::CowFleeAndSearchWeaponState()
{
}


CowFleeAndSearchWeaponState::~CowFleeAndSearchWeaponState()
{
}


void CowFleeAndSearchWeaponState::Enter(Cow* cow)
{
	//cow->SetMaxSpeed(200.0);
	//cow->Steering()->FleeOn();
	cow->Steering()->EvadeOn(cow->GetEnemy());
	cow->SetMaxSpeed(500.0);
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetWeapon()));
}
void CowFleeAndSearchWeaponState::Execute(Cow* cow)
{
	//if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 300 &&
	//	cow->Pos().x < cow->GetEnemy()->Pos().x + 300) &&
	//	(cow->Pos().y > cow->GetEnemy()->Pos().y - 300 &&
	//	cow->Pos().y < cow->GetEnemy()->Pos().y + 300))
	//{
	//	cow->GetFSM()->ChangeState(CowFleeingState::Instance());
	//}
	
	if ((cow->Pos().x > cow->GetWeapon()->Pos().x - 25 &&
		cow->Pos().x < cow->GetWeapon()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetWeapon()->Pos().y - 25 &&
		cow->Pos().y < cow->GetWeapon()->Pos().y + 25))
	{
		cow->GetWeapon()->Respawn();
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
}

void CowFleeAndSearchWeaponState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	//cow->Steering()->FleeOff();
}

void CowFleeAndSearchWeaponState::Start(Cow* cow)
{

}
