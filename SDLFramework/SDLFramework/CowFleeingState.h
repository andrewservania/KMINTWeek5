#pragma once
#include "State.h"
#include "Cow.h"

class CowFleeingState :
	public State<Cow>
{
private:
	bool hasStarted;
	void Start(Cow* Cow);

public:
	CowFleeingState();
	~CowFleeingState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Fleeing"; }
	bool NoThreat(Cow* cow);
	static CowFleeingState* Instance()
	{
		static CowFleeingState instance;
		return &instance;
	}
};

