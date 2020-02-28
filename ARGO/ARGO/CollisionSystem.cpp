#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
	m_isColliding = false;
}

CollisionSystem::~CollisionSystem()
{
}

bool const CollisionSystem::collides(const PositionComponent& t_pos1, const BodyComponent& t_body1, const PositionComponent& t_pos2, const BodyComponent& t_body2)
{
	PositionComponent tempPos1 = t_pos1, tempPos2 = t_pos2;
	BodyComponent tempBod1 = t_body1, tempBod2 = t_body2;

	
	if (tempPos1.getPosition().x + tempBod1.getSize().x > tempPos2.getPosition().x && tempPos1.getPosition().x < tempPos2.getPosition().x + tempBod2.getSize().x &&
		tempPos1.getPosition().y + tempBod1.getSize().y > tempPos2.getPosition().y && tempPos1.getPosition().y < tempPos2.getPosition().y + tempBod2.getSize().y)
	{
		// there will be an if statement here to check if an entity has a "stop" component to check if the previous position should be set for it or it should be moved
		
		m_isColliding = true;
	}
	else
	{
		m_isColliding = false;
	}
	return m_isColliding;
}


