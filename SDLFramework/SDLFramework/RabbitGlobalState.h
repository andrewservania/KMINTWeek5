#pragma once
#include "State.h"
#include "Rabbit.h"

class RabbitGlobalState :
	public State<Rabbit>
{
public:
	RabbitGlobalState();
	~RabbitGlobalState();

	void Enter(Rabbit* rabbit);
	void Execute(Rabbit* rabbit);
	void Exit(Rabbit* rabbit);
	std::string GetStateName() { return "Global State"; }
	static RabbitGlobalState* Instance()
	{
		static RabbitGlobalState instance;
		return &instance;
	}
};

