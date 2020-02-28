#pragma once
#include<vector>
#include"Entity.h"
#include "PositionComponent.h"
#include "BodyComponent.h"
class System
{
public:
	System();
	~System();

	void movementUp();
	void movementDown();
	void movementLeft();
	void movementRight();

	void wallCol();
private:
	Entity entityArr[100];//Is this the best place for this?

};
