#include "OctTree.h"

OctTree::OctTree()
{
}

OctTree::~OctTree()
{
}

void OctTree::initTree(Vector2 box1Pos, Vector2 boxSize)
{
	pos= box1Pos;
	
	size = boxSize;
}
