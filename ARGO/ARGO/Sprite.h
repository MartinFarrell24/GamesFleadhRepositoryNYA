#pragma once
#include <iostream>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
class Sprite
{
public:
	Sprite();
	bool loadFromFile(std::string path, SDL_Renderer* t_screen);
	void setRect(int x, int y, int width, int height);
	void render(int x, int y, SDL_Renderer*& t_screen);

	SDL_Surface* loadedSurface;
	SDL_Texture* m_texture;
	SDL_Rect fullRect;
	int m_width;
	int m_height;
};