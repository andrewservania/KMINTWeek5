#include "CowFleeAndSearchPillState.h"
#include "CowHidingState.h"
#include "Rabbit.h"
#include "CowFleeingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeAndSearchPillState::CowFleeAndSearchPillState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CowFleeAndSearchPillState::~CowFleeAndSearchPillState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Execute required actions right after entering this state </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchPillState::Enter(Cow* cow)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The cow tries to pick a pill by going after it.
/// 			At the same time, the cow checks whether it is under threat by determining how close 
/// 			the rabbit to the cow. If the rabbit is closer that 300 pixels from the cow, the cow
/// 			tries to evade (flee) from the rabbit. Only when the cow has reached a safe place
/// 			(Any location farther than 300 pixels from the rabbit) will it go after a pill again.
/// 			If the cow catches a pill it goes into a Hiding state.
/// 			 </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchPillState::Execute(Cow* cow)
{

	float distanceDistanceBetweenCowAndRabbit = cow->DistanceBetween(cow->GetEnemy());
	if (distanceDistanceBetweenCowAndRabbit < 300)
	{
		cow->SetMaxSpeed(38000.0);
		cow->Steering()->EvadeOn(cow->GetEnemy());
		cow->Steering()->PursuitOff();
	}
	else{
		cow->SetMaxSpeed(400.0);
		cow->Steering()->PursuitOn(cow->GetPill());
	}
	 if ((cow->Pos().x > cow->GetPill()->Pos().x - 25 &&
		cow->Pos().x < cow->GetPill()->Pos().x + 25) &&
		(cow->Pos().y > cow->GetPill()->Pos().y - 25 &&
		cow->Pos().y < cow->GetPill()->Pos().y + 25))
	{
		cow->GetPill()->Respawn();
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state 
/// 			The cow's speed will be set to a default 50.0
/// 			The cow will stop pursuing the pill.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="cow">	[in,out] If non-null, the cow. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CowFleeAndSearchPillState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	cow->Steering()->PursuitOff();
	
}
