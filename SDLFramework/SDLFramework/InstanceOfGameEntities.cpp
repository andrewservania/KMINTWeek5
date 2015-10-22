#include "InstanceOfGameEntities.h"
#include "Parameters.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"
#include "CowGlobalState.h"
#include "RabbitGlobalState.h"

#include <iostream>

using namespace std;

InstanceOfGameEntities::InstanceOfGameEntities()
{

	weapon = new Weapon(200 + rand() % 600, rand() % 800);
	pill = new Pill(200 + rand() % 600, rand() % 800);

	cow =  new Cow(3,
		Vector2D(200, rand() % 800),						//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale, rabbit);		//scale

	rabbit = new Rabbit(4,
		Vector2D(600, rand() % 800),						//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *			
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed *2,				//max velocity (double the speed of the cow)
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale,				//scale
		*cow);				


	rabbit->GetFSM()->ChangeState(RabbitPursuitState::Instance());

	cow->SetEnemy(rabbit);
	cow->SetWeapon(weapon);
	cow->SetPill(pill);
	cow->GetFSM()->ChangeState(CowWanderingState::Instance());

}


InstanceOfGameEntities::~InstanceOfGameEntities()
{
}

void InstanceOfGameEntities::SetColor(Color* _color)
{
	rabbit->SetColor(_color);
	cow->SetColor(_color);
	weapon->SetColor(_color);
	pill->SetColor(_color);
}

void InstanceOfGameEntities::Reset()
{

	cow->Reset();
	rabbit->Reset();
	weapon->Respawn();
	pill->Respawn();
	PrintProbabilities();

}

void InstanceOfGameEntities::End()
{
	rabbit->GetFSM()->ChangeState(RabbitGlobalState::Instance());
	rabbit->SetPos(Vector2D(200 + rand() % 600, rand() % 800));
	cow->GetFSM()->ChangeState(CowGlobalState::Instance());
	cow->SetPos(Vector2D(200 + rand() % 600, rand() % 800));

}

void InstanceOfGameEntities::PrintProbabilities()
{
	cout <<		"Flee: " + to_string(cow->GetProbabilityDistribution()->GetChoice1Probability()) + "%  " +
		"FleeAndSearchWeapon: " + to_string(cow->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		"FleeAndSearchPill: " + to_string(cow->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		"Hide: " + to_string(cow->GetProbabilityDistribution()->GetChoice4Probability()) + "% \n";	// Cow 1 probability
	
}

InstanceScore InstanceOfGameEntities::GetScore()
{
	instanceScore.cowScore = cow->GetScore();
	instanceScore.rabbitScore = rabbit->GetScore();
	instanceScore.probabilityDistribution = cow->GetProbabilityDistribution();
	instanceScore.instanceColor = cow->GetInstanceColor();
	return instanceScore;
}

