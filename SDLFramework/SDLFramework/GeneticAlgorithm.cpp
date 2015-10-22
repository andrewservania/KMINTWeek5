#include "GeneticAlgorithm.h"

#include <algorithm>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm()
{
}

GeneticAlgorithm::~GeneticAlgorithm()
{
}

InstanceScore GeneticAlgorithm::DetermineMostEffectiveInstance()
{
	// sort vector grom greatest to smallest
	sort(instanceScores.begin(), instanceScores.end(), greater<InstanceScore>());
	winningInstanceColor = instanceScores.at(0).instanceColor;
	return instanceScores.at(0);
}

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
	ProbabilityDistribution* nextGenerationProbDistribution = new ProbabilityDistribution(0,0,0,0);

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