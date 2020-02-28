#include "BoundarySystem.h"

BoundarySystem::BoundarySystem()
{
}

BoundarySystem::~BoundarySystem()
{
}

Vector2 BoundarySystem::hitBoundary(PositionComponent t_pos, BodyComponent t_body, Vector2 t_mapTopLeft, Vector2 t_mapBottomRight)
{
	Vector2 newPosition = t_pos.getPosition();
	if (t_pos.getPosition().x < t_mapTopLeft.x)
		newPosition = Vector2(t_mapTopLeft.x, newPosition.y);
	else if(t_pos.getPosition().x + t_body.getSize().x > t_mapBottomRight.x)
		newPosition = Vector2(t_mapBottomRight.x - t_body.getSize().x, newPosition.y);
	else if(t_pos.getPosition().y < t_mapTopLeft.y)
		newPosition = Vector2(newPosition.x,t_mapTopLeft.y);
	else if(t_pos.getPosition().y + t_body.getSize().y > t_mapBottomRight.y )
		newPosition = Vector2(newPosition.x,t_mapBottomRight.y - t_body.getSize().y);

	return newPosition;
}
