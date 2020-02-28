#pragma once
#include"Command.h"

class UpCommand : public Command
{
private:
	std::string temp = "up";
public:
	virtual std::string execute();
};
