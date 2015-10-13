#include "Arena.h"
#include "Parameters.h"
#include "Dashboard.h"


using namespace std;



Arena::Arena()
{
	seconds = 0;
	runs = 0;
	applicationEnd = false;
	 instance1 = make_shared<InstanceOfGameEntities>();
	 instance2 = make_shared<InstanceOfGameEntities>();
	 instance3 = make_shared<InstanceOfGameEntities>();
	 instance4 = make_shared<InstanceOfGameEntities>();

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
	instance1->Reset();
	instance2->Reset();
	instance3->Reset();
	instance4->Reset();
}

void Arena::SecondTick()
{
	if (!applicationEnd)
	{
		if (seconds == 30)
		{
			seconds = 0;
			runs++;
			Dashboard::Instance()->SetAmountOfRuns(runs);
			if (runs == 5)
			{
				EndProgram();
				applicationEnd = true;
			}
			else	
			{
				ResetInstances();
			}
		}
		else
		{
			seconds++;
		}
		Dashboard::Instance()->SetTimePassed(seconds);
	}
}

void Arena::EndProgram()
{
	instance1->End();
	instance2->End();
	instance3->End();
	instance4->End();
}