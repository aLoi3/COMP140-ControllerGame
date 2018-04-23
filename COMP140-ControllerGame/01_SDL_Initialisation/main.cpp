#include "stdafx.h"
#include "SDL.h"
#include "Game.h"
#include <iostream>


Game* game = 0;


int main(int argc, char* argv[])
{
	// new game instance
	game = new Game();

	// initialise the game
	game->init("SDL Serial", 100, 100, 640, 480, 0);

	std::cout << "Press L to start... \n";

	// create a game loop
	while (game->running()) {

		// choose a framerate - in this case we are using 1000%40 which means 
		// 25 frames per second (quite slow)
		int increment = SDL_GetTicks() % 40;

		// if modulo returns 0 trigger one frame in our game
		if (increment == 0) {

			game->handleEvents();
			game->update();
			game->render();

		}
	}

	// when the game ends clean SDL and Serial
	game->clean();

	return 0;
}
