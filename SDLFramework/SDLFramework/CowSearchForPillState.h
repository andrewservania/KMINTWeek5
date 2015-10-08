#pragma once
#include "State.h"
#include "Cow.h"
class CowSearchForPillState :
	public State<Cow>
{
private:
	void Start(Cow* cow);

public:
	CowSearchForPillState();
	~CowSearchForPillState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Search For Pill"; }
	static CowSearchForPillState* Instance()
	{
		static CowSearchForPillState instance;
		return &instance;
	}
};

