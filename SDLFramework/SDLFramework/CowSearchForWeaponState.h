#pragma 
#include "State.h"
#include "Cow.h"

class CowSearchForWeaponState : public State<Cow>
{
private:
	void Start(Cow* cow);

public:
	CowSearchForWeaponState();
	~CowSearchForWeaponState();
	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Search For Weapon"; }
	static CowSearchForWeaponState* Instance()
	{
		static CowSearchForWeaponState instance;
		return &instance;
	}
};


