#pragma once
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Gamestate.h"
#include "Joystick.h"

enum HelpButtonState
{
	helpBackBtn
};

class Help
{
public:
	Help();
	void handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick);
	void update();
	void render(SDL_Renderer* t_renderer);
	void clean(SDL_Renderer& t_renderer, SDL_Window& t_window);
	void loadSprites(SDL_Renderer* renderer);
private:
	SDL_Surface* loadedSurface;
	SDL_Texture* m_backgroundTexture;
	SDL_Texture* m_backBtnTexture;
	SDL_Texture* m_mainMenuTutorialTexture;
	SDL_Texture* m_movementTutorialTexture;
	SDL_Texture* m_reverseTutorialTexture;
	SDL_Texture* m_wordsUITutorialTexture;
	SDL_Texture* m_helpTexture;
	SDL_Texture* m_faceButtonTexture;
	SDL_Texture* m_selectorTexture;
	SDL_Rect m_backgroundRect;
	SDL_Rect m_backBtnRect;
	SDL_Rect m_selectorRect;
	SDL_Rect m_mainMenuTutorialRect;
	SDL_Rect m_movementTutorialRect;
	SDL_Rect m_reverseTutorialRect;
	SDL_Rect m_wordsUITutorialRect;
	SDL_Rect m_helpRect;
	SDL_Rect m_faceButtonRect;

	HelpButtonState currentState;
	int count;
};

