#pragma once
#include "Vector2.h"

class OctTree
{
public:
	OctTree();
	~OctTree();

	//There will be 6 sections.
	void initTree(Vector2 box1Pos, Vector2 boxSize);
	
	Vector2 getOct(int t_arrayPos) { return pos; };
	Vector2 getSize() { return size; };
private:
	Vector2 pos;
	Vector2 size;
};

