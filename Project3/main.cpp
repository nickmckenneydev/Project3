#define SDL_MAIN_USE_CALLBACKS 1


#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	static SDL_Window* window;
	window = SDL_CreateWindow("wwwwww", 320, 240, SDL_WINDOW_RESIZABLE);
	SDL_Delay(5000);
	SDL_Quit();
	return 0;
}

