#include "Options.h"

Options::Options()
{
	m_backgroundRect = { 0,0, 3840/2, 2160/2 };
	m_backBtnRect = { 3200/2,1600/2, 500/2,500/2 };
	m_selectorRect = m_backBtnRect;
	loadedSurface = NULL;
	m_backgroundTexture = NULL;
	m_backBtnTexture = NULL;

	currentState = OptionsButtonState::optionsBackBtn;
	count = 0;
}

void Options::handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick)
{
	count++;
	switch (t_event.type)
	{
	case SDL_JOYBUTTONDOWN:
		if (SDL_JoystickGetButton(t_stick.getStick(), 1) != 0 && count > 30)
		{
			count = 0;
			switch (currentState)
			{
			case OptionsButtonState::optionsBackBtn:
				gamestate = GameState::mainMenu;
			default:
				break;
			}
		}
		break;

	default:
		break;
	}
}

void Options::update()
{
}

void Options::render(SDL_Renderer* t_renderer)
{
	loadSprites(t_renderer);
	SDL_RenderClear(t_renderer);
	SDL_RenderCopy(t_renderer, m_backgroundTexture, NULL, &m_backgroundRect);
	SDL_RenderCopy(t_renderer, m_backBtnTexture, NULL, &m_backBtnRect);
	if (m_hurtAchievementUnlocked)
	{
		SDL_RenderCopy(t_renderer, m_catHurtTexture, NULL, &m_catHurtPos);
	}
	if (m_swapStatesAchievementUnlocked)
	{
		SDL_RenderCopy(t_renderer, m_catStateTexture, NULL, &m_statesPos);
	}
	if (m_achievementCount > 0)
	{
		for (int i = 0; i < m_achievementCount; i++)
		{

			m_catAchievmentPos = { (400 + 400 * i)/2,260/2,400/2,400/2 };
			std::cout << "gotta draw cat " << i << std::endl;
			m_achievementCats.at(i) = SDL_CreateTextureFromSurface(t_renderer, m_catAchievementSurface);
			SDL_RenderCopy(t_renderer, m_achievementCats.at(i), NULL, &m_catAchievmentPos);

		}
	}
	SDL_RenderPresent(t_renderer);
}


void Options::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{
}

void Options::loadSprites(SDL_Renderer* renderer)
{
	if (m_backgroundTexture == NULL)
	{
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/options.bmp");
		m_backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/Back.bmp");
		m_backBtnTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		m_catAchievementSurface = SDL_LoadBMP("ASSETS/IMAGES/AchievmentCat.bmp");
		m_catAchievementHurt = SDL_LoadBMP("ASSETS/IMAGES/AchievmentCatCactus.bmp");
		m_catHurtTexture = SDL_CreateTextureFromSurface(renderer, m_catAchievementHurt);
		m_catAchievementStates = SDL_LoadBMP("ASSETS/IMAGES/AchievmentCatSwapStates.bmp");
		m_catStateTexture = SDL_CreateTextureFromSurface(renderer, m_catAchievementStates);
		
		SDL_FreeSurface(loadedSurface);
	}
}

void Options::setAchievementUnlocked(bool t_achievment)
{
	m_achievementUnlocked = t_achievment;
}

void Options::increaseAchievementCount(SDL_Renderer* t_renderer)
{
	m_achievementCount++;
	m_achievementCats.push_back(SDL_CreateTextureFromSurface(t_renderer, m_catAchievementSurface));
}

void Options::setCatHurtAchievement(bool t_hurt)
{
	m_hurtAchievementUnlocked = t_hurt;
}

void Options::setCatStateAchievement(bool t_hurt)
{
	m_swapStatesAchievementUnlocked = t_hurt;
}
