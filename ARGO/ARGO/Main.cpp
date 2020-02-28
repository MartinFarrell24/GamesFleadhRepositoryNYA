#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	int time = SDL_GetTicks();

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("FYP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;


		if (SDL_GetTicks() > time + 10)
		{
			time = SDL_GetTicks();
			game->subSystemUpdate();
		}

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}