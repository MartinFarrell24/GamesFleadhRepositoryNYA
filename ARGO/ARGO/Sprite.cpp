#include "Sprite.h"

Sprite::Sprite()
{
	m_texture = NULL;
	m_width = 50;
	m_height = 50;
}

bool Sprite::loadFromFile(std::string path, SDL_Renderer* t_screen)
{
	loadedSurface = SDL_LoadBMP(path.c_str());
	m_texture = SDL_CreateTextureFromSurface(t_screen, loadedSurface);
	if (m_texture == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Sprite::setRect(int x, int y, int width, int height)
{
	fullRect = { x,y,width,height };
}

void Sprite::render(int x, int y, SDL_Renderer*& t_screen)
{
	SDL_Rect dstrect = { x,y, m_width, m_height };
	SDL_RenderCopy(t_screen, m_texture, NULL, &dstrect);
}
