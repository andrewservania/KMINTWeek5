#include "CowFleeingState.h"
#include "CowWanderingState.h"
#include "Rabbit.h"


CowFleeingState::CowFleeingState()
{
	hasStarted = false;

}


CowFleeingState::~CowFleeingState()
{
}

void CowFleeingState::Enter(Cow* cow)
{
	Start(cow);
}

void CowFleeingState::Execute(Cow* cow)
{
	if (hasStarted == false)
	{
		Start(cow);

		hasStarted = true;
	}
	if (NoThreat(cow)) cow->GetFSM()->ChangeState(CowWanderingState::Instance());
}

void CowFleeingState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
	hasStarted = false;
}

void CowFleeingState::Start(Cow* cow)
{
	cow->Steering()->EvadeOn(reinterpret_cast<Vehicle*>(cow->GetEnemy()));
	cow->SetMaxSpeed(20000.0);
}

bool CowFleeingState::NoThreat(Cow* cow)
{
		if (cow->GetEnemy()->Pos().x >= (cow->Pos().x + 301) ||
			cow->GetEnemy()->Pos().x <= (cow->Pos().x - 301) ||
			cow->GetEnemy()->Pos().y >= (cow->Pos().y + 301) ||
			cow->GetEnemy()->Pos().y <= (cow->Pos().y - 301))
		{
			return true; 
		}	
		else return false;
	
		return false;
}