#pragma once
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include <list>
class mapTile
{
public:
	mapTile();
	~mapTile();

	SpriteComponent m_tile;
	Vector2 vec;
	
	void init(std::string t_spriteToLoad, SDL_Renderer*& t_renderer) {
		m_tile.setPathAndScreen(t_spriteToLoad, t_renderer);
	}
	void setPos(Vector2 t_vec) { vec = t_vec; m_tile.setPosAndSize(vec.x, vec.y, 60, 60); };
	void render(SDL_Renderer*& t_renderer) { m_tile.render(); };
	void renderVector(SDL_Renderer*& t_renderer);
	void setCost(int cost);
	void setPreviousTile(mapTile& previous);
	void setGoal(bool g);
	void setStart(bool s);
	void setPath(bool p);
	void setWall(bool w);
	void setVisited(bool v);
	void setEnd(Vector2 end);
	void addEdge(mapTile& mapTile);

	int getCost();
	mapTile* getPrevious();
	bool getStart();
	bool getGoal();
	bool getWall();
	bool getVisited();
	Vector2 getEnd();
	Vector2 getCenter();
	void setCentre(Vector2 t_centre);
	std::list<mapTile*>& getAdjacent();

private:

	std::list<mapTile*> m_adj;
	mapTile* m_previous;
	Vector2 m_lineEnd, m_center;
	int m_cost;
	bool m_visited;
	bool m_start;
	bool m_goal;
	bool m_path;
	bool m_wall;
};