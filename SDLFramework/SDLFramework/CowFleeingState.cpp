#include "CowFleeingState.h"
#include "CowWanderingState.h"
#include "Rabbit.h"
#include "CowFleeAndSearchPillState.h"
#include "CowFleeAndSearchWeaponState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeingState::CowFleeingState()
{
	hasStarted = false;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeingState::~CowFleeingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Enters the given cow. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeingState::Enter(Cow* cow)
{
	Start(cow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Keep checking whether the cow is under threat by the rabbit.
/// 			As long as the rabbit is under threat, the cow keeps on evading the rabbit.
/// 			Otherwise it goes back into a Wandering state.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeingState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);

		hasStarted = true;
	}
	if (NoThreat(cow)){
		cow->GetFSM()->ChangeState(CowWanderingState::Instance());
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeingState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(2000.0);
	cow->Steering()->EvadeOff();
	hasStarted = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Increase the speed of the cow and start evading the enemy.
/// 			/summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeingState::Start(Cow* cow)
{
	cow->Steering()->EvadeOn(cow->GetEnemy());
	cow->SetMaxSpeed(27000.0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Check if the cow is still under threat by determining whether the rabbit is within
/// 			300 pixels from the cow. If it isn't return true, otherwise return false.
/// 			 </summary>
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
///
/// <returns>	true if it No threat, otherwise false. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool CowFleeingState::NoThreat(Cow* cow)
{
	float distanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit > 300)
	{
		return true; 
	}	
	return false;
}