#pragma once
#include "Cow.h"
#include "Rabbit.h"
#include "Weapon.h"
#include "Pill.h"

#include <memory>

class InstanceOfGameEntities
{
public:

	Cow* cow;
	Rabbit* rabbit;
	Weapon* weapon;
	Pill* pill;

	InstanceOfGameEntities();
	~InstanceOfGameEntities();
	void SetColor(Color* color);
	void Reset();
	void End();
};

