#pragma once
#include "State.h"
#include "Cow.h"
class CowFleeAndSearchPillState :
	public State<Cow>
{
private:
	void Start(Cow* cow);

public:
	CowFleeAndSearchPillState();
	~CowFleeAndSearchPillState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "FleeAndSearchForPill"; }
	static CowFleeAndSearchPillState* Instance()
	{
		static CowFleeAndSearchPillState instance;
		return &instance;
	}
};

