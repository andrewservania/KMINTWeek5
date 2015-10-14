#include "ProbabilityDistribution.h"
#include "Dashboard.h"
#include <cstdlib>
#include <assert.h>
#include <stack>

using namespace std;

// A class created to distribute probability among three choices in the most amateuristic way possible.
// My sincere apologies to any statisticians ,computer-math scientists, scientific software engineers.
// I stand open to all your expert feedback. :)

ProbabilityDistribution::ProbabilityDistribution() : choice1Probability(20), choice2Probability(20), choice3Probability(20), choice4Probability(20)
{

}
ProbabilityDistribution::ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3, int probabilityChoice4) : choice1Probability(20), choice2Probability(20), choice3Probability(20), choice4Probability(20)
{
	currentTotalProbability = totalProbability;
	choice1Probability = probabilityChoice1;
	choice2Probability = probabilityChoice2;
	choice3Probability = probabilityChoice3;
	choice4Probability = probabilityChoice4;

	assert((choice1Probability + choice2Probability + choice3Probability + probabilityChoice4) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");

	UpdateProbabilityLabels();
}

ProbabilityDistribution::~ProbabilityDistribution()
{
}

int ProbabilityDistribution::GenerateRandomChoice()
{
	int randomNumber = rand() % totalProbability + 1; // number between 0 and 100

	if (randomNumber >= 0 && randomNumber <= choice1Probability) 
		return 1;
	if (randomNumber > choice1Probability && randomNumber <= (choice1Probability + choice2Probability)) 
		return 2;
	if (randomNumber > (choice1Probability + choice2Probability) && randomNumber <= (choice1Probability + choice2Probability + choice3Probability))
		return 3;
	if (randomNumber > (choice1Probability + choice2Probability + choice3Probability)) 
		return 4;

	return 0; // If the random number does not fall within the above-declared ranges, return 0
}

void ProbabilityDistribution::UpdateProbabilityLabels()
{
	Dashboard::Instance()->SetChoice1Probablity(choice1Probability);
	Dashboard::Instance()->SetChoice2Probablity(choice2Probability);
	Dashboard::Instance()->SetChoice3Probablity(choice3Probability);
}