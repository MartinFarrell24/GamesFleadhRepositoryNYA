#include "Splash.h"

Splash::Splash()
{
	m_x = 0;
	m_y = 0;
	m_width = 3840/2;
	m_height = 2160/2;
	loadedSurface = NULL;
	m_texture = NULL;
	m_count = 0;
	loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/splash.bmp");
}

void Splash::handleEvents(SDL_Event& t_event)
{
	switch (t_event.type)
	{
	case SDL_KEYDOWN:
		if (t_event.key.keysym.sym == SDLK_ESCAPE)
		{


		}
		break;
	default:
		break;
	}
}

void Splash::update(GameState& gamestate)
{
	m_count++;

	if (m_count > 240)
	{
		gamestate = GameState::licence;
	}
}

void Splash::render(SDL_Renderer* t_renderer)
{
	SDL_RenderClear(t_renderer);
	SDL_Rect dstrect = { m_x, m_y, m_width, m_height };
	if (m_texture == NULL)
	{
		m_texture = SDL_CreateTextureFromSurface(t_renderer, loadedSurface);
	}
	SDL_RenderCopy(t_renderer, m_texture, NULL, &dstrect);
	SDL_RenderPresent(t_renderer);
}


void Splash::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{

}
