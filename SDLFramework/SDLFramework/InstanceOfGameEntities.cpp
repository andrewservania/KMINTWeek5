#include "InstanceOfGameEntities.h"
#include "Parameters.h"
#include "RabbitPursuitState.h"
#include "CowWanderingState.h"
#include "CowGlobalState.h"
#include "RabbitGlobalState.h"

using namespace std;

InstanceOfGameEntities::InstanceOfGameEntities()
{

	weapon = new Weapon(rand() % 800, rand() % 600);
	pill = new Pill(rand() % 800, rand() % 600);

	cow =  new Cow(3,
		Vector2D(200, rand() % 600),						//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale, rabbit);		//scale

	rabbit = new Rabbit(4,
		Vector2D(600, rand() % 600),						//initial position
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

	//weapon = new Weapon(rand() % 800, rand() % 600);
	//pill = new Pill(rand() % 800, rand() % 600);
	//weapon->Respawn();
	//pill->Respawn();

	//cow->SetWeapon(weapon);
	//cow->SetPill(pill);
}

void InstanceOfGameEntities::End()
{
	rabbit->GetFSM()->ChangeState(RabbitGlobalState::Instance());
	cow->GetFSM()->ChangeState(CowGlobalState::Instance());

}