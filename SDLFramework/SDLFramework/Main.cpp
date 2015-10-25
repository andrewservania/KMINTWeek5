#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include <ctime>
#include "Arena.h"
#include "Dashboard.h"
#include "SDL_timer.h"
#include <memory>

/// <summary>	delay threshold of 1000ms. Used to determine 1 (one) second when the timer starts. </summary>
Uint32 delay = 1000;
/// <summary>	Identifier for my timer. </summary>
SDL_TimerID myTimerID;
/// <summary>	The arena. </summary>
std::shared_ptr<Arena> arena;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Timer call back function. </summary>
///
/// A function that is called every second.
/// Used in order to create a timer on screen.
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="interval">	The interval. </param>
/// <param name="param">   	[in,out] If non-null, the parameter. </param>
///
/// <returns>	An Uint32. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

Uint32 MyCallBackFunc(Uint32 interval, void *param)
{
	arena->SecondTick();
	return interval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Main entry-point for this application. </summary>
///
///  Initialize SDL, the arena, the dashboard and all game entities.
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="args">	Number of command-line arguments. </param>
///
/// <returns>	Exit-code for the process - 0 for success, else an error code. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

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
	auto dashboard = new Dashboard();

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