#pragma once
#include"Command.h"

class RightCommand : public Command
{
private:
	std::string temp = "right";
public:
	virtual std::string execute()
	{
		
		return temp;
	};
};
