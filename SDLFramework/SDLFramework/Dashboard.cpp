
#include "Dashboard.h"
#include "FWApplication.h"
#include "Arena.h"
#include "ProbabilityDistribution.h"

std::string Dashboard::applicationInformation;
std::string Dashboard::timePassed;
std::string Dashboard::amountOfRuns;


std::string Dashboard::cow1Score;
std::string Dashboard::cow2Score;
std::string Dashboard::cow3Score;
std::string Dashboard::cow4Score;

std::string Dashboard::rabbit1Score;
std::string Dashboard::rabbit2Score;
std::string Dashboard::rabbit3Score;
std::string Dashboard::rabbit4Score;

std::string Dashboard::cow1StateLabel;
std::string Dashboard::cow2StateLabel;
std::string Dashboard::cow3StateLabel;
std::string Dashboard::cow4StateLabel;

std::string Dashboard::stateOfAllRabbitsLabel;

Cow* Dashboard::cow1;
Cow* Dashboard::cow2;
Cow* Dashboard::cow3;
Cow* Dashboard::cow4;

Rabbit* Dashboard::rabbit1;
Rabbit* Dashboard::rabbit2;
Rabbit* Dashboard::rabbit3;
Rabbit* Dashboard::rabbit4;

using namespace std;

Dashboard::Dashboard()
{
	// Application information
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

Dashboard::~Dashboard()
{

}

void Dashboard::Update()
{
	if (rabbit1 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 1 Color: " + rabbit1->GetInstanceColor(), 130, 120); // Instance Color
		SetRabbit1Score(rabbit1->GetScore());

		//FWApplication::GetInstance()->DrawTextOnScreen(
		//	"1. Flee: " + to_string(cow1->GetProbabilityDistribution()->GetChoice1Probability()) + "%  " +
		//	"FleeAndSearchWeapon: " + to_string(cow1->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		//	"FleeAndSearchPill: " + to_string(cow1->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		//	"Hide: " + to_string(cow1->GetProbabilityDistribution()->GetChoice4Probability()) + "% ", 250, 200);	// Cow 1 probability
	}
	if (rabbit2 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 2 Color: " + rabbit2->GetInstanceColor(), 130, 220); // Instance Color
		SetRabbit2Score(rabbit2->GetScore());

		//FWApplication::GetInstance()->DrawTextOnScreen(
		//	"2. Flee: " + to_string(cow2->GetProbabilityDistribution()->GetChoice1Probability()) + "% " +
		//	"FleeAndSearchWeapon: " + to_string(cow2->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		//	"FleeAndSearchPill: " + to_string(cow2->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		//	"Hide: " + to_string(cow2->GetProbabilityDistribution()->GetChoice4Probability()) + "% ", 250, 300);	// Cow 1 probability

	}
	if (rabbit3 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 3 Color: " + rabbit3->GetInstanceColor(), 130, 320); // Instance Color
		SetRabbit3Score(rabbit3->GetScore());

		//FWApplication::GetInstance()->DrawTextOnScreen(
		//	"3. Flee: " + to_string(cow3->GetProbabilityDistribution()->GetChoice1Probability()) + "% " +
		//	"FleeAndSearchWeapon: " + to_string(cow3->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		//	"FleeAndSearchPill: " + to_string(cow3->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		//	"Hide: " + to_string(cow3->GetProbabilityDistribution()->GetChoice4Probability()) + "% ", 250, 400);	// Cow 1 probability

	}
	if (rabbit4 != nullptr)
	{
		FWApplication::GetInstance()->DrawTextOnScreen("Instance 4 Color: " + rabbit4->GetInstanceColor(), 130, 420); // Instance Color
		SetRabbit4Score(rabbit4->GetScore());

		//FWApplication::GetInstance()->DrawTextOnScreen(
		//	"4. Flee: " + to_string(cow4->GetProbabilityDistribution()->GetChoice1Probability()) + "% " +
		//	"FleeAndSearchWeapon: " + to_string(cow4->GetProbabilityDistribution()->GetChoice2Probability()) + "% " +
		//	"FleeAndSearchWeapon: " + to_string(cow4->GetProbabilityDistribution()->GetChoice3Probability()) + "% " +
		//	"Hide: " + to_string(cow4->GetProbabilityDistribution()->GetChoice4Probability()) + "% ", 250, 500);	// Cow 1 probability
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
	FWApplication::GetInstance()->DrawTextOnScreen(stateOfAllRabbitsLabel + rabbit1->GetCurrentState(), 200, 600);	// State of the rabbit of all 4 instances

}