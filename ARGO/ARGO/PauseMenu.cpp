#include "PauseMenu.h"
#include <fstream>
#include <sstream>
#include <iostream>
PauseMenu::PauseMenu()
{
	m_lockValue = NUM_OF_BOXES;
	m_rulesChanged = false;
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::init()
{
	loadedSurfaceBack = SDL_LoadBMP("ASSETS/IMAGES/pauseBack.bmp");
	loadedSurfaceObj = SDL_LoadBMP("ASSETS/IMAGES/objects.bmp");
	loadedSurfaceAdjecUnlock = SDL_LoadBMP("ASSETS/IMAGES/adjectivesUnlocked.bmp");
	loadedSurfaceAdjecLock = SDL_LoadBMP("ASSETS/IMAGES/adjectivesLocked.bmp");
	loadedSurfaceSelect = SDL_LoadBMP("ASSETS/IMAGES/selector.bmp");
	loadedSurfaceSelect2 = SDL_LoadBMP("ASSETS/IMAGES/selected.bmp");
	loadedSurfaceNotRewind= SDL_LoadBMP("ASSETS/IMAGES/pauseUnselect.bmp");
	loadedSurfaceRewind= SDL_LoadBMP("ASSETS/IMAGES/pauseSelect.bmp");
	selectBox[0] = Vector2(1200/2, 1860/2);
	selectBox[1] = Vector2(selectBox[0].X()+120, 1900/2);
	selectBox[2] = Vector2(selectBox[0].X() +240,selectBox[0].Y());
	selectBox[3] = Vector2(selectBox[0].X() + 360,selectBox[1].Y());
	selectBox[4] = Vector2(selectBox[0].X() +480,selectBox[0].Y());
	rewindBox = Vector2(selectBox[0].X(), selectBox[0].Y() + 75);
	/*selectBox[5] = Vector2(1200, 1900);
	selectBox[6] = Vector2(selectBox[0].X() + 240, 1900);
	selectBox[7] = Vector2(selectBox[0].X() + 480, selectBox[0].Y());
	selectBox[8] = Vector2(selectBox[0].X() + 720, selectBox[1].Y());
	selectBox[9] = Vector2(selectBox[0].X() + 960, selectBox[0].Y());*/
	
	for (int box = 0; box < NUM_OF_BOXES; box++)
	{
		boxSelected[box] = false;
		if(box%2==0)
			srcrect[box] = { 0, srcrect[box].y, 60, 60 };
		else
			srcrect[box] = { 60, srcrect[box].y, 60, 60 };
		boxRectSliced[box] = { int(selectBox[box].X()), int(selectBox[box].Y()), srcrect[box].w, 60 };
	}
	dstrectBack = { 0, 900, 1920, 180 };
	rect = { int(rewindBox.X()+240),int(rewindBox.Y()),60,60 };
	currentBox = 0;
	m_slectOffset = Vector2(5, 5);
	dstrectSelect = { int(selectBox[currentBox].X() - m_slectOffset.x), int(selectBox[currentBox].Y() - m_slectOffset.y), 62, 85 };
	//dstrectSelect2 = { int(selectBox[currentBox].X()- (m_slectOffset.x/2)), int(selectBox[currentBox].Y()- (m_slectOffset.y / 2)), 125, 124 };
	boxSelected[0] = true;
}

void PauseMenu::input(SDL_Event& t_event, Joystick t_stick)
{
	if (timer == MAX_TIME)
	{
		if (SDL_JoystickGetButton(t_stick.getStick(), 0) != 0)
		{
			for (int box = 0; box < NUM_OF_BOXES; box++)
			{
				if (box <= m_lockValue)
				{
					
					if (dstrectSelect.x + m_slectOffset.x == selectBox[box].X() && dstrectSelect.y + m_slectOffset.y == selectBox[box].Y())
					{
						if (!boxSelected[box])
						{
							boxSelected[box] = true;
							m_swappedStates = true;
							forAllTexture = m_textureObj;
							for (int box2 = 0; box2 < NUM_OF_BOXES; box2++)
							{
								if (boxSelected[box] == boxSelected[box2] && box != box2)
								{
									boxSelected[box2] = false;
								}
							}
						}
						else if (boxSelected[box])
						{
							boxSelected[box] = false;
							forAllTexture = m_textureAdjecUnlock;
						}
						else
						{
							for (int box2 = 1; box2 < NUM_OF_BOXES; box2 += 2)
							{
								if (boxSelected[box2])
								{
									float tempCut = srcrect[box2].y;
									srcrect[box2].y = srcrect[box].y;
									srcrect[box].y = tempCut;
									forAllTexture = m_textureObj;
									boxSelected[box2] = false;
									m_rulesChanged = true;
								}
							}
						}
						if (box == m_lockValue)
						{
							forAllTexture = m_textureRewind;
						}
						timer = 0;
					}
				}
			}
		}
		resetALittle = false;
		ResetAll = false;
		
		forAllTexture = m_textureNotRewind;
		if (currentBox >= m_lockValue)
		{
			currentBox = 0;
			for (int box = 0; box < NUM_OF_BOXES; box++)
			{
				boxSelected[box] = false;
			}
		}
		if (SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_RIGHT)
		{
			currentBox += 2;
			timer = 0;
			if (currentBox >= m_lockValue)
			{
				currentBox -= m_lockValue;
			}
			/*if (boxSelected[currentBox])
			{
				currentBox += 2;
			}*/
			if (currentBox >= m_lockValue)
			{
				currentBox -= m_lockValue;
			}
		}
		else if (SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_LEFT)
		{
			currentBox -= 2;
			timer = 0;
			if (currentBox < 0)
			{
				currentBox += m_lockValue;
			}
			/*if (boxSelected[currentBox])
			{
				currentBox -= 2;
			}*/
			if (currentBox < 0)
			{
				currentBox += m_lockValue;
			}
		}
		else if (SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_UP )
		{
			ResetAll = true;
			forAllTexture = m_textureRewind;
		}
		else if(SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_DOWN)
		{
			resetALittle = true;
			forAllTexture = m_textureRewind;
		}
		
		dstrectSelect = { int(selectBox[currentBox].X() - m_slectOffset.x), int(selectBox[currentBox].Y() - m_slectOffset.y), dstrectSelect.w, dstrectSelect.h };
		/*if (!anyActive())
		{
			dstrectSelect2 = { int(selectBox[currentBox].X() - (m_slectOffset.x / 2)), int(selectBox[currentBox].Y() - (m_slectOffset.x / 2)), dstrectSelect2.w, dstrectSelect2.h };
		}*/
		
	}
}

void PauseMenu::update()
{
	if (timer < MAX_TIME)
	{
		timer++;
	}
	rewindBox=selectBox[m_lockValue];
}

void PauseMenu::render(SDL_Renderer*& t_renderer)
{
	if (m_textureBack == NULL)
	{
		m_textureBack = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceBack);
	}
	SDL_RenderCopy(t_renderer, m_textureBack, NULL, &dstrectBack);

	if (m_textureObj == NULL)
	{
		m_textureObj = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceObj);
	}

	if (m_textureAdjecUnlock == NULL)
	{
		m_textureAdjecUnlock = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceAdjecUnlock);
	}
	if (m_textureAdjecLock == NULL)
	{
		m_textureAdjecLock = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceAdjecLock);
	}
	if (m_textureRewind == NULL)
	{
		m_textureRewind = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceRewind);
	}
	if (resetALittle||ResetAll)
	{
		m_textureRewind = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceRewind);
		

	}
	else
	{
		m_textureRewind = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceNotRewind);
	}
	
	for (int box = NUM_OF_BOXES-1; box >= 0; box--)
	{
		
		if (boxSelected[box] )
		{
			forAllTexture = m_textureObj;
		}
		else if (!boxSelected[box])
		{
			forAllTexture = m_textureAdjecUnlock;
		}
		if(box >= m_lockValue)
		{
			forAllTexture = NULL;
		}
		
		
		
		SDL_RenderCopy(t_renderer, forAllTexture, &srcrect[box], &boxRectSliced[box]);
	}
	if (m_textureSelect == NULL)
	{
		m_textureSelect = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceSelect);
	}
	if (m_textureSelect2 == NULL)
	{
		m_textureSelect2 = SDL_CreateTextureFromSurface(t_renderer, loadedSurfaceSelect2);
	}
	SDL_RenderCopy(t_renderer, m_textureSelect, NULL, &dstrectSelect);
	if (anyActive())
	{
		SDL_RenderCopy(t_renderer, m_textureSelect2, NULL, &dstrectSelect2);	
	}
	
	
	SDL_RenderCopy(t_renderer, m_textureRewind, NULL, &rect);
}

bool PauseMenu::anyActive()
{
	bool isAnyActive = false;
	for (int box = 0; box < NUM_OF_BOXES&& !isAnyActive; box++)
	{
		if (boxSelected[box])
		{
			isAnyActive = true;
		}
	}
	return isAnyActive;
}

int PauseMenu::getTime()
{
	return timer;
}

void PauseMenu::resetTime()
{
	timer = 0;
}

std::vector<std::string> PauseMenu::getChanges()
{
	std::vector<std::string> rules;
	for (int box = 0; box < NUM_OF_BOXES; box += 2)
	{
		/*if (boxSelected[box])
		{
			rules.push_back("player");
		}
		else
		{
			rules.push_back("stop");
		}*/
		if (srcrect[box].y == 0)
		{
			rules.push_back("cat");
		}
		else if (srcrect[box].y == 60)
		{
			rules.push_back("clock");
		}
		else if(srcrect[box].y == 120)
		{
			rules.push_back("platform");
		}
		else if (srcrect[box].y == 180)
		{
			rules.push_back("flag");
		}
		else
		{
			rules.push_back("cactus");
		}
		if (boxSelected[box])
		{
			rules.push_back("player");
		}
		else if (box<6)
		{
			rules.push_back("stop");
		}
		else if (srcrect[box + 1].y == 120)
		{
			rules.push_back("move");
		}
		else if (srcrect[box + 1].y == 60)
		{
			rules.push_back("goal");
		}
		else
		{
			rules.push_back("spiky");
		}
	}

	return rules;
}

void PauseMenu::setRules(int t_levelNum)
{
	std::ifstream myfile("ASSETS/MAP/level" + std::to_string(t_levelNum) + ".txt");
	std::string currentText = "";
	getline(myfile, currentText, ':');
	int currentBox = 0;
	while (getline(myfile, currentText, '-'))
	{
		setUIRules(currentBox, currentText);
		if (currentText == "lock")
		{
			m_lockValue = currentBox;
			currentBox -= 2;
		}
		currentBox++;
		getline(myfile, currentText, ',');
		setUIRules(currentBox, currentText);
		currentBox++;
	}
}

void PauseMenu::setUIRules(int t_index, std::string t_type)
{
	if (t_type == "cat" || t_type == "player")
		srcrect[t_index].y = 0;
	else if (t_type == "clock" || t_type == "goal")
		srcrect[t_index].y = 60;
	else if (t_type == "platform" || t_type == "stop")
		srcrect[t_index].y = 120;
	else if (t_type == "flag" || t_type == "move")
		srcrect[t_index].y = 180;
	else if (t_type == "cactus" || t_type == "spiky")
		srcrect[t_index].y = 240;
}

void PauseMenu::botSwitch()
{
	boxSelected[currentBox] = false;
	currentBox += 2;
	timer = 0;
	if (currentBox >= m_lockValue)
	{
		currentBox=0;
	}
	/*if (boxSelected[currentBox])
	{
		currentBox += 2;
	}*/
	
	boxSelected[currentBox] = true;
}
