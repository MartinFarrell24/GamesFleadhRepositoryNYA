#include "MainMenu.h"

MainMenu::MainMenu()
{
	m_backgroundRect = { 0,0, 3840/2, 2160/2 };
	m_playRect = { 1670/2,800/2,(100 * 5)/2,(38 * 5)/2 };
	m_optionsRect = { 1670/2,1100/2,(100 * 5)/2,(38 * 5)/2 };
	m_helpRect = { 1670/2,1400/2,(100 * 5)/2,(38 * 5)/2 };
	m_quitRect = { 1670/2,1700/2,(100 * 5)/2,(38 * 5)/2 };

	m_selectorRect = m_playRect;
	//m_selectorRect = { m_playRect.x,m_playRect.y,m_playRect.w,((m_playRect.h / 5) + 105) * 5 };
	loadedSurface = NULL;
	m_backgroundTexture = NULL;

	currentState = ButtonState::play;
	keyHeld = false;
	count = 0;
}

void MainMenu::handleEvents(SDL_Event& t_event, GameState& gamestate, Joystick t_stick)
{
	
	switch (t_event.type)
	{
	case SDL_JOYHATMOTION:
		if (SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_DOWN && count > 20)
		{
			count = 0;
			switch (currentState)
			{
			case ButtonState::play:
				currentState = ButtonState::optionsBTN;
				break;
			case ButtonState::optionsBTN:
				currentState = ButtonState::helpBTN;
				break;
			case ButtonState::helpBTN:
				currentState = ButtonState::quit;
				break;
			case ButtonState::quit:
				currentState = ButtonState::play;
				break;
			default:
				break;
			}
		}

		if (SDL_JoystickGetHat(t_stick.getStick(), 0) == SDL_HAT_UP && count > 20)
		{
			count = 0;
			switch (currentState)
			{
				case ButtonState::play:
					currentState = ButtonState::quit;
					break;
				case ButtonState::quit:
					currentState = ButtonState::helpBTN;
					break;
				case ButtonState::helpBTN:
					currentState = ButtonState::optionsBTN;
					break;
				case ButtonState::optionsBTN:
					currentState = ButtonState::play;
					break;
				default:
					break;
			}
		}
	case SDL_JOYBUTTONDOWN:
		if (SDL_JoystickGetButton(t_stick.getStick(), 0) != 0 && count > 30)
		{
			count = 0;
			switch (currentState)
			{
			case ButtonState::play:
				gamestate = GameState::gameplay;
				break;
			case ButtonState::optionsBTN:
				gamestate = GameState::options;
				break;
			case ButtonState::helpBTN:
				gamestate = GameState::help;
				break;
			case ButtonState::quit:
				quit = true;
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
}

void MainMenu::update()
{
	count++;
	switch (currentState)
	{
	case ButtonState::play:
		m_selectorRect = { m_playRect.x,m_playRect.y-5,m_playRect.w,((m_playRect.h / 5) + 7) * 5 };
		break;
	case ButtonState::optionsBTN:
		m_selectorRect = { m_optionsRect.x,m_optionsRect.y-5,m_optionsRect.w,((m_optionsRect.h / 5) +7) * 5 };
		break;
	case ButtonState::helpBTN:
		m_selectorRect = { m_helpRect.x,m_helpRect.y-5,m_helpRect.w,((m_helpRect.h / 5) + 7) * 5 };
		break;
	case ButtonState::quit:
		m_selectorRect = { m_quitRect.x,m_quitRect.y-5,m_quitRect.w,((m_quitRect.h / 5) + 7) * 5 };
		break;
	default:
		break;
	}
	
}

void MainMenu::render(SDL_Renderer* t_renderer)
{
	SDL_RenderClear(t_renderer);
	loadSprites(t_renderer);
	SDL_RenderCopy(t_renderer, m_backgroundTexture, NULL, &m_backgroundRect);
	SDL_RenderCopy(t_renderer, m_playTexture, NULL, &m_playRect);
	SDL_RenderCopy(t_renderer, m_optionsTexture, NULL, &m_optionsRect);
	SDL_RenderCopy(t_renderer, m_helpTexture, NULL, &m_helpRect);
	SDL_RenderCopy(t_renderer, m_quitTexture, NULL, &m_quitRect);
	SDL_RenderCopy(t_renderer, m_selectorTexture, NULL, &m_selectorRect);


	SDL_RenderPresent(t_renderer);
}


void MainMenu::clean(SDL_Renderer& t_renderer, SDL_Window& t_window)
{
}

void MainMenu::loadSprites(SDL_Renderer* renderer)
{
	if (m_backgroundTexture == NULL)
	{
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/mainmenu.bmp");
		m_backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/play.bmp");
		m_playTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/optionsBTN.bmp");
		m_optionsTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/help.bmp");
		m_helpTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/quit.bmp");
		m_quitTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/selector.bmp");
		m_selectorTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		
		SDL_FreeSurface(loadedSurface);

	}
}

bool MainMenu::quitState()
{
	return quit;
}




