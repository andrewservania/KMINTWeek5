#pragma 
#include "State.h"
#include "Cow.h"

class CowFleeAndSearchWeaponState : public State<Cow>
{
private:
	void Start(Cow* cow);

public:
	CowFleeAndSearchWeaponState();
	~CowFleeAndSearchWeaponState();
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "FleeAndSearchForWeapon"; }
	static CowFleeAndSearchWeaponState* Instance()
	{
		static CowFleeAndSearchWeaponState instance;
		return &instance;
	}
};


