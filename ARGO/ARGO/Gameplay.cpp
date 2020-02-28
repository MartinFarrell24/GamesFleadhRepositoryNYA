#include "Gameplay.h"
#include <fstream>
#include <sstream>
Gameplay::Gameplay() :


	myClient("149.153.106.148", 1111)//149.153.106.148

{
	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
	}
	mess = "";
	m_IPAddr = "";
	m_gameplayLeft = false;
	m_gameover = false;
}

void Gameplay::init(SDL_Renderer*& t_renderer)
{
	m_catAchDisplayHurt = SDL_LoadBMP("ASSETS/IMAGES/CactusAchievement.bmp");
	m_dispCatHurtAch = SDL_CreateTextureFromSurface(t_renderer, m_catAchDisplayHurt);
	m_catAchDisplayStates = SDL_LoadBMP("ASSETS/IMAGES/StatesAchievement.bmp");
	m_dispCatStatesAch = SDL_CreateTextureFromSurface(t_renderer, m_catAchDisplayStates);
	m_catAchPassLevel = SDL_LoadBMP("ASSETS/IMAGES/LevelCompleteGeneric.bmp");
	m_dispPassLevel = SDL_CreateTextureFromSurface(t_renderer, m_catAchPassLevel);
	m_map.init(t_renderer,1);
	m_map.setLevelNum(1);

	m_pauseMenu.setRules(m_map.getLevelNum());
	std::string temp = "ASSETS/IMAGES/level" + std::to_string(m_map.getLevelNum()) + "back.bmp";
	m_loadedSurfaceBack = SDL_LoadBMP(temp.c_str());
	m_textureBack = SDL_CreateTextureFromSurface(t_renderer, m_loadedSurfaceBack);
	m_pauseMenu.init();
	timer = 0;
	m_OTree.initTree(Vector2(0, 0), Vector2(960/2, 1080/2));

	m_ghosts.setUp(t_renderer);
}

void Gameplay::handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick,int t_levelNum)
{
	if (m_gameover && t_levelNum == 5)
	{
		gamestate = GameState::credits;
		m_gameplayLeft = true;
		m_gameover = false;
	}
	if (SDL_JoystickGetButton(t_stick.getStick(), 6) != 0 )
	{
		gamestate = GameState::mainMenu;
		m_gameplayLeft = true;
		//m_gameover = false;

	}
	
	m_pauseMenu.input(t_event, t_stick);
}

void Gameplay::update()
{
	m_pauseMenu.update();
	m_ghosts.update(&playerNum);
	m_ghosts.posUpdate(mess, playerNum);

	if (myClient.isMessage)
	{
		myClient.isMessage = false;
		if (m_ghosts.posUpdate(myClient.newMessage, playerNum) == playerNum)
		{
			playerNum++;
		}
	}
	std::istringstream input;
	input.str(mess);
	std::string message = "";
	std::getline(input, message, ':');
	if (std::stoi(message) == playerNum)
	{
		myClient.SendString(mess);
	}

	if (m_IPAddr == "")
	{
		m_IPAddr = myClient.GetIPAddr();
	}
}

void Gameplay::render(SDL_Renderer*& t_renderer, EntityManager& t_entMan)
{
	 newLevel = t_entMan.handleWin(m_map.getLevelNum());
	 if (newLevel > 5)
		 m_gameover = true;
	 if (m_gameplayLeft)
		newLevel = 1;
	if (m_map.getLevelNum() != newLevel || m_gameplayLeft)
	{
		m_gameplayLeft = false;
		m_map.init(t_renderer,newLevel);
		m_pauseMenu.setRules(m_map.getLevelNum());
		std::string temp = "ASSETS/IMAGES/level" + std::to_string(m_map.getLevelNum()) + "back.bmp";
		m_loadedSurfaceBack = SDL_LoadBMP(temp.c_str());
		m_textureBack = SDL_CreateTextureFromSurface(t_renderer, m_loadedSurfaceBack);
	}
	SDL_Rect dstrect = { 60, 60, m_map.getMapCorners().at(1).x-60,  m_map.getMapCorners().at(1).y-60};

	SDL_RenderCopy(t_renderer, m_textureBack, NULL, &dstrect);


	for (int j=0; j < 15; j++)
	{
		for (int i=0; i < 32; i++)
		{
			m_map.render(t_renderer, i, j);
			Vector2 temp(60, 60);

		}
	}
	m_pauseMenu.render(t_renderer);
	m_ghosts.render(playerNum);
	if (m_hurtByCactus)
	{
		if (m_deathAchTimer <= m_achDisplayTime)
		{
			SDL_RenderCopy(t_renderer, m_dispCatHurtAch, NULL, &m_promptAchievementPos);
		}
		m_deathAchTimer += m_timeTracker;
	}
	if (m_stateSwapped)
	{
		if (m_statesAchTimer <= m_achDisplayTime)
		{
			SDL_RenderCopy(t_renderer, m_dispCatStatesAch, NULL, &m_promptAchievementPos);
		}
		m_statesAchTimer += m_timeTracker;
	}
	if (m_passLevel)
	{
		if (m_levelPassTimerAch <= m_achDisplayTime)
		{
			SDL_RenderCopy(t_renderer, m_dispPassLevel, NULL, &m_promptAchievementPos);
		}
		else
		{
			m_passLevel = false;
			m_levelCount++;
			m_levelPassTimerAch = 0;
		}
		m_levelPassTimerAch += m_timeTracker;
	}
}

void Gameplay::clean(SDL_Renderer*& t_renderer, SDL_Window* t_window)
{
}


std::vector<std::string> Gameplay::getChanges()
{
	return m_pauseMenu.getChanges();
}

Map* Gameplay::getMap()
{
	return &m_map;
}

std::vector<Vector2> Gameplay::getMapCorners()
{
	return m_map.getMapCorners();
}

void Gameplay::fixedUpdate(EntityManager& t_entMan)
{
	Vector2 PlayerPos = t_entMan.getPlayerPos();

	int xVal, yVal, wVal, hVal;
	xVal = (PlayerPos.X() - 240/2) / 60;
	yVal = (PlayerPos.Y() - 240/2) / 60;
	wVal = (PlayerPos.X() + 360/2) / 60;
	hVal = (PlayerPos.Y() + 360/2) / 60;
	if (xVal < 0)
	{
		xVal = 0;
	}
	if (yVal < 0)
	{
		yVal = 0;
	}
	if (wVal > 32)
	{
		wVal = 32;
	}
	if (hVal > 15)
	{
		hVal = 15;
	}
	setupRowCol(yVal, xVal, hVal, wVal);
	bool updateCalled = false;
	for (int j = row; j < maxRow; j++)
	{
		for (int i = col; i < maxCol; i++)
		{
			if (!updateCalled)
			{
				t_entMan.update(yVal, xVal, hVal, wVal);
				updateCalled = true;
			}
			if (m_map.tile[i][j].getWall())
			{
				Vector2 temp(60, 60);
				t_entMan.mapCol(m_map.tile[i][j].vec, temp);
			}
		}
	}
}

bool Gameplay::getSwappedStates()
{
	m_stateSwapped = m_pauseMenu.getStatesSwapped();
	return m_stateSwapped;
}

void Gameplay::updatePositions(std::vector<Vector2> t_pos)
{
	mess = std::to_string(playerNum) + ":Cat-" + std::to_string(int(t_pos.at(0).x)) + "," + std::to_string(int(t_pos.at(0).y)) + ","
		+ "Clock-" + std::to_string(int(t_pos.at(1).x)) + "," + std::to_string(int(t_pos.at(1).y)) + ","
		+ "Book-" + std::to_string(int(t_pos.at(2).x)) + "," + std::to_string(int(t_pos.at(2).y)) + ","
		+ "Flag-" + std::to_string(int(t_pos.at(3).x)) + "," + std::to_string(int(t_pos.at(3).y)) + ","
		+ "Cactus-" + std::to_string(int(t_pos.at(4).x)) + "," + std::to_string(int(t_pos.at(4).y)) + ",";
}

void Gameplay::setHurtByCactus(bool t_cactus)
{
	m_hurtByCactus = t_cactus;
}

void Gameplay::setupRowCol(int t_row, int t_col, int t_MaxRow,int t_MaxCol)
{
	row = t_row;
	col = t_col;
	maxRow = t_MaxRow;
	maxCol = t_MaxCol;
}
