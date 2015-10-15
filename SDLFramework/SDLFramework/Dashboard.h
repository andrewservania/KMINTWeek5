#pragma once
#include <string>
#include <stdint.h>
class Dashboard
{
public:
	static std::string applicationInformation;
	static std::string shortestPathLabel;
	static std::string cowStateLabel;
	static std::string rabbitStateLabel;
	static std::string comment1;
	static std::string comment2;
	static std::string comment3;
	static std::string comment4;
	static std::string comment5;
	static std::string comment6;
	static std::string comment7;
	static std::string comment8;
	static std::string comment9;
	static std::string comment10;
	static std::string comment11;
	static std::string comment12;
	static std::string comment13;


	static std::string choice1Probability;
	static std::string choice2Probability;
	static std::string choice3Probability;
	static std::string cowSleepingTurns;



	Dashboard();
	~Dashboard();
	void Update();

	// Accessors
	std::string ApplicationInformation() const { return applicationInformation; }
	std::string ShortestPathLabel() const { return shortestPathLabel; }
	std::string CowStateLabel() const { return cowStateLabel; }
	std::string RabbitStateLabel() const { return rabbitStateLabel; }

	void ApplicationInformation(std::string val) { applicationInformation = val; }
	void ShortestPathLabel(std::string val) { shortestPathLabel = val; }
	void CowStateLabel(std::string val) { cowStateLabel = "Cow State: " + val; }
	void RabbitStateLabel(std::string val) { rabbitStateLabel = "Rabbit state: " + val; }
	void SetCowSleepingTurns(int val) { cowSleepingTurns = "Cow Sleeping Turns: " + std::to_string(val); }
	
	void SetTimePassed(uint32_t val) {
		if (val <= 9)
			comment1 = "Time passed: 00:0" +
			std::to_string(val);
		else{
			comment1 = "Time passed: 00:" +
				std::to_string(val);
		}
	}

	void SetAmountOfRuns(int val){ comment2 = "Amount of runs: "+ std::to_string(val); }
	
	void SetRabbitScore(int val) { comment3 = "Rabbit score: " + std::to_string(val); }

	void SetCowScore(int val) { comment4 = "Cow score: " + std::to_string(val); }
	
	
	
	static Dashboard* Instance()
	{
		static Dashboard instance;
		return &instance;
	}

};
