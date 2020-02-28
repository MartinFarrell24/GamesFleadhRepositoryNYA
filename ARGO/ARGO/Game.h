#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Gamestate.h"
#include "LevelState.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "BodyComponent.h"
#include "EntityManager.h"
#include "Intro.h"
#include "Splash.h"
#include "Licence.h"
#include "help.h"
#include "MainMenu.h"
#include "Gameplay.h"
#include "Options.h"
#include "Credits.h"
#include "Joystick.h"
#include "MovementSystem.h"
#include "AudioComponent.h"
#include "Factory.h"
#include "BotComponent.h"
#include "Gameplay.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void subSystemUpdate();
	void render();
	void clean();

	

	bool running() { return isRunning; }
	static GameState m_currentMode;
	int m_currentLevel;

	SDL_Renderer* m_renderer;
	SDL_Event m_event;
private:
	bool botMode = false;
	bool botSwitch = false;
	bool isRunning;
	SDL_Window* m_window;
	Splash m_splashScr;
	Licence m_licence;
	MainMenu m_mainMenuScr;
	Gameplay m_gamePlayScr;
	Options m_optionsScr;
	Credits m_creditsScr;
	Help m_helpScr;
	Intro m_intro;
	Joystick stick;
	bool keyTest = false;
	bool temp = false;
	bool m_gotAchievment = false;

	float m_timer = 0.0f;
	float m_frames = 1.0f / 60.0f;
	


	
	Entity* m_cat;
	Factory* m_factory = new CharacterFactory();
	std::vector<Character*> m_characterVectorArray;

	
	

	bool initialiseOnce = false;
	bool m_initialiseLevelFour = false;

	Entity*  entArr[5];

	/// <summary>
	/// Systems
	/// </summary>
	MovementSystem m_moveSys;
	std::vector<std::string> answer;

	void initEnts(Entity &t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, bool t_botMode);

	void updateEnts(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, bool t_botMode);
	std::string lastString;
	bool botPresent=true;
	int  currBiggestStack=0;
	bool firstRun = false;
};
