#include "CowFleeAndSearchWeaponState.h"
#include "CowHidingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeAndSearchWeaponState::CowFleeAndSearchWeaponState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeAndSearchWeaponState::~CowFleeAndSearchWeaponState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action when entering the state </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchWeaponState::Enter(Cow* cow)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The cow tries to pick a weapon by going after it.
/// 			At the same time, the cow checks whether it is under threat by determining how close
/// 			the rabbit to the cow. If the rabbit is closer that 300 pixels from the cow, the cow
/// 			tries to evade (flee) from the rabbit. Only when the cow has reached a safe place
/// 			(Any location farther than 300 pixels from the rabbit) will it go after a weapon again.
/// 			If the cow catches a weapon it goes into a Hiding state.
/// 			 </summary>
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchWeaponState::Execute(Cow* cow)
{
	float distanceDistanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceDistanceBetweenCowAndRabbit < 300)
	{
		cow->SetMaxSpeed(38000.0);
		cow->Steering()->EvadeOn(cow->GetEnemy());
		cow->Steering()->PursuitOff();
	}
	else{
		cow->SetMaxSpeed(400);
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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchWeaponState::Exit(Cow* cow)
{
	cow->Steering()->PursuitOff();
}