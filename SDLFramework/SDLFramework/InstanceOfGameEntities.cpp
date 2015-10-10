#include "InstanceOfGameEntities.h"
#include "Parameters.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"

using namespace std;

InstanceOfGameEntities::InstanceOfGameEntities()
{
	Vector2D spawnPosition1 = Vector2D(200, rand() % 600);
	Vector2D spawnPosition2 = Vector2D(600, rand() % 600);
	weapon = new Weapon(rand() % 800, rand() % 600);
	pill = new Pill(rand() % 800, rand() % 600);
	cow =  new Cow(1,
		spawnPosition1,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale, rabbit);		//scale

	rabbit = new Rabbit(2,
		spawnPosition2,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(400, 200),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *			
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed*2,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale,				//scale
		*cow);				




	cow->SetEnemy(rabbit);
	rabbit->GetFSM()->ChangeState(RabbitPursuitState::Instance());
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