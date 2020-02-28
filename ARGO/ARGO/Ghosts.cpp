#include "Ghosts.h"
#include <fstream>
#include <sstream>
Ghost::Ghost()
{
	for (int i = 0; i < MAX_GHOSTS; i++)
	{
		dstrect[i] = { 0, -120, 120, 120 };
		srcrect[i] = { 0, i*120, 120, 120 };
		if (i >= 5)
			srcrect[i].y -= 600;
	}
}

void Ghost::setUp(SDL_Renderer* t_screen)
{
	m_screen = t_screen;
	m_loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/ghosts.bmp");
	m_texture = SDL_CreateTextureFromSurface(m_screen, m_loadedSurface);
}

int Ghost::posUpdate(std::string t_pos, int t_mainPlayerNum)
{
	/*mess = std::to_string(playerNum) + ":Cat-" + std::to_string(int(m_map.getCatPos().x)) + "," + std::to_string(int(m_map.getCatPos().y)) + ","
		+ "Clock-" + std::to_string(int(m_map.getClockPos().x)) + "," + std::to_string(int(m_map.getClockPos().y)) + ","
		+ "Book-" + std::to_string(int(m_map.getFlagPos().x)) + "," + std::to_string(int(m_map.getFlagPos().y)) + ","
		+ "Flag-" + std::to_string(int(m_map.getPlatformPos().x)) + "," + std::to_string(int(m_map.getPlatformPos().y)) + ","
		+ "Cactus-" + std::to_string(int(m_map.getCactusPos().x)) + "," + std::to_string(int(m_map.getCactusPos().y)) + ",";
		*/
	//reset();
	std::istringstream input;
	input.str(t_pos);
	std::string message = "";
	std::getline(input, message, ':');
	int playerNum = std::stoi(message);
	int index = 0;
	if (playerNum*5 > dstrect2.size())
	{
		while (std::getline(input, message, '-'))
		{
			SDL_Rect temp = { 0, -120, 120, 120 };
			std::getline(input, message, ',');
			temp.x = std::stoi(message);
			std::getline(input, message, ',');
			temp.y = std::stoi(message);
			dstrect2.push_back(temp);	
		}
		ghostsSignal.push_back(int(100));
	}
	else
	{
		while (std::getline(input, message, '-'))
		{
			SDL_Rect temp = { 0, -120, 120, 120 };
			std::getline(input, message, ',');
			temp.x = std::stoi(message);
			std::getline(input, message, ',');
			temp.y = std::stoi(message);
			dstrect2.at(((playerNum-1)*5)+index) = temp;
			index++;
		}
		ghostsSignal.at(playerNum - 1) = 100;
	}
	return playerNum; 
}

void Ghost::update(int* t_mainPlayerNum)
{
	int index = 0;
	for (auto currentGhostSignal : ghostsSignal)
	{
		ghostsSignal.at(index) -= 1;
		if(currentGhostSignal <=0)
		{
			reset(index+1, t_mainPlayerNum);
			ghostsSignal.erase(ghostsSignal.begin() + index);
			index--;
		}
		index++;
	}
	
}

void Ghost::render(int t_currentPlayerNum)
{
	for (int i = 0; i < MAX_GHOSTS; i++)
	{
		//SDL_RenderCopy(m_screen, m_texture, &srcrect[i], &dstrect[i]);
		//dstrect[i].y = -120;
	}
	int index = 0;
	for (auto currentDstrect : dstrect2)
	{
		if (index/5!= t_currentPlayerNum-1)
		{
			SDL_RenderCopy(m_screen, m_texture, &srcrect[index % 5], &currentDstrect);
		}
		index++;
	}
}

void Ghost::reset(int t_leftPlayer, int* t_mainPlayerNum)
{
	int playerStart = (t_leftPlayer-1) * 5;
	dstrect2.erase(dstrect2.begin()+ playerStart, dstrect2.begin() + playerStart+5);
	if (*t_mainPlayerNum > t_leftPlayer)
	{
		(*t_mainPlayerNum)--;
	}
}
