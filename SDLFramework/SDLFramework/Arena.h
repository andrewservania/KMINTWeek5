#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"
#include "InstanceOfGameEntities.h"
#include "SDL_timer.h"


class Arena 
{
private:
	uint32_t seconds;

	void ResetInstances();

public:

	Arena();
	~Arena();
	void SecondTick();
};

