#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>
int main(int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Failed!");
		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow("HIIII", 320, 240, SDL_WINDOW_RESIZABLE|SDL_WINDOW_BORDERLESS);
	SDL_Delay(5000);
	SDL_Quit();

	return 0;
}