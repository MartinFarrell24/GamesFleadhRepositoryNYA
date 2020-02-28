#pragma once
#include "Component.h"
#include "Vector2.h"
#include <string>
class Wall : public Component
{
public:
	Wall();
	~Wall();
	void init() override;
	void update();
private:
	Vector2 m_pos;
	std::string tag="Wall";
};