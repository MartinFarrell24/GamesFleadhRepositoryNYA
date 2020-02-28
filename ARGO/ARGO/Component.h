#pragma once

class Entity;

class Component
{
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual ~Component() = 0;
	Entity* entity;
private:

};
#include "Entity.h"