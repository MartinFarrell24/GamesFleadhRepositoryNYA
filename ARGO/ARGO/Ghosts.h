#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
class Ghost
{
public:
	Ghost();
	void setUp(SDL_Renderer* t_screen);
	int posUpdate(std::string t_pos, int t_mainPlayerNum);
	void update(int* t_mainPlayerNum);
	void render(int t_currentPlayerNum);
	void reset(int t_leftPlayer, int* t_mainPlayerNum);
	const static int MAX_GHOSTS = 10;
	int playerGhost = 0;
private:
	SDL_Renderer* m_screen;
	SDL_Surface* m_loadedSurface;
	SDL_Texture* m_texture;
	SDL_Rect dstrect[MAX_GHOSTS];
	SDL_Rect srcrect[MAX_GHOSTS];
	std::vector<SDL_Rect>dstrect2;
	std::vector<int>ghostsSignal;
};