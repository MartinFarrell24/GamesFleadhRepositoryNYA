#include "Licence.h"

Licence::Licence()
{
	m_x = 0;
	m_y = 0;
	m_width = 3840/2;
	m_height = 2160/2;
	loadedSurface = NULL;
	m_texture = NULL;
	m_count = 0;
	loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/Licence.bmp");
}

void Licence::handleEvents(SDL_Event& t_event, GameState& gamestate)
{
	switch (t_event.type)
	{
	case SDL_JOYBUTTONDOWN:
		gamestate = GameState::mainMenu;
		break;
	default:
		break;
	}
}

void Licence::update(GameState& gamestate)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		
	}
}

void Licence::render(SDL_Renderer* t_renderer)
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

void Licence::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{
}
