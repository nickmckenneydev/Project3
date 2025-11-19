#define SDL_MAIN_USE_CALLBACKS 1


#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>

SDL_Window* window;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		return SDL_APP_FAILURE;
	}
	window = SDL_CreateWindow("wwwwww", 320, 240, SDL_WINDOW_RESIZABLE);
	/*if (!window) {
		SDL_GetError();
	}*/
	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate)
{
		SDL_Delay(5000);
		return SDL_APP_CONTINUE;
}
	
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
	SDL_Quit();
}
