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
	textDestination.x = 0;
	textDestination.y = 0;
	textDestination.h = 100;
	textDestination.w = 600;
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
				//SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
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
	//SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
	//SDL_RenderDrawRect(greeting, );

	// clear previous frame
	SDL_RenderClear(mainRenderer);

	greeting = Text(mainRenderer, "Text/Greetings.png", 72, 341);
	//SDL_RenderClear(mainRenderer);
	SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);

	//greeting = Text(mainRenderer, "Text/Greetings1.png", 72, 341);
	
	if (greeting.getTexture() != nullptr)
		SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);

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

			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_l:
				greeting = Text(mainRenderer, "Text/Greetings1.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";

			}

			switch (event.key.keysym.sym)
			{
			case SDLK_e:
				greeting = Text(mainRenderer, "Text/Greetings2.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_t:
				greeting = Text(mainRenderer, "Text/Greetings3.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_s:
				greeting = Text(mainRenderer, "Text/Greetings4.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_g:
				greeting = Text(mainRenderer, "Text/Greetings5.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_o:
				greeting = Text(mainRenderer, "Text/Greetings6.png", 72, 341);
				SDL_RenderClear(mainRenderer);
				SDL_RenderCopy(mainRenderer, greeting.getTexture(), NULL, &textDestination);
				std::cout << "Welcome on board, Sir! (Press E to continue) \n";
			}

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