#include "InstanceOfGameEntities.h"
#include "Parameters.h"

using namespace std;

InstanceOfGameEntities::InstanceOfGameEntities()
{
	Vector2D spawnPosition1 = Vector2D(rand() % 1300, rand() % 700);
	Vector2D spawnPosition2 = Vector2D(rand() % 1300, rand() % 700);

	cow =  new Cow(1,
		spawnPosition1,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed*3,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale

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


		weapon = new Weapon(200,200);
		pill = new Pill(300,300);



}


InstanceOfGameEntities::~InstanceOfGameEntities()
{
}
