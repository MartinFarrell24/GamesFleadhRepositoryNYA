#include"System.h"

System::System()
{
}

System::~System()
{
}

void System::movementUp()
{
	for (auto const& Entity : entityArr)
	{
		//move up
	}
}

void System::movementDown()
{
	for (auto const& Entity : entityArr)
	{
		//move down
	}
}

void System::movementLeft()
{
	for (auto const& Entity : entityArr)
	{
		//move left
	}
}

void System::movementRight()
{
	for (auto const& Entity : entityArr)
	{
		//move right
	}
}


void System::wallCol()
{
	for (auto const& Entity : entityArr)
	{
		for (auto const& Entity2 : entityArr)
		{
			//if (/*pos of Entity2==pos of Entity*/)
			//{

			//}
		}
	}
}
//void System::platformCollision()
//{
//
//}
