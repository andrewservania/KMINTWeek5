#include "Arena.h"
#include "Parameters.h"
#include "Dashboard.h"

#include <iostream>

using namespace std;


Arena::Arena()
{
	seconds = 0;
	runs = 0;
	applicationEnd = false;
	cout << "\nRun # " + to_string(runs);
	InitializeInstance1();
	InitializeInstance2();
	InitializeInstance3();
	InitializeInstance4();
}



Arena::~Arena()
{

}


void Arena::ResetInstances()
{
	cout << "\n\n Run # " + to_string(runs);
	cout << "\nInstance 1:\n";
	instance1->Reset();
	cout << "\nInstance 2:\n";
	instance2->Reset();
	cout << "\nInstance 3:\n";
	instance3->Reset();
	cout << "\nInstance 4:\n";
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

void Arena::InitializeInstance1()
{
	instance1 = make_shared<InstanceOfGameEntities>();
	instance1->SetColor(new Color(0, 0, 255, 255));  // green instance
	instance1->cow->SetInstanceColor("Green");
	instance1->rabbit->SetInstanceColor("Green");
	Dashboard::Instance()->SetCow1(instance1->cow);
	Dashboard::Instance()->SetRabbit1(instance1->rabbit);
	cout << "\nInstance 1:\n";
	instance1->PrintProbabilities();
}

void Arena::InitializeInstance2()
{
	instance2 = make_shared<InstanceOfGameEntities>();
	instance2->SetColor(new Color(0, 255, 0, 255));  // blue instance
	instance2->cow->SetInstanceColor("Blue");
	instance2->rabbit->SetInstanceColor("Blue");
	Dashboard::Instance()->SetCow2(instance2->cow);
	Dashboard::Instance()->SetRabbit2(instance2->rabbit);
	cout << "\nInstance 2:\n";
	instance2->PrintProbabilities();
}

void Arena::InitializeInstance3()
{

	instance3 = make_shared<InstanceOfGameEntities>();
	instance3->SetColor(new Color(255, 0, 0, 255));  // red instance
	instance3->cow->SetInstanceColor("Red");
	instance3->rabbit->SetInstanceColor("Red");
	Dashboard::Instance()->SetCow3(instance3->cow);
	Dashboard::Instance()->SetRabbit3(instance3->rabbit);
	cout << "\nInstance 3:\n";
	instance3->PrintProbabilities();
}

void Arena::InitializeInstance4()
{
	instance4 = make_shared<InstanceOfGameEntities>();
	instance4->SetColor(new Color(255, 0,255, 255)); // yellow instance
	instance4->cow->SetInstanceColor("Yellow");
	instance4->rabbit->SetInstanceColor("Yellow");
	Dashboard::Instance()->SetCow4(instance4->cow);
	Dashboard::Instance()->SetRabbit4(instance4->rabbit);
	cout << "\nInstance 4:\n";
	instance4->PrintProbabilities();
}