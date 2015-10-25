#include "RabbitPursuitState.h"
#include "Dashboard.h"
#include "CowWanderingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitPursuitState::RabbitPursuitState()
{
	hasStarted = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitPursuitState::~RabbitPursuitState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state
///
/// 			The Start() function is called.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitPursuitState::Enter(Rabbit* rabbit)
{
	Start(rabbit);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The rabbit will pursuit the cow.
/// 			If the rabbit catches the cow while the cow's in a Fleeing State, a FleeAndSearchForWeapon State,
/// 			a FleeAndSearchForPill state:
/// 			1) The rabbit gets a 10 points.
/// 			2) Both the cow and the rabbit gets respawned at a random location on the Arena
/// 			3) The cow goes back to a Wandering state
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitPursuitState::Execute(Rabbit* rabbit)
{
	if (hasStarted == false) {
		Start(rabbit);
		hasStarted = true;
	}

	float distanceBetweenRabbitAndCow = rabbit->DistanceBetween(&rabbit->GetEnemy());
	if (distanceBetweenRabbitAndCow <= 30)
	{
		if ((&rabbit->GetEnemy())->GetCurrentState() == "Fleeing" ||
			(&rabbit->GetEnemy())->GetCurrentState() == "FleeAndSearchForWeapon" ||
			(&rabbit->GetEnemy())->GetCurrentState() == "FleeAndSearchForPill")
		{
			rabbit->SetScore((rabbit->GetScore() + 10));
			rabbit->Respawn();
			(&rabbit->GetEnemy())->Respawn();
			(&rabbit->GetEnemy())->GetFSM()->ChangeState(CowWanderingState::Instance());
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state.
/// 			Set 'hasStarted' flag to false.
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitPursuitState::Exit(Rabbit* rabbit)
{
	hasStarted = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The rabbit starts to pursue the cow </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitPursuitState::Start(Rabbit* rabbit)
{
	rabbit->Steering()->PursuitOn(&rabbit->GetEnemy());
}