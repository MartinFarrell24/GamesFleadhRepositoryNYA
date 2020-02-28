#pragma once
#include "PositionComponent.h"
#include <string>
class MovementSystem
{
public:
	MovementSystem();
	~MovementSystem();
	
	Vector2 const move(PositionComponent pos, std::string t_dir);
	

private:
};

