#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include "Animation.h"
#include "AnimationStates.h"
enum PlayerStates
{
	IdlePlayer,
	MovingPlayer,
	PushingPlayer,
	DyingPlayer
};
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	void resetSprite();
	void setPathAndScreen(std::string path, SDL_Renderer* t_screen, bool t_anime = false);
	void setPosAndSize(int x, int y, int width, int height);
	void updateState(PlayerStates t_newState);
	PlayerStates getCurrentState();
	bool finishedAnime();
	bool isCat();
	void init() override;
	void update() override;
	void render() override;

	static const int MAX_TIME = 2;//MovementSystem::move
private:
	std::vector< std::string> m_paths;
	std::vector <SDL_Surface*> loadedSurface;
	std::vector<SDL_Texture*> m_texture;
	SDL_Renderer* m_screen;
	int m_width;
	int m_height;
	int m_x;
	int m_y;
	int xOffset;
	int yOffset;
	int timer;
	int m_animed;
	int m_currentTex;
	PlayerStates m_currentState;
	Animation m_animeStates;
};