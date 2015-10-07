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
	  //static Cow*cow;
	  //static Rabbit*rabbit;
	InstanceOfGameEntities* instanceOfGameEntities;

	Arena();
	~Arena();


	static Arena* Instance()
	{
		static Arena instance;

		return &instance;
	}
};

