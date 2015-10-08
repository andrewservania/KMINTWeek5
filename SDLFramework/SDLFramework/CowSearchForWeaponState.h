#pragma 
#include "State.h"
#include "Cow.h"

class CowSearchForWeaponState : public State<Cow>
{
public:
	CowSearchForWeaponState();
	~CowSearchForWeaponState();
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	void Start(Cow* cow);
	std::string GetStateName() override { return "Search For Weapon"; }
	static CowSearchForWeaponState* Instance()
	{
		static CowSearchForWeaponState instance;
		return &instance;
	}
};


