#pragma once

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	State* getCurrent()
	{
		return current;
	}
	void idle();
	void moving();
	void pushing();
	void dying();
};
#include "AnimationStates.h"