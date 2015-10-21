#pragma once

#include "State.h"
#include "Rabbit.h"



class RabbitPursuitState : public State<Rabbit>
{
private:
	void Start(Rabbit* rabbit);
	bool hasStarted;
public:
	RabbitPursuitState();
	~RabbitPursuitState();
	void Enter(Rabbit* rabbit) override;
	void Execute(Rabbit* rabbit) override;
	void Exit(Rabbit* rabbit) override;
	std::string GetStateName() override { return "Pursuit (Chasing Cow)"; }

	static RabbitPursuitState* Instance()
	{
		static RabbitPursuitState instance;
		return &instance;
	}
};

