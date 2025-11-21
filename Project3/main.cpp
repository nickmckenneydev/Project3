#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>
int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	static SDL_Window* window;
	window = SDL_CreateWindow("wwwwww", 320, 240, SDL_WINDOW_RESIZABLE);

	
	
	bool game_is_still_running = true;
	SDL_Event event;
	SDL_Scancode scanCode;
	SDL_zero(event);//init event quieie
	const bool *keys = SDL_GetKeyboardState(nullptr);//Return a pointer to an internal managed array

	while (game_is_still_running) {

		while (SDL_PollEvent(&event)) { //reading event from queue. Repop event
			SDL_Log("KEYBOARD STATE %p and %d\n", keys,*keys);
			switch (event.type) {
			case SDL_EVENT_KEY_DOWN:
				if (event.key.key == 'q') {
					SDL_Log("We got a key event.");
					game_is_still_running = false;
					SDL_Quit();
					break;
				}
			
				SDL_Log("We got a key event. :%d\n",event.key.key);
					
				

			default:
				if (keys[15] == true) {
					SDL_Log("Unhandled Event!");
				}
			}
		}
	}
	
	return 0;
}

