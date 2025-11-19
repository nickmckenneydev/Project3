#define SDL_MAIN_USE_CALLBACKS 1


#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>

	SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]);


	SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event);
	SDL_AppResult SDL_AppIterate(void* appstate);
	void SDL_AppQuit(void* appstate, SDL_AppResult result);
