#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"
#include "InstanceOfGameEntities.h"
class Arena
{
private:
	
public:

	Arena();
	~Arena();


	static Arena* Instance()
	{
		static Arena instance;

		return &instance;
	}
};

