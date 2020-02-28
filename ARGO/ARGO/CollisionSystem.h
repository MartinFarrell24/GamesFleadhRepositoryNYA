#ifndef COLLISIONSYSTEM
#define COLLISIONSYSTEM
#include "PositionComponent.h"
#include "BodyComponent.h"
class CollisionSystem
{

public:
	CollisionSystem();
	~CollisionSystem();

	bool const collides(const PositionComponent & t_pos1, const BodyComponent& t_body1, const PositionComponent & t_pos2, const BodyComponent & t_body2);
private:
	bool m_isColliding;
};
#endif	// !COLLISIONSYSTEM

