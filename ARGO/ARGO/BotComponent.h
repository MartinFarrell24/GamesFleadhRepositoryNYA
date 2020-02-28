#pragma once
#include <SDL_mixer.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include "Component.h"
class BotComponent : public Component
{
public:
	BotComponent();
	~BotComponent();
	void init() override;
	void update() override;
	void render() override;

	void setFakeStickX(int t_fakeStickX) { m_fakeStickX = t_fakeStickX; };
	void setFakeStickY(int t_fakeStickY) { m_fakeStickY = t_fakeStickY; };
	int getFakeStickX() { return m_fakeStickX; };
	int getFakeStickY() { return m_fakeStickY; };
	bool getBotMode() { return botMode; };
	void setBotMode(bool t_mode) { botMode = t_mode; };
	bool AButtonPress() { return selectA; };
	bool moveRight() { return goRight; };

private:
	bool botMode = true;
	int m_fakeStickX = 0, m_fakeStickY=0;
	bool selectA = false, goRight = false;
};
