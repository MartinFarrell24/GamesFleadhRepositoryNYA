#pragma once
#include <SDL.h>
#include "Vector2.h"
#include "Joystick.h"
#include <vector>
#include <string>
class PauseMenu
{
public:
	PauseMenu();
    ~PauseMenu();
	void init();
	void input(SDL_Event& t_event, Joystick t_stick);
	void update();
	void render(SDL_Renderer*& t_renderer);
	bool anyActive();
	int getTime();
	void resetTime();
	std::vector<std::string> getChanges();
	void setRules(int t_levelNum);
	void setUIRules(int t_index,std::string t_type);
	void otherUIRules(std::string t_rules);
	bool getStatesSwapped() { return m_swappedStates; }
	
	static const int MAX_TIME = 30;
	bool getRewindALittle() { return resetALittle; };
	bool getRewindALot() { return ResetAll; };
	void botSwitch();
private:
	SDL_Surface* loadedSurfaceBack;
	SDL_Surface* loadedSurfaceObj;
	SDL_Surface* loadedSurfaceAdjecUnlock;
	SDL_Surface* loadedSurfaceAdjecLock;
	SDL_Surface* loadedSurfaceSelect;
	SDL_Surface* loadedSurfaceSelect2;
	SDL_Surface* loadedSurfaceRewind;
	SDL_Surface* loadedSurfaceNotRewind;
	SDL_Texture* m_textureBack;
	SDL_Texture* m_textureObj;
	SDL_Texture* m_textureAdjecUnlock;
	SDL_Texture* m_textureAdjecLock;
	SDL_Texture* m_textureSelect;
	SDL_Texture* m_textureSelect2;
	SDL_Texture* m_textureRewind;
	SDL_Texture* m_textureNotRewind;
	SDL_Rect dstrectBack;
	SDL_Rect dstrectSelect;
	SDL_Rect dstrectSelect2;
	SDL_Texture* forAllTexture;
	static const int NUM_OF_BOXES = 10;
	SDL_Rect boxRectSliced[NUM_OF_BOXES];
	Vector2 selectBox[NUM_OF_BOXES];
	Vector2 rewindBox;
	bool boxSelected[NUM_OF_BOXES];
	SDL_Rect srcrect[NUM_OF_BOXES];
	SDL_Rect rect;
	int timer;
	int currentBox;
	Vector2 m_slectOffset;
	int m_lockValue;
	bool m_swappedStates = false;
	bool m_rulesChanged;

	bool ResetAll = false;
	bool resetALittle = false;
};