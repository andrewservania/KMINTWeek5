#include "CowWanderingState.h"
#include "CowFleeingState.h"
#include "Rabbit.h"
#include "CowFleeAndSearchPillState.h"
#include "CowFleeAndSearchWeaponState.h"
#include "CowHidingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowWanderingState::CowWanderingState()
{
	hasStarted = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowWanderingState::~CowWanderingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before entering the wandering state
/// 			Call the Start() method on the cow.
/// 			The cow gets a specific velocity vector and starts wandering around.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowWanderingState::Enter(Cow* cow)
{
	Start(cow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	If the cow is under threat, it choose one of its 4 choices
///
/// 			The speed of the cow is 'slowly' normalized to the default 50.0 after being coming
/// 			from the Fleeing state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowWanderingState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);
		hasStarted = true;
	}

	// Slowly normalize the speed of the cow after coming back from the Fleeing state
	if (cow->MaxSpeed() > 50.0){
		cow->SetMaxSpeed(cow->MaxSpeed() - 50.0);
	}
	if (cow->MaxSpeed() < 50.0)
	{
		cow->SetMaxSpeed(50.0);
	}

	if (IsThreatEminent(cow)){
		// Choose next action
		switch (cow->GetProbabilityDistribution()->GenerateRandomChoice())
		{
		case 1:
			cow->GetFSM()->ChangeState(CowFleeingState::Instance());

			break;
		case 2:
			cow->GetFSM()->ChangeState(CowFleeAndSearchWeaponState::Instance());

			break;
		case 3:
			cow->GetFSM()->ChangeState(CowFleeAndSearchPillState::Instance());

			break;
		case 4:
			cow->GetFSM()->ChangeState(CowHidingState::Instance());

			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state.
/// 			The cow will stop wandering around
/// 			hasStarted flag is set to false </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowWanderingState::Exit(Cow* cow)
{
	hasStarted = false;
	cow->Steering()->WanderOff();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state.
/// 			1) The cow will start wandering around the arena.
/// 			2) The cow's velocity will be set to a vector of x=200 and y=200
/// 			</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowWanderingState::Start(Cow* cow)
{
	cow->Steering()->WanderOn();
	cow->SetVelocity(Vector2D(200, 100));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Check if the rabbit is within 300 pixels from the cow. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
///
/// <returns>	true if thread eminent, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool CowWanderingState::IsThreatEminent(Cow* cow)
{
	float distanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceBetweenCowAndRabbit <= 300)
	{
		return true;
	}
	return false;
}