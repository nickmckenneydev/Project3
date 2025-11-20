#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	static SDL_Window* window;
	window = SDL_CreateWindow("wwwwww", 320, 240, SDL_WINDOW_RESIZABLE);

	
	
	bool game_is_still_running = true;

	while (game_is_still_running) {
		SDL_Event event;
		
		SDL_zero(event);//init event quieie
		while (SDL_PollEvent(&event)) { //reading event from queue. Repop event
			switch (event.type) {
			case SDL_EVENT_KEY_DOWN:
				if (event.key.key == 'q') {
					SDL_Log("We got a key event.");
					game_is_still_running = false;
					SDL_Quit();
					break;
				}
			default:
				SDL_Log("Unhandled Event!");
			}
			SDL_Log("Event queue empty.");
			//return SDL_APP_CONTINUE;
		}
	}
	
	return 0;
}

