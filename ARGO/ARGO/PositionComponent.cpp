#include "PositionComponent.h"

PositionComponent::PositionComponent()
{
}

PositionComponent::~PositionComponent()
{
}

PositionComponent::PositionComponent(Vector2 position)
{
	m_position = position;
}

void PositionComponent::init()
{

}

void PositionComponent::update()
{
	
}

void PositionComponent::render()
{
}

int PositionComponent::getStackSize()
{
	int varToRet = m_prevPositions.size();
	return varToRet;
}
void PositionComponent::resetStack()
{
	while (!m_prevPositions.empty())
	{
		m_prevPositions.pop();
	}
}
void PositionComponent::popPreviousPosition()
{
	if(!m_prevPositions.empty())
	{
		
		m_prevPositions.pop();
	}
}

void PositionComponent::popAllPositions()
{
	while(!m_prevPositions.empty())
	{

		m_prevPositions.pop();
	}
}

void PositionComponent::completeReset()
{
	while(!m_prevPositions.empty())
	{
		m_position = m_prevPositions.top();
		m_prevPositions.pop();
	}
}

void PositionComponent::setPosition(Vector2 position)
{
	m_position = position;
}

void PositionComponent::setPreviousPosition(Vector2 position)
{
	//if (m_prevPositions.size< MAX_STACKSIZE)
	//{
		m_prevPositions.push(position);
	//}
	

}

Vector2 PositionComponent::getPreviousPosition()
{
	if (!m_prevPositions.empty())
	{
		return m_prevPositions.top();
	}
	else
	{
		return m_position;
	}
	
}

void PositionComponent::setToPreviousPos()
{
	if (!m_prevPositions.empty())
	{
		m_position = m_prevPositions.top();
		m_prevPositions.pop();
	}
	
}

bool PositionComponent::isEmpty()
{
	return m_prevPositions.size() == 0;
}

Vector2 PositionComponent::getPosition()
{
	return m_position;
}
