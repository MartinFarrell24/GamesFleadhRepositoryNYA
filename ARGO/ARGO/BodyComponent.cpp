#include "BodyComponent.h"

BodyComponent::BodyComponent()
{
}

BodyComponent::~BodyComponent()
{
}

BodyComponent::BodyComponent(Vector2 size)
{
	m_size = size;
}

Vector2 BodyComponent::getSize()
{
	return m_size;
}

void BodyComponent::setSize(Vector2 size)
{
	m_size = size;
}

void BodyComponent::init()
{
}

void BodyComponent::update()
{
}

void BodyComponent::render()
{
}
