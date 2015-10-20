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

}
void CowFleeAndSearchWeaponState::Execute(Cow* cow)
{

	float distanceDistanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceDistanceBetweenCowAndRabbit < 300)
	{
		cow->SetMaxSpeed(25000.0);
		cow->Steering()->EvadeOn(cow->GetEnemy());
		cow->Steering()->PursuitOff();
	}
	else{
		cow->SetMaxSpeed(500.0);
		cow->Steering()->PursuitOn(cow->GetWeapon());
	}

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
	cow->Steering()->PursuitOff();
	//cow->SetMaxSpeed(50.0);
}

void CowFleeAndSearchWeaponState::Start(Cow* cow)
{

}
