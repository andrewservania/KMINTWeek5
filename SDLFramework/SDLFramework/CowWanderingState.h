#pragma once
#include "State.h"
#include "Cow.h"
class CowWanderingState :
	public State<Cow>
{
public:
	CowWanderingState();
	~CowWanderingState();
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	void Start(Cow* cow);
	std::string GetStateName() override { return "Wandering"; }

	static CowWanderingState* Instance()
	{
		static CowWanderingState instance;
		return &instance;
	}
};

