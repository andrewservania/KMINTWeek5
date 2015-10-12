#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"
#include "InstanceOfGameEntities.h"
//#include "SDL.h"


class Arena : public IGameObject
{
private:
	uint32_t instanceTimer;
	uint32_t instanceSeconds;
	uint32_t seconds;


	/* Start the timer; the callback below will be executed after the delay */
	//Uint32 delay;
	//SDL_TimerID my_timer_id;


	void ResetInstances();
	//Uint32 MyTimerCallBackFunc(Uint32 interval, void *param);
public:

	Arena();
	~Arena();

	void Update(float deltaTime) override;
	

	static Arena* Instance()
	{
		static Arena instance;

		return &instance;
	}

};

