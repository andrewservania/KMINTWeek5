#pragma once
#include "State.h"
#include "Cow.h"

class CowHidingState :
	public State<Cow>
{
private:
	double cowCurrentXpos;
	double cowCurrentYpos;


public:
	CowHidingState();
	~CowHidingState();


	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Hiding"; }



	static CowHidingState* Instance()
	{
		static CowHidingState instance;
		return &instance;
	}

};

