#include "CowHidingState.h"
#include "Rabbit.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowHidingState::CowHidingState()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowHidingState::~CowHidingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Make sure the cow does not move while being in a Hiding state
/// 			1) If the cow was searching for a pill and just grabbed it, the cow will be respawned
/// 			at a different location. 
/// 			2) If the cow was Wandering or just caught a Weapon, then
/// 			the cow will be respawned at a different location and it wil go to a Wandering State
/// 			  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowHidingState::Enter(Cow* cow)
{
	cow->SetVelocity(Vector2D(0, 0));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowHidingState::Execute(Cow* cow)
{

	cow->SetVelocity(Vector2D(0, 0));
	cow->DoesNotMove_On();
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 25 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 25 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 25))
	{
		if (cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForPill")
		{
			cow->SetScore((cow->GetScore() + 1));
			cow->SetPos(Vector2D(200, 200 + rand() % 200));
			
		}

		if (cow->GetFSM()->PreviousState()->GetStateName() == "Wandering" ||
			cow->GetFSM()->PreviousState()->GetStateName() == "FleeAndSearchForWeapon")
		{
			cow->GetFSM()->ChangeState(CowWanderingState::Instance());

			cow->SetPos(Vector2D(200, 200 + rand() % 200));
		}
		cow->GetEnemy()->Respawn();
	}


	

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state. 
/// 			1) The cow move again.  
/// 			2) Set the maximum speed of the cow to 50.0  
/// 			3) Set the velocity of the cow to a vector of x=200 and y=100
/// 			</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowHidingState::Exit(Cow* cow)
{
	cow->DoesNotMove_Off();
	cow->SetMaxSpeed(50.0);
	cow->SetVelocity(Vector2D(200, 100));

}