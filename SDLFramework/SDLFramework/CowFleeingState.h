#pragma once
#include "State.h"
#include "Cow.h"

class CowFleeingState :
	public State<Cow>
{
public:
	CowFleeingState();
	~CowFleeingState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	void Start(Cow* Cow);
	std::string GetStateName() override { return "Fleeing"; }
	static CowFleeingState* Instance()
	{
		static CowFleeingState instance;
		return &instance;
	}
};

