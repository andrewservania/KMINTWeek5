#include "Arena.h"
#include "Parameters.h"
#include "Dashboard.h"


using namespace std;



Arena::Arena()
{
	seconds = 0;
	auto instance1 = make_shared<InstanceOfGameEntities>();
	auto instance2 = make_shared<InstanceOfGameEntities>();
	auto instance3 = make_shared<InstanceOfGameEntities>();
	auto instance4 = make_shared<InstanceOfGameEntities>();

	instance1->SetColor(new Color(0, 0,255, 255));
	instance2->SetColor(new Color(0, 255, 0, 255));
	instance3->SetColor(new Color(255, 0, 0, 255));
	instance4->SetColor(new Color(255, 0,255, 255));
	


}



Arena::~Arena()
{

}


void Arena::ResetInstances()
{
	
}

void Arena::SecondTick()
{
	if (seconds == 30)
	{
		seconds = 0;
		ResetInstances();
	}
	else
	{
		seconds++;
	}
	Dashboard::Instance()->SetTimePassed(seconds);
}