#pragma once
#include"Command.h"

class DownCommand : public Command
{
private:
	std::string temp = "down";
public:
	virtual std::string execute()
	{
		
		return temp;
	};
};
