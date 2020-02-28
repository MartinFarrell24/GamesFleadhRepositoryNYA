#include "VelocityComponent.h"

VelocityComponent::VelocityComponent(Vector2 velocity)
{
	m_velocity = velocity;
}

void VelocityComponent::init()
{

}

void VelocityComponent::update()
{

}

void VelocityComponent::setVelocity(Vector2 velocity)
{
	m_velocity = velocity;
}

Vector2 VelocityComponent::getVelocity()
{
	return m_velocity;
}