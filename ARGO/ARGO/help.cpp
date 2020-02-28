#include "help.h"

Help::Help()
{
	m_mainMenuTutorialRect = { 0, 0, 1200/2, 800/2 };
	m_movementTutorialRect = { 1300/2, 0, 1200/2, 800/2 };
	m_wordsUITutorialRect = { 0, 850/2, 1200/2, 800/2 };
	m_reverseTutorialRect = { 1300/2, 850/2, 1200/2, 800/2 };
	m_backgroundRect = { 0,0, 3840/2, 2160/2 };
	m_backBtnRect = { 3200/2,1600/2, 500/2,500/2 };
	m_selectorRect = m_backBtnRect;
	loadedSurface = NULL;
	m_backgroundTexture = NULL;
	m_backBtnTexture = NULL;
	m_selectorTexture = NULL;
	m_helpTexture = NULL;
	m_faceButtonTexture = NULL;

	currentState = HelpButtonState::helpBackBtn;
	count = 0;
}

void Help::handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick)
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
			case HelpButtonState::helpBackBtn:
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

void Help::update()
{
}

void Help::render(SDL_Renderer* t_renderer)
{
	loadSprites(t_renderer);
	SDL_RenderClear(t_renderer);
	SDL_RenderCopy(t_renderer, m_backgroundTexture, NULL, &m_backgroundRect);
	SDL_RenderCopy(t_renderer, m_helpTexture, NULL, &m_helpRect);
	SDL_RenderCopy(t_renderer, m_backBtnTexture, NULL, &m_backBtnRect);
	SDL_RenderCopy(t_renderer, m_selectorTexture, NULL, &m_selectorRect);
	/*SDL_RenderCopy(t_renderer, m_mainMenuTutorialTexture, NULL, &m_mainMenuTutorialRect);
	SDL_RenderCopy(t_renderer, m_mainMenuTutorialTexture, NULL, &m_mainMenuTutorialRect);
	SDL_RenderCopy(t_renderer, m_wordsUITutorialTexture, NULL, &m_wordsUITutorialRect);
	SDL_RenderCopy(t_renderer, m_reverseTutorialTexture, NULL, &m_reverseTutorialRect);
	SDL_RenderCopy(t_renderer, m_movementTutorialTexture, NULL, &m_movementTutorialRect);*/
	SDL_RenderCopy(t_renderer, m_faceButtonTexture, NULL, &m_faceButtonRect);

	SDL_RenderPresent(t_renderer);
}

void Help::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{
}

void Help::loadSprites(SDL_Renderer* renderer)
{
	if (m_backgroundTexture == NULL)
	{
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/helpTutorialBackground.bmp");
		m_backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/Back.bmp");
		m_backBtnTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/MainMenuTutorial.bmp");
		m_mainMenuTutorialTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/MovementTutorial.bmp");
		m_movementTutorialTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/WordsUITutorial.bmp");
		m_wordsUITutorialTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/ReverseTutorial.bmp");
		m_reverseTutorialTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/helpScreen.bmp");
		m_helpTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/AFaceButton.bmp");
		m_faceButtonTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);
	}
}
