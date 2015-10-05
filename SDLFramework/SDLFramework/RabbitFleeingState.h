#pragma once
#include "State.h"
#include "Rabbit.h"

class RabbitFleeingState :
	public State<Rabbit>
{
private:
	bool hasStarted;
	void Start(Rabbit* rabbit);
	bool NoThreat(Rabbit* rabbit);

public:
	RabbitFleeingState();
	~RabbitFleeingState();
	void Enter(Rabbit* rabbit) override;
	void Execute(Rabbit* rabbit) override;
	void Exit(Rabbit* rabbit) override;
	std::string GetStateName() override { return "Fleeing"; }
	static RabbitFleeingState* Instance()
	{
		static RabbitFleeingState instance;
		return &instance;
	}
};
