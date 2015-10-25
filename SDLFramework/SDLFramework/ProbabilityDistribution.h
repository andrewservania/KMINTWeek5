#pragma once

class ProbabilityDistribution
{
private:
	// Probability is in percentages
	const int totalProbability = 100;
	const int minimumProbabilityPerChoice = 10;

	int currentTotalProbability;
	int choice1Probability;
	int choice2Probability;
	int choice3Probability;
	int choice4Probability;

	int lastChangedChoice;

public:

	enum Choice
	{
		CHOICE1, CHOICE2, CHOICE3, CHOICE4
	};

	;

	ProbabilityDistribution();
	ProbabilityDistribution(int probabilityChoice1, int probabilityChoice2, int probabilityChoice3, int probabilityChoice4);
	~ProbabilityDistribution();
	int GenerateRandomChoice();

	int GetChoice1Probability() { return choice1Probability; }
	int GetChoice2Probability() { return choice2Probability; }
	int GetChoice3Probability() { return choice3Probability; }
	int GetChoice4Probability() { return choice4Probability; }

	void SetChoice1Probability(int val){ choice1Probability = val; };
	void SetChoice2Probability(int val){ choice2Probability = val; };
	void SetChoice3Probability(int val){ choice3Probability = val; };
	void SetChoice4Probability(int val){ choice4Probability = val; };
	void Normalize();
	void DistributeProbabilityAtRandom();
};
