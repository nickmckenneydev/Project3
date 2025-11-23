#include <SDL3/SDL.h>
#include <string>
#include <vector>
struct Particles {
	struct Particle {
		float speed;
		float velocity;
		void Randomize() {
			speed = 1.0f + static_cast<float>(SDL_rand(10));
			velocity = 1.0f+static_cast<float>(SDL_rand(180));
		}
	};
	std::vector<SDL_FPoint> mPoints;
	std::vector<Particle> mParticles;

	Particles(size_t numberOfPoints) {
		for (int i = 0; i < numberOfPoints; i++) {
			Particle particle;
			particle.Randomize();
			SDL_FPoint point = SDL_FPoint{
				static_cast<float>(SDL_rand(320)),
				static_cast<float>(SDL_rand(10))-120,
			};
			mParticles.push_back(particle);
			mPoints.push_back(point);
		}
	}
};
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
	Particles mParticleSystem{ 10000 };
	SDLApplication(const char* title) { //constructor
		SDL_Init(SDL_INIT_VIDEO);
		mWindow = SDL_CreateWindow(title, 320, 240, SDL_WINDOW_RESIZABLE);
		mRenderer = SDL_CreateRenderer(mWindow, "opengl");
		if (mRenderer == nullptr)
		{
		}
		else {
			SDL_Log("Renderer is %s: ",SDL_GetRendererName(mRenderer));
			
			for (int i = 0; i < SDL_GetNumRenderDrivers(); i++)
			{
				SDL_Log("%d. %s", i + i, SDL_GetRenderDriver(i));
			}
			SDL_SetRenderLogicalPresentation(mRenderer,320,240, SDL_LOGICAL_PRESENTATION_STRETCH);
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
	void Update(){
		for (int i = 0; i < mParticleSystem.mParticles.size(); i++) {
			mParticleSystem.mPoints[i].y += mParticleSystem.mParticles[i].speed * .01f;
			mParticleSystem.mPoints[i].x += SDL_sinf(mParticleSystem.mParticles[i].velocity) * .5f;
			mParticleSystem.mParticles[i].velocity += 0.1f;
			if (mParticleSystem.mPoints[i].y > 240) {
				
				mParticleSystem.mParticles[i].Randomize();
				mParticleSystem.mPoints[i].y = -120;
			}
			
		}
	}
	void Render(){
		SDL_Log("x,y %f %f", x, y);
		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 255);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 255);
		SDL_RenderPoints(mRenderer, mParticleSystem.mPoints.data(), mParticleSystem.mParticles.size());
		SDL_RenderPresent(mRenderer);
	
	}
	void MainLoop() {
		Uint64 fps = 0;
		while (mGameRunning) {
			Uint64 currentTick = SDL_GetTicks();
			Tick();
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

