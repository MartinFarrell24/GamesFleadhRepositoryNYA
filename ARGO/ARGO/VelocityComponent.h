#pragma once
#include "Component.h"
#include "Vector2.h"

class VelocityComponent : public Component
{
public:
	VelocityComponent(Vector2 velocity);
	Vector2 getVelocity();
	void setVelocity(Vector2 velocity);
	void init() override;
	void update() override;
private:
	Vector2 m_velocity;
};

