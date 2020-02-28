#pragma once
#include <SDL_joystick.h>
#include <SDL.h>
class Joystick
{
public:
	Joystick();
	~Joystick();

	void init();
	void close();
	const int getDeadZone() { return JOYSTICK_DEAD_ZONE; };
	SDL_Joystick* getStick();

	int X() { return m_xDir; }; int Y() { return m_yDir; };
	void setX(int t_x) { m_xDir = t_x; }; void setY(int t_y) { m_yDir = t_y; };
private:
	const int JOYSTICK_DEAD_ZONE = 8000;
	SDL_Joystick* m_controller = NULL;

	int m_xDir=0, m_yDir=0;
};

