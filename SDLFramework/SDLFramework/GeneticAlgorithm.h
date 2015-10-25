#pragma once




#include <vector>

#include "InstanceOfGameEntities.h"

class GeneticAlgorithm
{
private:

	std::vector<InstanceScore> instanceScores;
	std::string winningInstanceColor;
	std::vector<InstanceScore> scoreRankings;

	// 1. determining the cow who has the highest score
	bool static pairCompare(const std::pair<ProbabilityDistribution::Choice, int> firstPair,
		const std::pair<ProbabilityDistribution::Choice, int> secondPair)
	{
		return (firstPair.second > secondPair.second);
	}


public:
	GeneticAlgorithm();
	~GeneticAlgorithm();
	InstanceScore DetermineMostEffectiveInstance();
	
	void AddInstanceScores(InstanceScore val){ instanceScores.push_back(val); };
	ProbabilityDistribution* GetNextGenerationProbDistribution();
	std::string GetWinningInstanceColor() { return winningInstanceColor; };
	std::vector<InstanceScore> GetScoreRanking() { return scoreRankings; }


};

