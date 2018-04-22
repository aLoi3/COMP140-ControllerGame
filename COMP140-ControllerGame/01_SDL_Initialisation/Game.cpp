 // 01SDLInitialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>

const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

Game::Game()
{
	serialInterface = new SerialInterface();
}

Game::~Game()
{
}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, int flags)
{
	// initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success \n";

		// Create a window
		mainWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if window succesful..
		if (mainWindow != 0) {
			std::cout << "Window creation success \n";

			// create renderer
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);

			// if renderer successful...
			if (mainRenderer != 0) {
				std::cout << "Renderer creation success \n";
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
			}
			else {
				std::cout << "renderer failed \n";
				return false;
			}
		}
		else {
			std::cout << "window failed \n";
			return false;
		}

	}
	else {
		std::cout << "SDL fail \n";
		return false;
	}

	isRunning = true;
	std::cout << "SDL init success \n";

	return true;
}

void Game::render()
{
	// set background color
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);

	// clear previous frame
	SDL_RenderClear(mainRenderer);

	// render new frame
	SDL_RenderPresent(mainRenderer);
}

/*
* update - Process all variables !in charge of anything to do with rendering
*
*/
void Game::update()
{
	serialInterface->getPositions();
}

/*
* handleEvents - Poll Events and uses switch case to process specific events
*
*/
void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDLK_l:
			std::cout << "Welcome on board, Sir! (Press E to continue) \n";
		case SDLK_e
			std::cout << "I greet You at the very best game on the universe. (Press T to continue) \n";
		case SDLK_t
			std::cout << "Even thought there are much more games that are superior. (Press S to continue) \n";
		case SDLK_s
			std::cout << "And this is totally not a game, but, after all, this is something, right? (Press G to continue) \n";
		case SDLK_g
			std::cout << "Okay, I'll stop chatting with you, so you can enjoy this 'the very best game'! (Press O to finally start it) \n";
		case SDLK_o
			std::cout << "A random number has been chosen, \n";
			std::cout << "Rotate the sphere to find the spot where all LEDs will turn GREEN. \n";

		default:
			break;
		}

	}
}

/*
* clean - Clean up SDL and close the port
*
*/
void Game::clean()
{
	serialInterface->close();

	std::cout << "Cleaning SDL \n";
	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(mainRenderer);
	SDL_Quit();
}


/*int main(int argc, char ** argsv)
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

	//SDL_Surface * ImageSurface = IMG_Load("Assets\Images\SeaImage.jpg");
	//SDL_Texture * SeaImageTexture = SDL_CreateTextureFromSurface(Renderer, ImageSurface);
	//SDL_FreeSurface(ImageSurface);

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

		//SDL_RenderCopy(Renderer, SeaImageTexture, &sourceRect, &destinationRect);

		SDL_RenderPresent(Renderer);

	}

	//SDL_DestroyTexture(SeaImageTexture);

	SDL_DestroyRenderer(Renderer);

	SDL_DestroyWindow(Window);
	IMG_Quit();
	SDL_Quit();

    return 0;
}*/

