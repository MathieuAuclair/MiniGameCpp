#include "Game.h"

Game *game = nullptr;

int main(int argc, const char * argv[]){
	//frame cap
	const int FrameRate = 60;
	//time between each frame (1000ms)
	const int frameDelay = 1000/FrameRate;

	Uint32 frameStart;
	int frameTime;
	
	game = new Game();
	game->init("Mini C++ Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 500, false);
	while(game->running()){

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	game->clean();
	return 0;
}
