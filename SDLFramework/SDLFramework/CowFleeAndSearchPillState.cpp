#include "CowFleeAndSearchPillState.h"
#include "CowHidingState.h"
#include "Rabbit.h"
#include "CowFleeingState.h"
CowFleeAndSearchPillState::CowFleeAndSearchPillState()
{
}


CowFleeAndSearchPillState::~CowFleeAndSearchPillState()
{
}

void CowFleeAndSearchPillState::Enter(Cow* cow)
{
	//cow->SetMaxSpeed(200.0);
	cow->SetMaxSpeed(1000.0);
	cow->Steering()->PursuitOn(reinterpret_cast<Vehicle*>(cow->GetPill()));
}

void CowFleeAndSearchPillState::Execute(Cow* cow)
{
	if ((cow->Pos().x > cow->GetEnemy()->Pos().x - 300 &&
		cow->Pos().x < cow->GetEnemy()->Pos().x + 300) &&
		(cow->Pos().y > cow->GetEnemy()->Pos().y - 300 &&
		cow->Pos().y < cow->GetEnemy()->Pos().y + 300))
	{
		cow->GetFSM()->ChangeState(CowFleeingState::Instance());
	}


	if ((cow->Pos().x > cow->GetPill()->Pos().x - 50 &&
		cow->Pos().x < cow->GetPill()->Pos().x + 50) &&
		(cow->Pos().y > cow->GetPill()->Pos().y - 50 &&
		cow->Pos().y < cow->GetPill()->Pos().y + 50))
	{
		cow->GetPill()->Respawn();
		cow->GetFSM()->ChangeState(CowHidingState::Instance());
	}
}

void CowFleeAndSearchPillState::Exit(Cow* cow)
{
	cow->SetMaxSpeed(50.0);
}

void CowFleeAndSearchPillState::Start(Cow* cow)
{

}