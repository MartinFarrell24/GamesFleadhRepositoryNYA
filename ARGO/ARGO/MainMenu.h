#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Gamestate.h"
#include "Joystick.h"

enum ButtonState
{
	play,
	optionsBTN,
	helpBTN,
	quit
};

class MainMenu
{
public:
	MainMenu();
	void handleEvents(SDL_Event& t_event, GameState &gamestate, Joystick t_stick);
	void update();
	void render(SDL_Renderer* t_renderer);
	void clean(SDL_Renderer& t_renderer, SDL_Window& t_window);
	void loadSprites(SDL_Renderer* renderer);
	static const int MAX_TIME = 20;
	bool quitState();
private:
	SDL_Surface* loadedSurface;
	SDL_Texture* m_backgroundTexture;
	SDL_Texture* m_playTexture;
	SDL_Texture* m_optionsTexture;
	SDL_Texture* m_helpTexture;
	SDL_Texture* m_quitTexture;
	SDL_Texture* m_selectorTexture;
	SDL_Rect m_backgroundRect;
	SDL_Rect m_playRect;
	SDL_Rect m_optionsRect;
	SDL_Rect m_helpRect;
	SDL_Rect m_quitRect;
	SDL_Rect m_selectorRect;
	bool quit = false;
	

	ButtonState currentState;
	bool keyHeld;
	int count;
	
};