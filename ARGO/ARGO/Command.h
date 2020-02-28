#pragma once
#include"Joystick.h"
#include<iostream>
class Command
{
public:
	virtual ~Command() {}
	virtual std::string execute() = 0;
};
