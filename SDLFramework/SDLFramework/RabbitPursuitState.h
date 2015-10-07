#pragma once

#include "State.h"
#include "Rabbit.h"



class RabbitPursuitState : public State<Rabbit>
{
public:
	RabbitPursuitState();
	~RabbitPursuitState();
	void Enter(Rabbit* cow) override;
	void Execute(Rabbit* cow) override;
	void Exit(Rabbit* cow) override;
	std::string GetStateName() override { return "Pursuing Cow"; }
	static RabbitPursuitState* Instance()
	{
		static RabbitPursuitState instance;
		return &instance;
	}
};

