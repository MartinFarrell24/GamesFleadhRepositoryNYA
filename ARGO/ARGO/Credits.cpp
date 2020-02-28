#include "Credits.h"

Credits::Credits()
{
	m_x = 1250/2;
	m_y = 2100/2;
	m_width = 1500/2;
	m_height = 1000/2;
	loadedSurface = NULL;
	m_texture = NULL;
	m_count = 0;
	loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/credits.bmp");
}

void Credits::handleEvents(SDL_Event& t_event)
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

void Credits::update()
{
	m_y--;
}

void Credits::render(SDL_Renderer* t_renderer)
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


void Credits::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{
}
