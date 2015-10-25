#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"
#include "InstanceOfGameEntities.h"
#include "SDL_timer.h"
#include "GeneticAlgorithm.h"

class Arena
{
private:

	uint32_t seconds;
	int runs;
	bool applicationEnd;

	std::shared_ptr<InstanceOfGameEntities> instance1;
	std::shared_ptr<InstanceOfGameEntities> instance2;
	std::shared_ptr<InstanceOfGameEntities> instance3;
	std::shared_ptr<InstanceOfGameEntities> instance4;
	std::shared_ptr<GeneticAlgorithm> geneticAlgorithm;

	void InitializeInstance1();
	void InitializeInstance2();
	void InitializeInstance3();
	void InitializeInstance4();

	void ResetInstances();
	void EndProgram();
public:

	Arena();
	~Arena();
	void SecondTick();
};
