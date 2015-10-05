#pragma once
#include "State.h"
#include "Cow.h"
class CowPursuitState :
	public State<Cow>
{
private:
	bool hasStarted;
	void Start(Cow* cow);

public:
	CowPursuitState();
	~CowPursuitState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Pursuing rabbit"; }
	static CowPursuitState* Instance()
	{
		static CowPursuitState instance;
		return &instance;
	}
};

