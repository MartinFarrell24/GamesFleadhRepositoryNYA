#ifndef FLAG
#define FLAG
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include "VelocityComponent.h"
#include "Sprite.h"
#include "PositionComponent.h"
#include "Entity.h"

class Flag
{
public:
	Flag(SDL_Texture * t_flagTexture, SDL_Rect * t_flagRect, int entityID);
	~Flag();
	void flagSetActive();
	void flagSetInactive();
	bool flagGetActive();

private:
	SDL_Rect* m_flagRect;
	SDL_Texture *m_flagTexture;
	Vector2 m_position;
	Vector2 m_velocity;
	bool m_flagActive;
	
};
#endif //!FLAG
