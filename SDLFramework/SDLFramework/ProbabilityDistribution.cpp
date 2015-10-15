#include "ProbabilityDistribution.h"
#include "Dashboard.h"
#include <cstdlib>
#include <assert.h>
#include <stack>

using namespace std;

// A class created to distribute probability among three choices in the most amateuristic way possible.
// My sincere apologies to any statisticians ,computer-math scientists, scientific software engineers.
// I stand open to all your expert feedback. :)

ProbabilityDistribution::ProbabilityDistribution()
{
	DistributeProbabilityAtRandom();
}

ProbabilityDistribution::ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3, int probabilityChoice4)
{
	currentTotalProbability = totalProbability;
	choice1Probability = probabilityChoice1;
	choice2Probability = probabilityChoice2;
	choice3Probability = probabilityChoice3;
	choice4Probability = probabilityChoice4;

	assert((choice1Probability + choice2Probability + choice3Probability + probabilityChoice4) == 100 && "The probability numbers are incorrect. Make sure the choice percentages equal 100% and 100% only.");
}

ProbabilityDistribution::~ProbabilityDistribution()
{
}

int ProbabilityDistribution::GenerateRandomChoice()
{
	int randomNumber = rand() % 100 + 1; // number between 0 and 100

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



void ProbabilityDistribution::DistributeProbabilityAtRandom()
{
	// The sum represents the probability space that encapsules all the given choices.
	// Therefore, one must normalize to 100%. The benifit of this is that, it won't manner
	// hopw big the probability space is, because it will always be 100%.

	// Step 1: Generate 4 random numbers between 10 and 30.
	int randomNumber1 = 10 + rand() % 21; 
	int randomNumber2 = 10 + rand() % 21;
	int randomNumber3 = 10 + rand() % 21;
	int randomNumber4 = 10 + rand() % 21;

	// Step 2: Calculate the sum of these 4 random numbers 
	int sum = randomNumber1 + randomNumber2 + randomNumber3 + randomNumber4;

	// Step 3: Normalize the random numbers to a total of 100% and
	// Step 4:assign the random numbers as to 4 probability values.
	// These will be used to distribute the probability among the 4 choices.
	choice1Probability = (randomNumber1 * 100) / sum;
	choice2Probability = (randomNumber2 * 100) / sum;
	choice3Probability = (randomNumber3 * 100) / sum;
	choice4Probability = (randomNumber4 * 100) / sum;





}