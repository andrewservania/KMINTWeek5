#pragma once
#include "State.h"
#include "Cow.h"
class CowGlobalState :
	public State<Cow>
{
public:
	CowGlobalState();
	~CowGlobalState();

	void Enter(Cow* cow);
	void Execute(Cow* cow);
	void Exit(Cow* cow);
	std::string GetStateName() { return "Global State"; }
	static CowGlobalState* Instance()
	{
		static CowGlobalState instance;
		return &instance;
	}


};

