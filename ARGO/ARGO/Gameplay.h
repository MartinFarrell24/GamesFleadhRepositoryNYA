#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Map.h"
#include "PauseMenu.h"
#include "Joystick.h"
#include "EntityManager.h"
#include "Gamestate.h"
#include "OctTree.h"
#include "CollisionSystem.h"
#include "ClientStuff/Client.h"
#include "MainMenu.h"
#include "Ghosts.h"
#include<string>

class Gameplay
{
public:
	Gameplay();

	void init(SDL_Renderer*& t_renderer);
	void handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick, int t_levelNum);
	void update();
	void render(SDL_Renderer *&t_renderer,EntityManager& t_entMan);

	void clean(SDL_Renderer*& t_renderer, SDL_Window* t_window);
	std::vector<std::string> getChanges();
	Map* getMap();
	std::vector<Vector2> getMapCorners();
	void fixedUpdate(EntityManager& t_entMan);
	int getCurrentLevel() { return newLevel; }
	bool getSwappedStates();
	void updatePositions(std::vector<Vector2> t_pos);
	void setHurtByCactus(bool t_cactus);
	PauseMenu& getPause() { return m_pauseMenu; };
	void addToLevelCount() { m_levelCount++; m_passLevel = true; }
	PauseMenu getPauseMenu(){ return m_pauseMenu; };
private:
	Map m_map;
	PauseMenu m_pauseMenu;
	int timer;
	OctTree m_OTree;
	int row, col,maxRow,maxCol;
	void setupRowCol(int t_row, int t_col, int t_MaxRow, int t_MaxCol);
	CollisionSystem gameplayCol;
	SDL_Surface* m_loadedSurfaceBack;
	SDL_Texture* m_textureBack;
	Client myClient;
	int playerNum = 1;
	std::string mess = "";
	int newLevel = 0;
	bool m_stateSwapped = false;
	bool m_hurtByCactus = false;
	bool m_passLevel = false;
	Ghost m_ghosts;
	float m_timeTracker = 1.f / 60.f;
	float m_statesAchTimer = 0.f;
	float m_deathAchTimer = 0.f;
	float m_levelPassTimerAch = 0.f;
	float m_achDisplayTime = 1.5f;
	SDL_Surface* m_catAchDisplayHurt;
	SDL_Texture* m_dispCatHurtAch;
	SDL_Surface* m_catAchDisplayStates;
	SDL_Texture* m_dispCatStatesAch;
	SDL_Surface* m_catAchPassLevel;
	SDL_Texture* m_dispPassLevel;
	SDL_Rect m_promptAchievementPos = { 50,50,400,200 };
	int m_levelCount = 0;
	std::string m_IPAddr;
	bool m_gameplayLeft, m_gameover;
};