#include "Arena.h"
#include "Parameters.h"




//Cow* Arena::cow;
//Rabbit* Arena::rabbit;

Arena::Arena()
{
	instanceOfGameEntities = new InstanceOfGameEntities();

	

	//Vector2D spawnPosition1 = Vector2D(rand() % 1300,rand() % 700);
	//Vector2D spawnPosition2 = Vector2D(rand() % 1300,rand() % 700);


	//cow = new Cow(1,
	//	spawnPosition1,										//initial position
	//	RandFloat()*TwoPi,									//start rotation
	//	Vector2D(200, 100),									//velocity
	//	Parameters::Instance()->VehicleMass,				//mass
	//	Parameters::Instance()->SteeringForce * 
	//	Parameters::Instance()->SteeringForceTweaker,		//max force
	//	Parameters::Instance()->MaxSpeed,					//max velocity
	//	Parameters::Instance()->MaxTurnRate,				//max turn rate
	//	Parameters::Instance()->VehicleScale);				//scale
	//
	//rabbit = new Rabbit(2,
	//	spawnPosition2,										//initial position
	//	RandFloat()*TwoPi,									//start rotation
	//	Vector2D(200,100),									//velocity
	//	Parameters::Instance()->VehicleMass,				//mass
	//	(Parameters::Instance()->SteeringForce *
	//	Parameters::Instance()->SteeringForceTweaker),	//max force
	//	Parameters::Instance()->MaxSpeed,				//max velocity
	//	Parameters::Instance()->MaxTurnRate,				//max turn rate
	//	Parameters::Instance()->VehicleScale);				//scale

	//predator->Steering()->PursuitOn(prey);
//	cow->SetScale(Vector2D(30, 30));
//	rabbit->SetScale(Vector2D(30, 30));

	//predator->Steering()->CreateRandomPath(3, 100, 200, 300, 400);
	//predator->Steering()->FollowPathOn();
	//cow->Steering()->PursuitOn(prey);
	
	//prey->Steering()->FleeOn();
	//prey->Steering()->WanderOn();
	
	
	//prey->SetScale(Vector2D(10, 10));
	//prey->Steering()->EvadeOn(cow);
	//prey->SetMaxSpeed(70);
	//prey->Steering()->ArriveOn();

}


Arena::~Arena()
{

}
