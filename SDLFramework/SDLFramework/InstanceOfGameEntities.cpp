#include "InstanceOfGameEntities.h"
#include "Parameters.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"
#include "CowGlobalState.h"
#include "RabbitGlobalState.h"

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// 1) Create a cow, a rabbit, a weapon and a pill.
/// 2) Put them on a random location on the arena.
/// 3) Point the cow to the rabbit and vice versa in order for them to find/evade/flee eachother during
/// the application
/// 4) Point the cow to the pill and the weapon in order for to be able to determine their location and
/// consume them.
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

InstanceOfGameEntities::InstanceOfGameEntities()
{
	weapon = new Weapon(200 + rand() % 800, rand() % 700);
	pill = new Pill(200 + rand() % 800, rand() % 700);

	cow = new Cow(3,
		Vector2D(200, 200 + rand() % 200),					//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale, rabbit);		//scale

	rabbit = new Rabbit(4,
		Vector2D(600, 200 + rand() % 200),					//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed * 2,				//max velocity (double the speed of the cow)
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale,				//scale
		*cow);

	rabbit->GetFSM()->ChangeState(RabbitPursuitState::Instance());

	cow->SetEnemy(rabbit);
	cow->SetWeapon(weapon);
	cow->SetPill(pill);
	cow->GetFSM()->ChangeState(CowWanderingState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

InstanceOfGameEntities::~InstanceOfGameEntities()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a color. </summary>
///
///   Set the color for the cow, the rabbit, the weapon and the pill.
///   Used in order to assign a color all game entities of a given instance.
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="_color">	[in,out] If non-null, the color. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void InstanceOfGameEntities::SetColor(Color* _color)
{
	rabbit->SetColor(_color);
	cow->SetColor(_color);
	weapon->SetColor(_color);
	pill->SetColor(_color);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets this instance. </summary>
///
/// Reset the cow, the rabbit, the pill and the weapon and print the probabilities of the cow's
/// choices.
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void InstanceOfGameEntities::Reset()
{
	cow->Reset();
	rabbit->Reset();
	weapon->Respawn();
	pill->Respawn();
	PrintProbabilities();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Ends the behavior of the cow </summary>
///
/// Set the rabbit and the cow to a Global State. The will not mobilize and do anything else
/// while being in this state.
/// Respawn the cow and the rabbit at a random location on the arena.
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void InstanceOfGameEntities::End()
{
	rabbit->GetFSM()->ChangeState(RabbitGlobalState::Instance());
	rabbit->SetPos(Vector2D(200 + rand() % 600, rand() % 800));
	cow->GetFSM()->ChangeState(CowGlobalState::Instance());
	cow->SetPos(Vector2D(200 + rand() % 600, rand() % 800));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print probabilities of the cow in the console window. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void InstanceOfGameEntities::PrintProbabilities()
{
	cout << "Flee: " + to_string(cow->GetProbabilityDistribution()->GetChoice1Probability()) + "%  " +
		"FleeAndSearchWeapon: " + to_string(cow->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		"FleeAndSearchPill: " + to_string(cow->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		"Hide: " + to_string(cow->GetProbabilityDistribution()->GetChoice4Probability()) + "% \n";	// Cow 1 probability
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the score, color and probability distribution of the cow in an instance. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <returns>	The score. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

InstanceScore InstanceOfGameEntities::GetScore()
{
	instanceScore.cowScore = cow->GetScore();
	instanceScore.rabbitScore = rabbit->GetScore();
	instanceScore.probabilityDistribution = cow->GetProbabilityDistribution();
	instanceScore.instanceColor = cow->GetInstanceColor();
	return instanceScore;
}