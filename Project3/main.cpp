#include <SDL3/SDL.h>
#include <string>
struct SDLApplication {//state is global to my application
	SDL_Window* mWindow;
	bool mGameRunning = true;
	unsigned int lastTime = 0;
	SDLApplication(const char* title) {
		SDL_Init(SDL_INIT_VIDEO);
		mWindow = SDL_CreateWindow(title, 320, 240, SDL_WINDOW_RESIZABLE);
	}
	~SDLApplication() {//Destructor
		SDL_Quit();
	}
	void Tick() {
		Input();
		Update();
		Render();
	}
	void Input() {//Loop One Iteration
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
				
				default:
					SDL_Log("Unhandled Event!");
				
			}
			float x, y;
			SDL_MouseButtonFlags mouse = SDL_GetMouseState(&x, &y);
			SDL_Log("x,y: %f,%f", x, y);
		}
	}
	void Update(){}
	void Render(){}
	void MainLoop() {
		Uint64 fps = 0;
		while (mGameRunning) {
			Uint64 currentTick = SDL_GetTicks();
			Tick();
			SDL_Delay(16);
			fps ++;
			
			Uint64 deltaTime = SDL_GetTicks() -currentTick;
			if (currentTick > lastTime + 1000) {
				lastTime = currentTick;
			
				std::string title;
				title += "Nicks - FPS: " + std::to_string(fps);
				SDL_SetWindowTitle(mWindow, title.c_str());
				fps = 0;
			}
		}
	}
};

int main(int argc,char* argv[])
{
	SDLApplication app("NICK NICK");
	app.MainLoop();
	return 0;
}

