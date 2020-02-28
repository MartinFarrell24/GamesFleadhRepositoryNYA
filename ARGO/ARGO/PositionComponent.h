#pragma once

#include "Component.h"
#include "Vector2.h"
#include <stack>
class PositionComponent : public Component
{
public:
	PositionComponent();
	~PositionComponent();
	PositionComponent(Vector2 position);
	Vector2 getPosition();
	void setPosition(Vector2 position);
	void setPreviousPosition(Vector2 position);
	Vector2 getPreviousPosition();
	void setToPreviousPos();
	bool isEmpty();
	void init() override;
	void update() override;
	void render() override;
	int getStackSize();
	void resetStack();
	void popPreviousPosition();
	void popAllPositions();
	void completeReset();
	const int MAX_STACKSIZE = 256;
private:
	Vector2 m_position;
	std::stack<Vector2> m_prevPositions;
	
};

