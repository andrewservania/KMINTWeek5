
#include "Dashboard.h"
#include "FWApplication.h"
#include "Arena.h"
#include "ProbabilityDistribution.h"

std::string Dashboard::applicationInformation;
std::string Dashboard::shortestPathLabel;
std::string Dashboard::cowStateLabel;
std::string Dashboard::rabbitStateLabel;
std::string Dashboard::comment1;
std::string Dashboard::comment2;
std::string Dashboard::comment3;
std::string Dashboard::comment4;
std::string Dashboard::comment5;
std::string Dashboard::comment6;
std::string Dashboard::comment7;
std::string Dashboard::comment8;
std::string Dashboard::comment9;
std::string Dashboard::comment10;
std::string Dashboard::comment11;
std::string Dashboard::comment12;
std::string Dashboard::comment13;

std::string Dashboard::choice1Probability;
std::string Dashboard::choice2Probability;
std::string Dashboard::choice3Probability;
std::string Dashboard::cowSleepingTurns;

using namespace std;

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 5");

	comment1 = "Time passed: 00:00";
	comment2 = "Amount of runs: 0";
	comment3 = "Rabbit score: 0";

	comment4 = "Cow score: 0";
	comment5 = "";
	comment6 = "";
	comment7 = "";
	comment8 = "";
	comment9 = "";

	comment10 = "";
	comment11 = "";
	comment12 = "";
	comment13 = "";


  //comment6 = "-------------------------------------------------------------------------------------------";
	//ShortestPathLabel("");

	SetChoice1Probablity(ProbabilityDistribution::Instance()->GetChoice1Probability());
	SetChoice2Probablity(ProbabilityDistribution::Instance()->GetChoice2Probability());
	SetChoice3Probablity(ProbabilityDistribution::Instance()->GetChoice3Probability());

	cowSleepingTurns = "Cow Sleeping Turns: 0";
}

Dashboard::~Dashboard()
{

}

void Dashboard::Update()
{
	// Application information
	FWApplication::GetInstance()->DrawTextOnScreen(applicationInformation, 400, 50);

	// KMINT Week 3 Description
	FWApplication::GetInstance()->DrawTextOnScreen(comment1, 400, 100); // Now indicates the amount of time passed.

	FWApplication::GetInstance()->DrawTextOnScreen(comment2, 400, 120);
	FWApplication::GetInstance()->DrawTextOnScreen(comment3, 300, 140);
	FWApplication::GetInstance()->DrawTextOnScreen(comment4, 300, 180);
	FWApplication::GetInstance()->DrawTextOnScreen(comment5, 300, 200);
	FWApplication::GetInstance()->DrawTextOnScreen(comment6, 300, 220);
	FWApplication::GetInstance()->DrawTextOnScreen(comment7, 300, 240);
	FWApplication::GetInstance()->DrawTextOnScreen(comment8, 300, 260);
	FWApplication::GetInstance()->DrawTextOnScreen(comment9, 300, 280);
	FWApplication::GetInstance()->DrawTextOnScreen(comment10, 300, 320);
	FWApplication::GetInstance()->DrawTextOnScreen(comment11, 300, 340);
	FWApplication::GetInstance()->DrawTextOnScreen(comment12, 300, 360);
	FWApplication::GetInstance()->DrawTextOnScreen(comment13, 300, 380);

	// Cow state label
	// CowStateLabel(Arena::cow->GetCurrentState());
	// FWApplication::GetInstance()->DrawTextOnScreen(cowStateLabel, 650, 90);
	// FWApplication::GetInstance()->DrawTextOnScreen("NEEDS FIX IN DASHBOARD CLASS", 300, 420);

	// Rabbit state label
	// RabbitStateLabel(Arena::rabbit->GetCurrentState());
	// FWApplication::GetInstance()->DrawTextOnScreen(rabbitStateLabel, 650, 110);
	// FWApplication::GetInstance()->DrawTextOnScreen("NEEDS FIX IN DASHBOARD CLASS", 300, 460);

	// Shortest path label
	// FWApplication::GetInstance()->DrawTextOnScreen(shortestPathLabel, 300, 500);

	// Probabilities
	// FWApplication::GetInstance()->DrawTextOnScreen(choice1Probability, 300, 540);
	// FWApplication::GetInstance()->DrawTextOnScreen(choice2Probability, 300, 560);
	// FWApplication::GetInstance()->DrawTextOnScreen(choice3Probability, 300, 580);




}