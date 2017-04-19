#include "SDL2/SDL.h"
#include <string>

SDL_Window* window;
SDL_Renderer* renderer;

const int WINDOW_WIDTH = 1250;
const int WINDOW_HEIGHT = 700;

void InitDisplay()
{
	window = NULL;
	renderer = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
		"I HAV A SHANK LOL",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Exit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* args[])
{
	InitDisplay();

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WINDOW_WIDTH;
	rect.h = WINDOW_HEIGHT;

	const std::string path = "xd.bmp";
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(path.c_str()));
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_RenderPresent(renderer);
	SDL_Delay(8000);

	SDL_DestroyTexture(texture);

	Exit();
	return 0;
}
