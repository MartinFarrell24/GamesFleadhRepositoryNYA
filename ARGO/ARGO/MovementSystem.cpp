#include "MovementSystem.h"

MovementSystem::MovementSystem()
{
}

MovementSystem::~MovementSystem()
{
}

Vector2 const MovementSystem::move(PositionComponent pos, std::string t_dir)
{
	Vector2 temp = pos.getPosition();
	float speedControl = 10.0f;//(MAX_TIME * 5)in sprite
	if (t_dir == "up")
	{
		temp = Vector2(temp.X(), temp.Y() - (60.0f / speedControl));
	}
	else if (t_dir == "left")
	{
		temp = Vector2(temp.X()- (60.0f / speedControl), temp.Y());
	}
	else if (t_dir == "right")
	{
		temp = Vector2(temp.X()+ (60.0f / speedControl), temp.Y());
	}
	else if (t_dir == "down")
	{
		temp = Vector2(temp.X(), temp.Y() + (60.0f / speedControl));
	}
	return temp;
}
