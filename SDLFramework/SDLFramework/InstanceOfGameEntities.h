#pragma once
#include "Cow.h"
#include "Rabbit.h"
#include "Weapon.h"
#include "Pill.h"

#include <memory>

struct InstanceScore
{
	int cowScore = 0;
	int rabbitScore = 0;
	std::string instanceColor;
	ProbabilityDistribution* probabilityDistribution;

	bool operator > (const InstanceScore& instance) const
	{
		return  (cowScore > instance.cowScore);
	}
};

class InstanceOfGameEntities
{
public:

	Cow* cow;
	Rabbit* rabbit;
	Weapon* weapon;
	Pill* pill;
	InstanceScore instanceScore;

	InstanceOfGameEntities();
	~InstanceOfGameEntities();
	void SetColor(Color* color);
	void Reset();
	void End();
	void PrintProbabilities();

	InstanceScore GetScore();
};
