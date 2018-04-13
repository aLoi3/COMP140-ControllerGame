 // 01SDLInitialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

int main(int argc, char ** argsv)
{
	SDL_Window * Window = nullptr;
	SDL_Renderer * Renderer = nullptr;

	bool isRunning = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Can't initialise SDL" << SDL_GetError() << std::endl;
		return -1;
	}

	int imgFlag = IMG_INIT_PNG | IMG_INIT_JPG;
	int imgFlagResults = IMG_Init(imgFlag);
	if (imgFlagResults != imgFlag)
	{
		std::cout << "Can't load in PNG and JPG support, we can use BMPs" << IMG_GetError() << std::endl;

	}

	Window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (Window == nullptr)
	{
		std::cout << "Can't create window" << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if (Renderer == nullptr)
	{
		std::cout << "Can't create renderer" << SDL_GetError() << std::endl;
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return -1;
	}

	SDL_Surface * ImageSurface = IMG_Load("Assets\Images\SeaImage.jpg");
	SDL_Texture * SeaImageTexture = SDL_CreateTextureFromSurface(Renderer, ImageSurface);
	SDL_FreeSurface(ImageSurface);

	SDL_Rect sourceRect;
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 860;
	sourceRect.h = 640;

	SDL_Rect destinationRect;
	destinationRect.x = 100;
	destinationRect.y = 100;
	destinationRect.w = 16;
	destinationRect.h = 16;

	SDL_Event currentEvent;

	while (isRunning)
	{
		while (SDL_PollEvent(&currentEvent))
		{
			switch (currentEvent.type)
			{
				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
			}
		}

		// Game stuff
		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		SDL_RenderClear(Renderer);

		SDL_RenderCopy(Renderer, SeaImageTexture, &sourceRect, &destinationRect);

		SDL_RenderPresent(Renderer);

	}

	SDL_DestroyTexture(SeaImageTexture);

	SDL_DestroyRenderer(Renderer);

	SDL_DestroyWindow(Window);
	IMG_Quit();
	SDL_Quit();

    return 0;
}

