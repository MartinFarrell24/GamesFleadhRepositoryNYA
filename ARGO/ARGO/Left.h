#pragma once
#include"Command.h"

class LeftCommand : public Command
{
private:
	std::string temp = "left";
public:
	virtual std::string execute()
	{
		
		return temp;
	};
};
