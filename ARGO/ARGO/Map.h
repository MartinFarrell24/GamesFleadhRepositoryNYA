#pragma once
#include "MapTile.h"
#include  "MapHolder.h"
#include <list>
class Map
{
public:
	Map();
	~Map();
	
	MapHolder m_mapHolder;
	mapTile tile[32][15];
	void init(SDL_Renderer*& t_renderer, int t_levelNum = 1);
	void render(SDL_Renderer*& t_renderer, int i, int j);
	std::vector<Vector2> getMapCorners();
	int getLevelNum();
	void setLevelNum(int t_level);

	void setAdjacents();
	
	Vector2 getCatPos() { return catPos; };
	Vector2 getFlagPos() { return flagPos; };
	Vector2 getClockPos() { return clockPos; };
	Vector2 getPlatformPos() { return platformPos; };
	Vector2 getCactusPos() { return cactusPos; };
	void setPlayerPos(Vector2 t_playerPos) { catPos = t_playerPos; };
	void setFlagPos(Vector2 t_flagPos) { flagPos = t_flagPos; };
	void setClockPos(Vector2 t_clockPos) { clockPos = t_clockPos; };
	void setPlatformPos(Vector2 t_platformPos) { platformPos = t_platformPos; };
	void setCactusPos(Vector2 t_cactusPos) { cactusPos = t_cactusPos; };
	void BFS(Vector2 goalPos);
	void ToggleDrawVector();
	Vector2 getDirection(Vector2 t_botPos);
private:
	Vector2 mapArr[32][15];
	std::string platformStr, wallStr;
	int levelNum;
	void drawTile(SDL_Renderer*& t_renderer,int i,int j);
	bool drawVectors;
	Vector2 catPos, flagPos, clockPos, platformPos, cactusPos;
};