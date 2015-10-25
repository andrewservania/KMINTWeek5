#include "Dashboard.h"
#include "FWApplication.h"
#include "Arena.h"
#include "ProbabilityDistribution.h"

/// <summary>	Information describing the dashboard application. </summary>
std::string Dashboard::applicationInformation;
/// <summary>	The time passed. </summary>
std::string Dashboard::timePassed;
/// <summary>	The amount of runs. </summary>
std::string Dashboard::amountOfRuns;

/// <summary>	The score of the cow from instance 1. </summary>
std::string Dashboard::cow1Score;
/// <summary>	The score of the cow from instance 2. </summary>
std::string Dashboard::cow2Score;
/// <summary>	The score of the cow from instance 3. </summary>
std::string Dashboard::cow3Score;
/// <summary>	The score of the cow from instance 4. </summary>
std::string Dashboard::cow4Score;

/// <summary>	The score of the rabbit from instance 1. </summary>
std::string Dashboard::rabbit1Score;
/// <summary>	The score of the rabbit from instance 2. </summary>
std::string Dashboard::rabbit2Score;
/// <summary>	The score of the rabbit from instance 3. </summary>
std::string Dashboard::rabbit3Score;
/// <summary>	The score of the rabbit from instance 4. </summary>
std::string Dashboard::rabbit4Score;

/// <summary>	The dashboard cow 1 state label. </summary>
std::string Dashboard::cow1StateLabel;
/// <summary>	The dashboard cow 2 state label. </summary>
std::string Dashboard::cow2StateLabel;
/// <summary>	The dashboard cow 3 state label. </summary>
std::string Dashboard::cow3StateLabel;
/// <summary>	The dashboard cow 4 state label. </summary>
std::string Dashboard::cow4StateLabel;

/// <summary>	The state label of all rabbits. </summary>
std::string Dashboard::stateOfAllRabbitsLabel;

/// <summary>	The first dashboard cow. </summary>
Cow* Dashboard::cow1;
/// <summary>	The second dashboard cow. </summary>
Cow* Dashboard::cow2;
/// <summary>	The third dashboard cow. </summary>
Cow* Dashboard::cow3;
/// <summary>	The fourth dashboard cow. </summary>
Cow* Dashboard::cow4;

/// <summary>	The first dashboard rabbit. </summary>
Rabbit* Dashboard::rabbit1;
/// <summary>	The second dashboard rabbit. </summary>
Rabbit* Dashboard::rabbit2;
/// <summary>	The third dashboard rabbit. </summary>
Rabbit* Dashboard::rabbit3;
/// <summary>	The fourth dashboard rabbit. </summary>
Rabbit* Dashboard::rabbit4;

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
///  initialize all parameters that are to be displayed on the dashboard
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Dashboard::Dashboard()
{
	applicationInformation = "Andrew Servania - KMINT Week 5";
	timePassed = "Time passed: 00:00";
	amountOfRuns = "Amount of runs: 0";

	cow1Score = "Cow 1 score: 0";
	cow2Score = "Cow 2 score: 0";
	cow3Score = "Cow 3 score: 0";
	cow4Score = "Cow 4 score: 0";

	rabbit1Score = "Rabbit 1 score: 0";
	rabbit2Score = "Rabbit 2 score: 0";
	rabbit3Score = "Rabbit 3 score: 0";
	rabbit4Score = "Rabbit 4 score: 0";

	cow1StateLabel = "Cow 1 State: null";
	cow2StateLabel = "Cow 2 State: null";
	cow3StateLabel = "Cow 3 State: null";
	cow4StateLabel = "Cow 4 State: null";

	stateOfAllRabbitsLabel = "State of the rabbit of all instances: ";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Dashboard::~Dashboard()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the dashboard. </summary>
///
///  Updates the dashboard with in realtime with the following statistics:
///  1) Instance color
///  2) The state of the cow of all instances
///  3) Application information
///  4) The time that has passed
///  5) The amount of runs
///  6) The state of the rabbit of all instances
///  7) Some additional description regarding the probability development of the cow's choices
///  8)
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Dashboard::Update()
{
	if (rabbit1 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 1 Color: " + rabbit1->GetInstanceColor(), 130, 120); // Instance Color
		SetRabbit1Score(rabbit1->GetScore());
	}
	if (rabbit2 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 2 Color: " + rabbit2->GetInstanceColor(), 130, 220); // Instance Color
		SetRabbit2Score(rabbit2->GetScore());
	}
	if (rabbit3 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 3 Color: " + rabbit3->GetInstanceColor(), 130, 320); // Instance Color
		SetRabbit3Score(rabbit3->GetScore());
	}
	if (rabbit4 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 4 Color: " + rabbit4->GetInstanceColor(), 130, 420); // Instance Color
		SetRabbit4Score(rabbit4->GetScore());
	}

	if (cow1 != nullptr)
	{
		SetCow1Score(cow1->GetScore());
		SetCow1StateLabel(cow1->GetFSM()->CurrentState()->GetStateName());
	}
	if (cow2 != nullptr)
	{
		SetCow2Score(cow2->GetScore());
		SetCow2StateLabel(cow2->GetFSM()->CurrentState()->GetStateName());
	}
	if (cow3 != nullptr)
	{
		SetCow3Score(cow3->GetScore());
		SetCow3StateLabel(cow3->GetFSM()->CurrentState()->GetStateName());
	}
	if (cow4 != nullptr)
	{
		SetCow4Score(cow4->GetScore());
		SetCow4StateLabel(cow4->GetFSM()->CurrentState()->GetStateName());
	}

	// Application information
	FWApplication::GetInstance()->DrawTextOnScreen(applicationInformation, 400, 50);
	FWApplication::GetInstance()->DrawTextOnScreen(timePassed, 400, 70);   // Now indicates the amount of time passed.
	FWApplication::GetInstance()->DrawTextOnScreen(amountOfRuns, 400, 90); // Amount of runs

	//KMINT Week 5

	// Instance1
	FWApplication::GetInstance()->DrawTextOnScreen(rabbit1Score, 130, 140);		// Rabbit 1 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow1Score, 130, 160);		// Cow 1 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow1StateLabel, 130, 180);	// Cow 1 State

	// Instance2
	FWApplication::GetInstance()->DrawTextOnScreen(rabbit2Score, 130, 240);		// Rabbit 2 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow2Score, 130, 260);		// Cow 2 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow2StateLabel, 130, 280);	// Cow 2 State

	// Instance3
	FWApplication::GetInstance()->DrawTextOnScreen(rabbit3Score, 130, 340);		// Rabbit 3 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow3Score, 130, 360);		// Cow 3 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow3StateLabel, 130, 380);	// Cow 3 State

	// Instance4
	FWApplication::GetInstance()->DrawTextOnScreen(rabbit4Score, 130, 440);		// Rabbit 4 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow4Score, 130, 460);		// Cow 4 score
	FWApplication::GetInstance()->DrawTextOnScreen(cow4StateLabel, 130, 480);	// Cow 4 State

	// The state of rabbit number1 will be representative of all for the state of all other rabbits, respectively (As required by KMINT Week 5
	FWApplication::GetInstance()->DrawTextOnScreen(stateOfAllRabbitsLabel + rabbit1->GetCurrentState(), 350, 700);	// State of the rabbit of all 4 instances

	FWApplication::GetInstance()->DrawTextOnScreen("Please check the console window for realtime developments on the cow's choices", 350, 730);	// State of the rabbit of all 4 instances
}