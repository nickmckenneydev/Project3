#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>
struct SDLApplication {
	SDL_Window* mWindow;
	bool mGameRunning = true;
	SDLApplication(const char* title) {
		SDL_Init(SDL_INIT_VIDEO);
		mWindow = SDL_CreateWindow(title, 320, 240, SDL_WINDOW_RESIZABLE);
	}
	~SDLApplication() {//Destructor
		SDL_Quit();
	}
	void Tick() {//Loop One Iteration
		SDL_Event event;
			while (SDL_PollEvent(&event)) { //reading event from queue. Repop event
				//SDL_Log("KEYBOARD STATE %p and % d\n", keys,*keys);
				switch (event.type) {
				case SDL_EVENT_QUIT:
					mGameRunning = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					SDL_Log("We got a key event. :%d\n", event.key.key);
					if (event.key.key == 'q') {
						SDL_Log("We got a key event.");
						mGameRunning = false;
						SDL_Quit();
						break;
					}
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						SDL_Log("button left clicked %d", event.button.button);
					}
					if (event.button.button == SDL_BUTTON_MIDDLE)
					{
						SDL_Log("button middle clicked %d", event.button.button);
					}
					if (event.button.button == SDL_BUTTON_RIGHT)
					{
						SDL_Log("button right clicked %d", event.button.button);
					}
					SDL_Log("We got a mouse q event. :%d\n", event.button.clicks);
					break;
				default:
					SDL_Log("Unhandled Event!");
				
			}
			float x, y;
			SDL_MouseButtonFlags mouse = SDL_GetMouseState(&x, &y);
			SDL_Log("x,y: %f,%f", x, y);
		}
	}
	void MainLoop() {
		while (mGameRunning) {
			Tick();
		}
	}
};


int main(int argc,char* argv[])
{
	SDLApplication app("NICK NICK");
	app.MainLoop();
	return 0;
}

