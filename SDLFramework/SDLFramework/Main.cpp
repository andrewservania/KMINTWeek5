#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include <ctime>
#include "AStar.h"
#include "Arena.h"
#include "Dashboard.h"
#include "SDL_timer.h"
#include <memory>

Uint32 delay = 1000; // ms
SDL_TimerID myTimerID;
std::shared_ptr<Arena> arena;

Uint32 MyCallBackFunc(Uint32 interval, void *param)
{
	arena->SecondTick();
	return interval;
}


int main(int args[])
{
	

	srand(static_cast<unsigned int>(time(nullptr)));						// initialize random seed

	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	arena = std::make_shared<Arena>();
	auto dashboard = new Dashboard();										// To show some statistics such as shortestPath, Cow state and rabbit state

	myTimerID = SDL_AddTimer(delay, MyCallBackFunc, nullptr);
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:

				switch (event.key.keysym.sym){
				case SDLK_0:

					break;

				default:

					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			}
		}

		application->SetColor(Color(0, 0, 0, 255));							// White color
		dashboard->Update();
		// For the background
		application->SetColor(Color(255, 255, 255, 255));					// Black color
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	return EXIT_SUCCESS;
}



