#include "Joystick.h"

Joystick::Joystick()
{
}

Joystick::~Joystick()
{
}

void Joystick::init()
{
	if (SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		//error
	}
	if (SDL_NumJoysticks() < 1)
	{
		//less than one controller
	}
	else
	{
		m_controller = SDL_JoystickOpen(0); 
		if (m_controller == NULL)
		{
			//Error opening controller
		}
	}
}

void Joystick::close()
{
	SDL_JoystickClose(m_controller);
	m_controller = NULL;
}

SDL_Joystick* Joystick::getStick()
{
	return m_controller;
}
