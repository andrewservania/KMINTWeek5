#include "RabbitWanderingState.h"
#include "Arena.h"
#include "RabbitSearchForWeaponState.h"
#include "ProbabilityDistribution.h"
#include "RabbitSearchForPillState.h"
#include "RabbitFleeingState.h"
#include "CowSleepingState.h"

RabbitWanderingState::RabbitWanderingState()
{
	//Arena::Instance()->rabbit->Steering()->WanderOn();

//	Arena::Instance()->rabbit->Steering()->CreateRandomPath(3, 250, 250, 350, 350);
//	Arena::Instance()->rabbit->Steering()->FollowPathOn();
}

RabbitWanderingState::~RabbitWanderingState()
{
}

void RabbitWanderingState::Enter(Rabbit* rabbit)
{
	rabbit->Steering()->ArriveOn();
	rabbit->SetMaxSpeed(150);
	Start(rabbit);

}

// Execute the code corresponding to the Wandering state for the rabbit
void RabbitWanderingState::Execute(Rabbit* rabbit)
{
	if (hasStarted = false)
	{
		Start(rabbit);
		hasStarted = true;
	}
	if (IsThreatEminent(rabbit))
		rabbit->GetFSM()->ChangeState(RabbitFleeingState::Instance());
	
}

void RabbitWanderingState::Exit(Rabbit* rabbit)
{
}

void RabbitWanderingState::Start(Rabbit* rabbit)
{
	Arena::Instance()->rabbit->Steering()->CreateRandomPath(3, 250, 250, 350, 350);
	Arena::Instance()->rabbit->Steering()->FollowPathOn();
}

bool RabbitWanderingState::IsThreatEminent(Rabbit* rabbit)
{
	float distanceBetweenCowAndRabbit = rabbit->DistanceTo(Arena::Instance()->cow);
	if (distanceBetweenCowAndRabbit <= 200)
		return true; 
	else 
		return false;
}

