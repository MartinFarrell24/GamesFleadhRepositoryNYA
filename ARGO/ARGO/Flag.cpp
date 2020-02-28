#include "Flag.h"




Flag::Flag(SDL_Texture* t_flagTexture, SDL_Rect* t_flagRect, int entityID)
{
	m_flagTexture = t_flagTexture;
	m_flagRect = t_flagRect;
	m_flagActive = true;
	// assign entity stuff later like ID and components for velocity etc
}

Flag::~Flag()
{
}

void Flag::flagSetActive()
{
	m_flagActive = true;
}

void Flag::flagSetInactive()
{
	m_flagActive = false;
}

bool Flag::flagGetActive()
{
	return m_flagActive;
}
