#include <SDL3/SDL.h>
#include <string>
struct SDLApplication {//state is global to my application
	SDL_Window* mWindow;
	bool mGameRunning = true;
	unsigned int lastTime = 0;
	SDL_Surface* mSurface;
	SDL_Renderer* mRenderer;
	SDL_Event event;
	SDL_FRect fillRet;
	int color;
	int color2;
	float x, y;
	SDLApplication(const char* title) {//constructor
		SDL_Init(SDL_INIT_VIDEO);
		mWindow = SDL_CreateWindow(title, 320, 240, SDL_WINDOW_RESIZABLE);
		
		mRenderer = SDL_CreateRenderer(mWindow, "opengl");
		if (mRenderer == nullptr)
		{

		}
		else {
			SDL_Log("Renderer is %s: ",SDL_GetRendererName(mRenderer));
			SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255); 
			SDL_RenderClear(mRenderer);
			for (int i = 0; i < SDL_GetNumRenderDrivers(); i++)
			{
				SDL_Log("%d. %s", i + i, SDL_GetRenderDriver(i));
			}
			SDL_Delay(5000);
		}

	
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
		
			while (SDL_PollEvent(&event)) { //reading event from queue. Repop event
				//SDL_Log("KEYBOARD STATE %p and % d\n", keys,*keys);
				switch (event.type) {
				case SDL_EVENT_QUIT:
					mGameRunning = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					SDL_Log("We got a key event. :%d\n", event.key.key);
					if (event.key.key == 'b') {
						color = event.key.key;
						color = color * 10;
					}
					if (event.key.key == 'q') {
						SDL_Log("We got a key event.");
						mGameRunning = false;
						SDL_Quit();
						break; 
					}
				case SDL_EVENT_MOUSE_MOTION:
					color = event.motion.x;
					color2 = event.motion.y;
				
				default:
					SDL_Log("Unhandled Event!");
					
			}
		
			SDL_MouseButtonFlags mouse = SDL_GetMouseState(&x, &y);
			
		}
	}
	void Update(){}
	void Render(){
		SDL_Log("x,y %f %f", x, y);
		SDL_SetRenderDrawColor(mRenderer, y, x, 0, 255); 
		SDL_RenderPoint(mRenderer, x, y);
		SDL_RenderPresent(mRenderer);
	
	}
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

