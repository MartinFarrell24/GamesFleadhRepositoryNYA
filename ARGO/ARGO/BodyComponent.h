#pragma once

#include "Component.h"
#include "Vector2.h"
class BodyComponent : public Component
{
public:
	BodyComponent();
	~BodyComponent();
	BodyComponent(Vector2 size);
	Vector2 getSize();
	void setSize(Vector2 size);
	void init() override;
	void update() override;
	void render() override;
	
private:
	Vector2 m_size;
};