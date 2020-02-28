#include "MapTile.h"

mapTile::mapTile()
{
 	m_center = Vector2(vec.X() + 30, vec.Y() + 30);
}

mapTile::~mapTile()
{
}

void mapTile::renderVector(SDL_Renderer*& t_renderer)
{
	if (!getWall() && m_lineEnd.X() != 0)
	{
		m_center = Vector2(vec.X() + 30, vec.Y() + 30);
		SDL_RenderDrawLine(t_renderer, m_center.X(), m_center.Y(), m_lineEnd.X(), m_lineEnd.Y());
	}
}

void mapTile::setCost(int cost)
{
	m_cost = cost;
}

void mapTile::setPreviousTile(mapTile& previous)
{
	m_previous = &previous;
}

void mapTile::setGoal(bool g)
{
	m_goal = g;
}

void mapTile::setStart(bool s)
{
	m_start = s;
}

void mapTile::setPath(bool p)
{
	m_path = p;
}

void mapTile::setWall(bool w)
{
	m_wall = w;
}

void mapTile::setVisited(bool v)
{
	m_visited = v;
}

void mapTile::setEnd(Vector2 end)
{

	m_lineEnd = end;
}

void mapTile::addEdge(mapTile& mapTile)
{
	m_adj.push_back(&mapTile);
}

int mapTile::getCost()
{
	return m_cost;
}

mapTile* mapTile::getPrevious()
{
	return m_previous;
}

bool mapTile::getStart()
{
	return m_start;
}

bool mapTile::getGoal()
{
	return m_goal;
}

bool mapTile::getWall()
{
	return m_wall;
}

bool mapTile::getVisited()
{
	return m_visited;
}

Vector2 mapTile::getEnd()
{
	return m_lineEnd;
}


void mapTile::setCentre(Vector2 t_centre)
{
	m_center = t_centre;
}
Vector2 mapTile::getCenter()
{
	return m_center;
}

std::list<mapTile*>& mapTile::getAdjacent()
{
	return m_adj;
}
