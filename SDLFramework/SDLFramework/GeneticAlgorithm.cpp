#include "GeneticAlgorithm.h"

#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

GeneticAlgorithm::GeneticAlgorithm()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

GeneticAlgorithm::~GeneticAlgorithm()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Determine most effective instance. </summary>
///
///  Determine which instance was the most effective by checking which instance has the cow
///  with the highest score.
///  This is done by sorting a vector containing all the instances score by highest score to lowest.
///  The highest instance score will be return.
/// <remarks>	Andrew Servania,. </remarks>
///
/// <returns>	An InstanceScore. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

InstanceScore GeneticAlgorithm::DetermineMostEffectiveInstance()
{
	// sort vector grom greatest to smallest
	sort(instanceScores.begin(), instanceScores.end(), greater<InstanceScore>());
	scoreRankings.clear();
	scoreRankings = instanceScores;
	winningInstanceColor = instanceScores.at(0).instanceColor;
	return instanceScores.at(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the next generation prob distribution. </summary>
///
/// The chances of the cow of the most effective instance in a given round will copied.
/// The two choices with the highest probabilities will be passed unto the next generation offspring of cows.
/// As it is for the two remaining choices, their probabilities will be me determined at random.
/// A new probability value probability will be generated. This is a value between 10 and 30.
/// This newly created set of probabilities will set into a Probability Distribution objects.
/// The values will be normalized to a scale of 0 to 100% and lastly returned.
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <returns>	null if it fails, else the next generation prob distribution. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

ProbabilityDistribution* GeneticAlgorithm::GetNextGenerationProbDistribution()
{
	// Determine the winning instance
	InstanceScore winningInstance = DetermineMostEffectiveInstance();

	// pair up choices with their probabilities
	vector <pair<ProbabilityDistribution::Choice, int>> choices;

	choices.push_back(make_pair(winningInstance.probabilityDistribution->CHOICE1, winningInstance.probabilityDistribution->GetChoice1Probability()));
	choices.push_back(make_pair(winningInstance.probabilityDistribution->CHOICE2, winningInstance.probabilityDistribution->GetChoice2Probability()));
	choices.push_back(make_pair(winningInstance.probabilityDistribution->CHOICE3, winningInstance.probabilityDistribution->GetChoice3Probability()));
	choices.push_back(make_pair(winningInstance.probabilityDistribution->CHOICE4, winningInstance.probabilityDistribution->GetChoice4Probability()));

	// sort choices to find the choice with the highest probability. Which will be the first element in the vector after being sorted.
	sort(choices.begin(), choices.end(), &GeneticAlgorithm::pairCompare);

	// create a new probability distribution for next run's offspring
	ProbabilityDistribution* nextGenerationProbDistribution = new ProbabilityDistribution(0, 0, 0, 0);

	// set the new probability values for the new offspring
	// We take the probability of two of the cows strategies with the highest probability

	// Transfer a choice from parent to next generation offspring
	// And we also increase the probability of the two most effective strategies of the cow in order to make it more adaptive
	switch (choices.at(0).first)
	{
	case ProbabilityDistribution::CHOICE1:
		nextGenerationProbDistribution->SetChoice1Probability(choices.at(0).second + 10);
		break;
	case ProbabilityDistribution::CHOICE2:
		nextGenerationProbDistribution->SetChoice2Probability(choices.at(1).second + 10);
		break;
	case ProbabilityDistribution::CHOICE3:
		nextGenerationProbDistribution->SetChoice3Probability(choices.at(2).second + 10);
		break;
	case ProbabilityDistribution::CHOICE4:
		nextGenerationProbDistribution->SetChoice4Probability(choices.at(3).second + 10);
		break;
	}

	// Transfer a second choice from parent to next generation offspring
	switch (choices.at(1).first)
	{
	case ProbabilityDistribution::CHOICE1:
		nextGenerationProbDistribution->SetChoice1Probability(choices.at(0).second + 10);
		break;
	case ProbabilityDistribution::CHOICE2:
		nextGenerationProbDistribution->SetChoice2Probability(choices.at(1).second + 10);
		break;
	case ProbabilityDistribution::CHOICE3:
		nextGenerationProbDistribution->SetChoice3Probability(choices.at(2).second + 10);
		break;
	case ProbabilityDistribution::CHOICE4:
		nextGenerationProbDistribution->SetChoice4Probability(choices.at(3).second + 10);
		break;
	}

	// For the two other remaining choices we generate random probability values
	switch (choices.at(2).first)
	{
	case ProbabilityDistribution::CHOICE1:
		nextGenerationProbDistribution->SetChoice1Probability(10 + rand() % 21);
		break;
	case ProbabilityDistribution::CHOICE2:
		nextGenerationProbDistribution->SetChoice2Probability(10 + rand() % 21);

		break;
	case ProbabilityDistribution::CHOICE3:
		nextGenerationProbDistribution->SetChoice3Probability(10 + rand() % 21);

		break;
	case ProbabilityDistribution::CHOICE4:
		nextGenerationProbDistribution->SetChoice4Probability(10 + rand() % 21);
		break;
	}

	switch (choices.at(3).first)
	{
	case ProbabilityDistribution::CHOICE1:
		nextGenerationProbDistribution->SetChoice1Probability(10 + rand() % 21);

		break;
	case ProbabilityDistribution::CHOICE2:
		nextGenerationProbDistribution->SetChoice2Probability(10 + rand() % 21);

		break;
	case ProbabilityDistribution::CHOICE3:
		nextGenerationProbDistribution->SetChoice3Probability(10 + rand() % 21);

		break;
	case ProbabilityDistribution::CHOICE4:
		nextGenerationProbDistribution->SetChoice4Probability(10 + rand() % 21);

		break;
	}

	// normalize probability values to a range of 0 to 100
	nextGenerationProbDistribution->Normalize();

	// lastly, remove instances that have already been used to calculate the probabilities for the next generation of cow offsprings
	instanceScores.clear();

	return nextGenerationProbDistribution;
}