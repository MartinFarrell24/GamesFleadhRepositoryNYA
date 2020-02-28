#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Gamestate.h"
#include "Joystick.h"
#include <vector>

enum OptionsButtonState
{
	optionsBackBtn
};

class Options
{
public:
	Options();
	void handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick);
	void update();
	void render(SDL_Renderer* t_renderer);
	void clean(SDL_Renderer& t_renderer, SDL_Window& t_window);
	void loadSprites(SDL_Renderer* renderer);
	void setAchievementUnlocked(bool t_achievment);
	bool getAchievementUnlocked() { return m_achievementUnlocked; }
	void increaseAchievementCount(SDL_Renderer* t_renderer);
	int getAchievementCount() { return m_achievementCount; }
	void setCatHurtAchievement(bool t_hurt);
	void setCatStateAchievement(bool t_hurt);
private:
	SDL_Surface* loadedSurface;
	SDL_Texture* m_backgroundTexture;
	SDL_Texture* m_backBtnTexture;
	SDL_Rect m_backgroundRect;
	SDL_Rect m_backBtnRect;
	SDL_Rect m_selectorRect;

	OptionsButtonState currentState;
	int count;

	std::vector<SDL_Texture*> m_achievementCats;
	SDL_Surface* m_catAchievementSurface;
	SDL_Texture* m_catHurtTexture;
	SDL_Surface* m_catAchievementHurt;
	SDL_Surface* m_catAchievementStates;
	SDL_Texture* m_catStateTexture;
	
	bool m_achievementUnlocked = false;
	bool m_hurtAchievementUnlocked = false;
	bool m_swapStatesAchievementUnlocked = false;
	int m_achievementCount = 0;
	
	SDL_Rect m_catAchievmentPos;
	SDL_Rect m_catHurtPos = { 500, 475, 200,200 };
	SDL_Rect m_statesPos = { 500,1650/2,200,200 };

};