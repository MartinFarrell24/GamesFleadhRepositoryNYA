#include "Map.h"

#include <string>
#include <fstream>
Map::Map()
{
	levelNum = 1;
}

Map::~Map()
{
}
void Map::init(SDL_Renderer*& t_renderer, int t_levelNum)
{
	if (t_levelNum < 6)
	{
		levelNum = t_levelNum;
	}
	platformStr = "ASSETS/IMAGES/platform.bmp";
	wallStr = "ASSETS/IMAGES/Wall.bmp";

	std::string line;
	std::ifstream myfile("ASSETS/MAP/level" + std::to_string(levelNum) + ".txt");
	std::vector<int> mapArray;
	if (myfile.is_open())
	{
		while (getline(myfile, line, ',') && line!="end")
		{
			mapArray.push_back(std::stoi(line));
		}
		myfile.close();
	}
	//7,6,5,2,0
		 int arrayIndex = 0;
	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 32; i++)
		{
			tile[i][j].setWall(false);
			tile[i][j].setPos(Vector2(0, 0));
			if (mapArray[arrayIndex] == 14) {
				m_mapHolder.mapDoubleArray[i][j] = mapArray[arrayIndex];
				tile[i][j].init(wallStr, t_renderer);
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				tile[i][j].setCost(999);
				tile[i][j].setWall(true);
			}
			else if (mapArray[arrayIndex] == 13) {
				m_mapHolder.mapDoubleArray[i][j] = mapArray[arrayIndex];
				tile[i][j].init(platformStr, t_renderer);
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));

				tile[i][j].setWall(true);
			}

			//19, 16, 17, 18, 20,
			//16=cactus 17=flag 18=platform 19=cat 20 = clock
			//cactus 16, cat 19, flag 17, clock 20, shelf 18
			else if (mapArray[arrayIndex] == 16)
			{
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				cactusPos = Vector2(0 + (60 * i), 0 + (60 * j));
			}
			else if (mapArray[arrayIndex] == 17)
			{
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				flagPos = Vector2(0 + (60 * i), 0 + (60 * j));
			}
			else if (mapArray[arrayIndex] == 18)
			{
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				platformPos = Vector2(0 + (60 * i), 0 + (60 * j));
			}
			else if (mapArray[arrayIndex] == 19)
			{
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				catPos = Vector2(0 + (60 * i), 0 + (60 * j));
			}
			else if (mapArray[arrayIndex] == 20)
			{
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				clockPos = Vector2(0 + (60 * i), 0 + (60 * j));
			}
			else {
				m_mapHolder.mapDoubleArray[i][j] = 0;
				tile[i][j].init(wallStr, t_renderer);
				tile[i][j].setPos(Vector2(0 + (60 * i), 0 + (60 * j)));
				tile[i][j].setCentre(Vector2(30 + (60 * i), 30 + (60 * j)));
			}
			arrayIndex++;
		}
	}
	drawVectors = true;
	setAdjacents();
}

void Map::drawTile(SDL_Renderer*& t_renderer, int i, int j)
{
	Vector2 tilePos = Vector2(0 + (120 * i), 0 + (120 * j));
	if(tilePos != cactusPos && tilePos != flagPos && tilePos != platformPos && tilePos != catPos && tilePos != clockPos)
		tile[i][j].m_tile.render();
	if (drawVectors)
	{
		tile[i][j].renderVector(t_renderer);
	}
}

void Map::BFS(Vector2 goalPos)
{
	int x = goalPos.x; int y = goalPos.y;
	tile[x][y].setCentre(Vector2(30 + (60 * x), 30 + (60 * y)));
	mapTile* goal = &tile[x][y];

	bool goalReached = false;

	std::list<mapTile*> queue;

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			tile[i][j].setStart(false);
			tile[i][j].setGoal(false);
			tile[i][j].setPath(false);
			tile[i][j].setVisited(false);
			tile[i][j].setCost(0);
		}
	}
	goal->setGoal(true);
	goal->setVisited(true);
	queue.push_back(goal);

	while (!queue.empty())
	{
		int originCost = queue.front()->getCost();

		for (auto& e : queue.front()->getAdjacent())
		{
			if (e->getVisited() == false)
			{
				e->setVisited(true);
				if (e->getWall() == false)
				{
					e->setCost(originCost + 1);
					e->setPreviousTile(*queue.front());
					queue.push_back(e);
				}
			}
		}
		queue.pop_front();
	}

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (tile[i][j].getPrevious() && tile[i][j].getWall() == false)
			{
				//b-a)/3)+a
				Vector2 tempV(((tile[i][j].getPrevious()->getCenter()- tile[i][j].getCenter()) /3) + tile[i][j].getCenter());
				tile[i][j].setEnd(tempV);
			}
		}
	}
}

void Map::ToggleDrawVector()
{
	if (drawVectors)
	{
		drawVectors = false;
	}
	else
	{
		drawVectors = true;
	}
}

Vector2 Map::getDirection(Vector2 t_botPos)
{
	Vector2 ans;
	int posX = t_botPos.x / 60;
	int posY = t_botPos.y / 60;
	ans = tile[posX][posY].getEnd() - tile[posX][posY].getCenter();
	return ans;
}

void Map::render(SDL_Renderer*& t_renderer, int i, int j)
{
	if (m_mapHolder.mapDoubleArray[i][j] == 11 ||
		m_mapHolder.mapDoubleArray[i][j] == 12||
		m_mapHolder.mapDoubleArray[i][j] == 13||
		m_mapHolder.mapDoubleArray[i][j] == 14 ||
		m_mapHolder.mapDoubleArray[i][j] == 15)
	{
		drawTile(t_renderer, i, j);
	}
	else
	{
		tile[i][j].renderVector(t_renderer);
	}
}

std::vector<Vector2> Map::getMapCorners()
{
	std::vector<Vector2> corners;
	Vector2 topLeft(0 + (60 * 1), 0 + (60 * 1));
	Vector2 bottomRight(0 + (60 * 31), 0 + (60 * 14));
	corners.push_back(topLeft);
	corners.push_back(bottomRight);
	return corners;
}

int Map::getLevelNum()
{
	return levelNum;
}

void Map::setLevelNum(int t_level)
{
	levelNum = t_level;
}

void Map::setAdjacents()
{
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i > 0)
			{
				tile[i][j].addEdge(tile[i - 1][j]);
			}

			if (i + 1 < 32)
			{
				tile[i][j].addEdge(tile[i + 1][j]);
			}

			if (j > 0)
			{
				tile[i][j].addEdge(tile[i][j - 1]);
			}

			if (j < 15)
			{
				tile[i][j].addEdge(tile[i][j + 1]);
			}

		/*	if (i > 0 && j > 0)
			{
				tile[i][j].addEdge(tile[i - 1][j - 1]);
			}
			if (i + 1 < 32 && j > 15)
			{
				tile[i][j].addEdge(tile[i + 1][j + 1]);
			}
			if (i + 1 < 32 && j > 0)
			{
				tile[i][j].addEdge(tile[i + 1][j - 1]);
			}
			if (i + 1 < 32 && j > 0)
			{
				tile[i][j].addEdge(tile[i + 1][j - 1]);
			}*/
		}
	}
}
