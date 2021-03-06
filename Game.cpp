#include "Game.h"

//texture holder
SDL_Texture* characterTexture;
SDL_Rect  sourceRect, destinationRect;

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout <<"Subsystem Initionalised!"<< std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window){
			std::cout <<"Window created!"<< std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout <<"Renderer created!" << std::endl;
		}

		isRunning = true;

	}

	//process to include texture
	SDL_Surface* tmpSurface = IMG_Load("./character1.png");
	characterTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);	
	SDL_FreeSurface(tmpSurface);
	destinationRect.h = 64;
	destinationRect.w = 64;

}

void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update(){
	count++;

}

void Game::render(){
	SDL_RenderClear(renderer);
	//stuff to render here!
	SDL_RenderCopy(renderer, characterTexture, NULL, &destinationRect);

	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout <<"Game has been cleared!"<< std::endl;
}
