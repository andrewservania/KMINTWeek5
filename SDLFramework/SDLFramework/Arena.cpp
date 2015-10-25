////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	Arena.cpp
//
// summary:	Implements the arena class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Arena.h"
#include "Parameters.h"
#include "Dashboard.h"

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
/// 
///  Call the initialization of 4 instances containing a rabbit, a cow, a weapon and a pill
///  Set the timer and amount of runs to 0.
///  
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Arena::Arena()
{
	seconds = 0;
	runs = 0;
	applicationEnd = false;
	cout << "\nRun # " + to_string(runs+1);
	geneticAlgorithm = make_shared<GeneticAlgorithm>();

	InitializeInstance1();
	InitializeInstance2();
	InitializeInstance3();
	InitializeInstance4();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Arena::~Arena()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets the instances. </summary>
///
///  1) Reset all 4 instances
///  2) Determine the most effective instances based on the cow's score using the genetic algorithm   
///     class
///  3) Pass the genes to the most effective cow unto the next generation of cows.  
///  4) Reset the cow and rabbit's score and states.
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::ResetInstances()
{


	//Determine score of the current round
	geneticAlgorithm->AddInstanceScores(instance1->GetScore());
	geneticAlgorithm->AddInstanceScores(instance2->GetScore());
	geneticAlgorithm->AddInstanceScores(instance3->GetScore());
	geneticAlgorithm->AddInstanceScores(instance4->GetScore());


	// Determine cow's most effective instance
	ProbabilityDistribution* nextGenerationProbabilityDistribution = geneticAlgorithm->GetNextGenerationProbDistribution();
	string winningInstanceColor = geneticAlgorithm->GetWinningInstanceColor();
	cout << "\nThe most effective instance was: " + winningInstanceColor + "\n";
	cout << "Score ranking of instances:\n";
	int ranking = 1;
	for (InstanceScore score : geneticAlgorithm->GetScoreRanking())
	{
		cout << to_string(ranking) + " " + score.instanceColor + " instance with a cow score of " + to_string(score.cowScore) + " points.\n";
		ranking++;
	}
	// Pass the elitarian 'genes' to the next generation
	if (winningInstanceColor == "Green")
	{
		instance2->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance3->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance4->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
	}
	else if (winningInstanceColor == "Blue")
	{
		instance1->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance3->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance4->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
	}
	else if (winningInstanceColor == "Red")
	{
		instance1->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance2->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance4->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
	}
	else if (winningInstanceColor == "Yellow")
	{
		instance1->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance2->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
		instance3->cow->SetProbalitityOfChoices(nextGenerationProbabilityDistribution);
	}

	
	cout << "\n\n Run # " + to_string(runs+1);
	cout << "\nInstance 1 Green:\n";
	instance1->Reset();
	cout << "\nInstance 2 Blue:\n";
	instance2->Reset();
	cout << "\nInstance 3 Red:\n";
	instance3->Reset();
	cout << "\nInstance 4 Yellow:\n";
	instance4->Reset();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Second tick. </summary>
///  
///  1) Update the dashboard timer every seconds
///  2) Trigger an instance reset when the timer has reached 30 seconds.  
///  3) End the application after 5 runs.  
///  
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Ends a program. </summary>
///
/// The all activities in the Arena.
/// This function is called when the amount of runs have reached 5 runs.
/// 
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::EndProgram()
{
	//Determine score of the current round
	geneticAlgorithm->AddInstanceScores(instance1->GetScore());
	geneticAlgorithm->AddInstanceScores(instance2->GetScore());
	geneticAlgorithm->AddInstanceScores(instance3->GetScore());
	geneticAlgorithm->AddInstanceScores(instance4->GetScore());


	// Determine cow's most effective instance
	ProbabilityDistribution* nextGenerationProbabilityDistribution = geneticAlgorithm->GetNextGenerationProbDistribution();
	string winningInstanceColor = geneticAlgorithm->GetWinningInstanceColor();
	cout << "\nThe most effective instance was: " + winningInstanceColor + "\n";
	cout << "Score ranking of instances:\n";
	int ranking = 1;
	for (InstanceScore score : geneticAlgorithm->GetScoreRanking())
	{
		cout << to_string(ranking) + " " + score.instanceColor + " instance with a cow score of " + to_string(score.cowScore) + " points.\n";
		ranking++;
	}
	instance1->End();
	instance2->End();
	instance3->End();
	instance4->End();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the instance 1. </summary>
/// 
/// 1) instantiate instance number 1 containing a cow, a rabbit a pill and a weapon.
/// 2) Set all game entities of this instance to Green  
/// 3) Give the dashboard a pointer to the cow and rabbit in order to monitor their statistics  
///	   such as score and state.
///	4) Print the current probability distribution of the cow's strategic choices.
///	   Meaning (The percentage of chances distributed between the Fleeing Search For A Pill,
///	   Search For a Weapon and Hiding
/// 
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::InitializeInstance1()
{
	instance1 = make_shared<InstanceOfGameEntities>();
	instance1->SetColor(new Color(0, 0, 255, 255));  // green instance
	instance1->cow->SetInstanceColor("Green");
	instance1->rabbit->SetInstanceColor("Green");
	Dashboard::Instance()->SetCow1(instance1->cow);
	Dashboard::Instance()->SetRabbit1(instance1->rabbit);
	cout << "\nInstance 1 Green:\n";
	instance1->PrintProbabilities();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the instance 2. </summary>
/// 
/// 1) instantiate instance number 2 containing a cow, a rabbit a pill and a weapon.
/// 2) Set all game entities of this instance to Green
/// 3) Give the dashboard a pointer to the cow and rabbit in order to monitor their statistics
///	   such as score and state.
///	4) Print the current probability distribution of the cow's strategic choices.
///	   Meaning (The percentage of chances distributed between the Fleeing Search For A Pill,
///	   Search For a Weapon and Hiding
///	   
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::InitializeInstance2()
{
	instance2 = make_shared<InstanceOfGameEntities>();
	instance2->SetColor(new Color(0, 255, 0, 255));  // blue instance
	instance2->cow->SetInstanceColor("Blue");
	instance2->rabbit->SetInstanceColor("Blue");
	Dashboard::Instance()->SetCow2(instance2->cow);
	Dashboard::Instance()->SetRabbit2(instance2->rabbit);
	cout << "\nInstance 2 Blue:\n";
	instance2->PrintProbabilities();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the instance 3. </summary>
///
/// 1) instantiate instance number 3 containing a cow, a rabbit a pill and a weapon.
/// 2) Set all game entities of this instance to Green
/// 3) Give the dashboard a pointer to the cow and rabbit in order to monitor their statistics
///	   such as score and state.
///	4) Print the current probability distribution of the cow's strategic choices.
///	   Meaning (The percentage of chances distributed between the Fleeing Search For A Pill,
///	   Search For a Weapon and Hiding
/// 
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::InitializeInstance3()
{

	instance3 = make_shared<InstanceOfGameEntities>();
	instance3->SetColor(new Color(255, 0, 0, 255));  // red instance
	instance3->cow->SetInstanceColor("Red");
	instance3->rabbit->SetInstanceColor("Red");
	Dashboard::Instance()->SetCow3(instance3->cow);
	Dashboard::Instance()->SetRabbit3(instance3->rabbit);
	cout << "\nInstance 3 Red:\n";
	instance3->PrintProbabilities();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the instance 4. </summary>
///
/// 1) instantiate instance number 4 containing a cow, a rabbit a pill and a weapon.
/// 2) Set all game entities of this instance to Green
/// 3) Give the dashboard a pointer to the cow and rabbit in order to monitor their statistics
///	   such as score and state.
///	4) Print the current probability distribution of the cow's strategic choices.
///	   Meaning (The percentage of chances distributed between the Fleeing Search For A Pill,
///	   Search For a Weapon and Hiding
/// 
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Arena::InitializeInstance4()
{
	instance4 = make_shared<InstanceOfGameEntities>();
	instance4->SetColor(new Color(255, 0,255, 255)); // yellow instance
	instance4->cow->SetInstanceColor("Yellow");
	instance4->rabbit->SetInstanceColor("Yellow");
	Dashboard::Instance()->SetCow4(instance4->cow);
	Dashboard::Instance()->SetRabbit4(instance4->rabbit);
	cout << "\nInstance 4 Yellow:\n";
	instance4->PrintProbabilities();
}