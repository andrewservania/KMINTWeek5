#include "Arena.h"
#include "Parameters.h"
#include "Dashboard.h"


using namespace std;



Arena::Arena()
{
	instanceTimer = 0;
	instanceSeconds = 0;
	seconds = 0;
	mApplication->AddRenderable(this);
	auto instance1 = make_shared<InstanceOfGameEntities>();
	auto instance2 = make_shared<InstanceOfGameEntities>();
	auto instance3 = make_shared<InstanceOfGameEntities>();
	auto instance4 = make_shared<InstanceOfGameEntities>();

	instance1->SetColor(new Color(0, 0,255, 255));
	instance2->SetColor(new Color(0, 255, 0, 255));
	instance3->SetColor(new Color(255, 0, 0, 255));
	instance4->SetColor(new Color(255, 0,255, 255));
	//

	//delay = (33 / 10) * 10;  /* To round it down to the nearest 10 ms */

	//my_timer_id = SDL_AddTimer(delay, MyTimerCallBackFunc, nullptr);
}

//Uint32 Arena::MyTimerCallBackFunc(Uint32 interval, void *param)
//{
//
//}

Arena::~Arena()
{

}

void Arena::Update(float deltaTime)
{
	instanceTimer = mApplication->GetTimeSinceStartedMS();
	

	if (instanceTimer > 1000)
	{
		seconds = instanceTimer / 1000;
		Dashboard::Instance()->SetTimePassed(seconds);

		if ((instanceTimer % 1000) == 0) instanceSeconds++;

		if ((seconds % 30) == 0)
		{
			ResetInstances();
			instanceSeconds = 0;
		}
	}

	
}

void Arena::ResetInstances()
{
	
}