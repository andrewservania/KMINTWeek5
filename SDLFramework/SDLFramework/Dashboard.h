#pragma once
#include <string>
#include <stdint.h>
#include "Cow.h"
#include "Rabbit.h"

class Dashboard
{
public:
	static std::string applicationInformation;
	static std::string timePassed;
	static std::string amountOfRuns;

	static std::string cow1StateLabel;
	static std::string cow2StateLabel;
	static std::string cow3StateLabel;
	static std::string cow4StateLabel;

	static std::string stateOfAllRabbitsLabel;

	static std::string rabbit1Score;
	static std::string rabbit2Score;
	static std::string rabbit3Score;
	static std::string rabbit4Score;

	static std::string cow1Score;
	static std::string cow2Score;
	static std::string cow3Score;
	static std::string cow4Score;

	static Cow* cow1;
	static Cow* cow2;
	static Cow* cow3;
	static Cow* cow4;

	static Rabbit* rabbit1;
	static Rabbit* rabbit2;
	static Rabbit* rabbit3;
	static Rabbit* rabbit4;

	Dashboard();
	~Dashboard();
	void Update();

	// Application information
	std::string ApplicationInformation() const { return applicationInformation; }

	void SetTimePassed(uint32_t val) {
		if (val <= 9){ timePassed = "Time passed: 00:0" + std::to_string(val); }
		else{ timePassed = "Time passed: 00:" +std::to_string(val); }
	}
	void SetAmountOfRuns(int val){ amountOfRuns = "Amount of runs: "+ std::to_string(val); }


	// Accessors

	void SetRabbit1Score(int val) { rabbit1Score = "Rabbit 1 score: " + std::to_string(val); }
	void SetRabbit2Score(int val) { rabbit2Score = "Rabbit 2 score: " + std::to_string(val); }
	void SetRabbit3Score(int val) { rabbit3Score = "Rabbit 3 score: " + std::to_string(val); }
	void SetRabbit4Score(int val) { rabbit4Score = "Rabbit 4 score: " + std::to_string(val); }

	void SetCow1Score(int val) { cow1Score = "Cow 1 score: " + std::to_string(val); }
	void SetCow2Score(int val) { cow2Score = "Cow 2 score: " + std::to_string(val); }
	void SetCow3Score(int val) { cow3Score = "Cow 3 score: " + std::to_string(val); }
	void SetCow4Score(int val) { cow4Score = "Cow 4 score: " + std::to_string(val); }

	void SetCow1StateLabel(std::string val){ cow1StateLabel = "Cow 1 State: " + val; }
	void SetCow2StateLabel(std::string val){ cow2StateLabel = "Cow 2 State: " + val; }
	void SetCow3StateLabel(std::string val){ cow3StateLabel = "Cow 3 State: " + val; }
	void SetCow4StateLabel(std::string val){ cow4StateLabel = "Cow 4 State: " + val; }

	void SetStateOfAllRabbits(std::string val){ stateOfAllRabbitsLabel = val; }
	void SetCow1(Cow* val){ cow1 = val; }
	void SetCow2(Cow* val){ cow2 = val; }
	void SetCow3(Cow* val){ cow3 = val; }
	void SetCow4(Cow* val){ cow4 = val; }

	void SetRabbit1(Rabbit* val){ rabbit1 = val; }
	void SetRabbit2(Rabbit* val){ rabbit2 = val; }
	void SetRabbit3(Rabbit* val){ rabbit3 = val; }
	void SetRabbit4(Rabbit* val){ rabbit4 = val; }

	
	static Dashboard* Instance()
	{
		static Dashboard instance;
		return &instance;
	}

};
