#define SDL_MAIN_USE_CALLBACKS 1


#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>
#include <SDL3/SDL_events.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	static SDL_Window* window;
	window = SDL_CreateWindow("wwwwww", 320, 240, SDL_WINDOW_RESIZABLE);

	SDL_Event event;
	SDL_zero(event);//init event quieie
	event.type = event.key;
	while (SDL_PollEvent(&event)) { //reading event from queue
		switch (event.type) {
		case SDL_EVENT_KEY_DOWN:
			SDL_Quit();
		default:
			SDL_Log("Unhandled Event!");
			break;
		}
		return SDL_APP_CONTINUE;
	}

	
	return 0;
}

