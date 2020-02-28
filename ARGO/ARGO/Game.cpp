#include "Game.h"


GameState Game::m_currentMode{ GameState::splash};
EntityManager manager;
auto& newPlayer(manager.addEntity("player"));
auto& flag(manager.addEntity("goal"));
auto& platform(manager.addEntity("stop"));
auto& cactus(manager.addEntity("spiky"));
auto& rock(manager.addEntity("move"));
auto& rock2(manager.addEntity("move"));
auto& rock3(manager.addEntity("move"));
auto& rock4(manager.addEntity("move"));
auto& rock5(manager.addEntity("move"));
auto& rock6(manager.addEntity("move"));
auto& rock7(manager.addEntity("move"));
auto& rock8(manager.addEntity("move"));
auto& rock9(manager.addEntity("move"));
auto& rock10(manager.addEntity("move"));
auto& rock11(manager.addEntity("move"));
auto& rock12(manager.addEntity("move"));
auto& rock13(manager.addEntity("move"));
auto& rock14(manager.addEntity("move"));
auto& rock15(manager.addEntity("move"));
auto& rock16(manager.addEntity("move"));

auto& rock17(manager.addEntity("move"));
auto& rock18(manager.addEntity("move"));
auto& rock19(manager.addEntity("move"));
auto& rock20(manager.addEntity("move"));
auto& rock21(manager.addEntity("move"));
auto& rock22(manager.addEntity("move"));
auto& rock23(manager.addEntity("move"));
auto& rock24(manager.addEntity("move"));

auto& rock25(manager.addEntity("move"));
auto& rock26(manager.addEntity("move"));
auto& rock27(manager.addEntity("move"));
auto& rock28(manager.addEntity("move"));
auto& rock29(manager.addEntity("move"));
auto& rock30(manager.addEntity("move"));
auto& rock31(manager.addEntity("move"));

auto& rock32(manager.addEntity("move"));
auto& rock33(manager.addEntity("move"));
auto& rock34(manager.addEntity("move"));

auto& rock35(manager.addEntity("move"));
auto& rock36(manager.addEntity("move"));
auto& rock37(manager.addEntity("move"));

Game::Game()
{


}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		}

		isRunning = true;
	}


	m_gamePlayScr.init(m_renderer);

	Map tempMap = *m_gamePlayScr.getMap();
	m_currentLevel = tempMap.getLevelNum();

	m_characterVectorArray.push_back(m_factory->initEntityCat(newPlayer, Vector2(tempMap.getCatPos()), Vector2(60, 60), "ASSETS/IMAGES/states.bmp", true, "ASSETS/AUDIO/meow.wav", false, *m_renderer));
	m_characterVectorArray.push_back(m_factory->initEntityFlag(flag, Vector2(tempMap.getFlagPos()), Vector2(60, 60), "ASSETS/IMAGES/flag.bmp", true, "ASSETS/AUDIO/levelPass.mp3", false, *m_renderer));
	m_characterVectorArray.push_back(m_factory->initEntityCactus(cactus,Vector2(tempMap.getCactusPos()), Vector2(60, 60), "ASSETS/IMAGES/cactus.bmp", true, "ASSETS/AUDIO/deathNoise.wav", false, *m_renderer));
	m_characterVectorArray.push_back(m_factory->initEntityPlatform(platform, Vector2(tempMap.getPlatformPos()), Vector2(60, 60), "ASSETS/IMAGES/platform.bmp", true, "ASSETS/AUDIO/temp.wav", false, *m_renderer));

	initEnts(rock, Vector2(tempMap.getFlagPos()), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	m_currentLevel = 0;// tempMap.getLevelNum();





	initEnts(rock2, Vector2(7200,480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock3, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock4, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true,  false);
	initEnts(rock5, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock6, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock7, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock8, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true,  false);
	initEnts(rock9, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true,  false);
	initEnts(rock10, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock11, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock12, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock13, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock14, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock15, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock16, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);

	initEnts(rock17, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock18, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock19, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock20, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock21, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock22, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock23, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock24, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);

	initEnts(rock25, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock26, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock27, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock28, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock29, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock30, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock31, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);

	initEnts(rock32, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock33, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock34, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);

	initEnts(rock35, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock36, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);
	initEnts(rock37, Vector2(7200, 480), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, false);





	lastString = "ASSETS/IMAGES/states.bmp";
	Entity* arr[]{ &newPlayer,&flag,&platform,&cactus,&rock };

	std::copy(std::begin(arr), std::end(arr), std::begin(entArr));
	stick.init();



	platform.getComponent<AudioComponent>().playAudioBG();
	newPlayer.getComponent<AudioComponent>().playAudioCat();

	//flag.getComponent<AudioComponent>().closeAudio();

	answer = m_gamePlayScr.getChanges();
}

void Game::handleEvents()
{
	SDL_PollEvent(&m_event);
	switch (m_event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_JOYAXISMOTION:
		if (m_event.jaxis.which == 0)
		{
			if (m_event.jaxis.axis == 0)
			{
				if (m_event.jaxis.value < -20000)
				{
					stick.setX(-1);
				}
				else if (m_event.jaxis.value > 20000)
				{
					stick.setX(1);
				}
				else {
					stick.setX(0);
					keyTest = true;
				}
			}
			if (m_event.jaxis.axis == 1)
			{
				if (m_event.jaxis.value < -stick.getDeadZone())
				{
					stick.setY(-1);
				}
				else if (m_event.jaxis.value > stick.getDeadZone())
				{
					stick.setY(1);
				}
				else {
					stick.setY(0);
				}
			}
		}
		break;
	case SDL_JOYBUTTONDOWN:
		if (SDL_JoystickGetButton(stick.getStick(), 4) != 0 && !botSwitch)
		{
			if (botMode)
			{
				botMode = false;
			}
			else if (!botMode)
			{
				botMode = true;
			}
			botSwitch = true;
		}

		break;
	}

	switch (m_currentMode)//gamestate
	{
	case GameState::splash:
		break;
	case GameState::licence:
		m_licence.handleEvents(m_event, m_currentMode);
		break;
	case GameState::mainMenu:
		m_mainMenuScr.handleEvents(m_event, m_currentMode, stick);
		if (m_mainMenuScr.quitState())
			clean();
		break;
	case GameState::gameplay://no process events for this screen here
		if (!SDL_JoystickGetButton(stick.getStick(), 4) != 0)
		{
			botSwitch = false;
		}
		break;
	case GameState::options:
		m_optionsScr.handleEvents(m_event, m_currentMode, stick);
		break;
	case GameState::help:
		m_helpScr.handleEvents(m_event, m_currentMode, stick);
	case GameState::credits:
		break;
	default:
		break;
	}
}

void Game::update()
{
	answer = m_gamePlayScr.getChanges();


	newPlayer.setComponentString(answer[1]);
	rock.setComponentString(answer[3]);
	platform.setComponentString(answer[5]);
	flag.setComponentString(answer[7]);
	cactus.setComponentString(answer[9]);

	m_timer += m_frames;
	if (m_timer >= 5)
	{
		newPlayer.getComponent<AudioComponent>().playAudioCat();
		m_timer = 0;
	}

	if (m_gamePlayScr.getCurrentLevel() -1 > m_optionsScr.getAchievementCount())
	{

		m_optionsScr.increaseAchievementCount(m_renderer);
		flag.getComponent<AudioComponent>().playAudioLevel();
		m_gamePlayScr.addToLevelCount();
	}
	//updateEnts(bot, Vector2(bot.getComponent<PositionComponent>().getPosition().X(), bot.getComponent<PositionComponent>().getPosition().Y()), Vector2(120, 120), "ASSETS/IMAGES/bot.bmp", true);
	m_optionsScr.setCatHurtAchievement(manager.GetDeathToCactus());
	m_optionsScr.setCatStateAchievement(m_gamePlayScr.getSwappedStates());


	if (manager.GetDeathToCactus())
	{
		m_gamePlayScr.setHurtByCactus(manager.GetDeathToCactus());
		cactus.getComponent< AudioComponent>().playAudioDeath();
	}


	Map tempMap = *m_gamePlayScr.getMap();

	Vector2 savedPos[5];
	for (int i = 0, j = 0; i < 5; i++, j += 2)
	{
		if (entArr[i] != NULL)
		{
			if (answer[j] == "cat")
			{
				if (stick.X()==1)
				{
					lastString = "ASSETS/IMAGES/states.bmp";
				}
				else if (stick.X() == -1)
				{
					lastString = "ASSETS/IMAGES/states2.bmp";
				}
				if (m_currentLevel != tempMap.getLevelNum())
				{
					entArr[i]->getComponent<PositionComponent>().setPosition(tempMap.getCatPos());
					entArr[i]->getComponent<PositionComponent>().popAllPositions();
				}

			updateEnts(*entArr[i], Vector2(entArr[i]->getComponent<PositionComponent>().getPosition().X(), entArr[i]->getComponent<PositionComponent>().getPosition().Y()), Vector2(60, 60), lastString, true,botMode);
			savedPos[0] = entArr[i]->getComponent<PositionComponent>().getPosition();
			}
			else if (answer[j] == "flag")
			{
				if (m_currentLevel != tempMap.getLevelNum())
				{
					entArr[i]->getComponent<PositionComponent>().setPosition(tempMap.getFlagPos());
					entArr[i]->getComponent<PositionComponent>().popAllPositions();
				}

				updateEnts(*entArr[i], Vector2(entArr[i]->getComponent<PositionComponent>().getPosition().X(), entArr[i]->getComponent<PositionComponent>().getPosition().Y()), Vector2(60, 60), "ASSETS/IMAGES/flag.bmp", true, botMode);
				savedPos[3] = entArr[i]->getComponent<PositionComponent>().getPosition();
			}
			else if (answer[j] == "cactus")
			{
				if (m_currentLevel != tempMap.getLevelNum())
				{


					entArr[i]->getComponent<PositionComponent>().setPosition(tempMap.getCactusPos());
					entArr[i]->getComponent<PositionComponent>().popAllPositions();
				}
				updateEnts(*entArr[i], Vector2(entArr[i]->getComponent<PositionComponent>().getPosition().X(), entArr[i]->getComponent<PositionComponent>().getPosition().Y()), Vector2(60, 60), "ASSETS/IMAGES/cactus.bmp", true, botMode);
				savedPos[4] = entArr[i]->getComponent<PositionComponent>().getPosition();
			}
			else if (answer[j] == "clock")
			{
				if (m_currentLevel != tempMap.getLevelNum())
				{


					entArr[i]->getComponent<PositionComponent>().setPosition(tempMap.getClockPos());
					entArr[i]->getComponent<PositionComponent>().popAllPositions();
				}
				updateEnts(*entArr[i], Vector2(entArr[i]->getComponent<PositionComponent>().getPosition().X(), entArr[i]->getComponent<PositionComponent>().getPosition().Y()), Vector2(60, 60), "ASSETS/IMAGES/clock.bmp", true, botMode);
				savedPos[1] = entArr[i]->getComponent<PositionComponent>().getPosition();
			}
			else if (answer[j] == "platform")
			{
				if (m_currentLevel != tempMap.getLevelNum())
				{


					entArr[i]->getComponent<PositionComponent>().setPosition(tempMap.getPlatformPos());
					entArr[i]->getComponent<PositionComponent>().popAllPositions();
				}
				updateEnts(*entArr[i], Vector2(entArr[i]->getComponent<PositionComponent>().getPosition().X(), entArr[i]->getComponent<PositionComponent>().getPosition().Y()), Vector2(60, 60), "ASSETS/IMAGES/book.bmp", true, botMode);

				savedPos[2] = entArr[i]->getComponent<PositionComponent>().getPosition();
			}
			entArr[i]->setComponentString(answer[j+1]);
		}

		if ((!(m_gamePlayScr.getMap()->getLevelNum() == 5 || m_gamePlayScr.getMap()->getLevelNum() == 4)) && rock2.getComponent<PositionComponent>().getPosition().x < 9000)
		{
			updateEnts(rock2, Vector2(9120, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock3, Vector2(9240, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock4, Vector2(9480, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock5, Vector2(9600, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock6, Vector2(9240, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock7, Vector2(9480, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock8, Vector2(9360, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock9, Vector2(9600, 1200), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock10, Vector2(9120, 1200), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock11, Vector2(9480, 1080), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock12, Vector2(9360, 1080), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock13, Vector2(9240, 1080), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock14, Vector2(9960, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock15, Vector2(91080, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock16, Vector2(91200, 1320), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock17, Vector2(91080, 720), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock18, Vector2(9960, 600), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock19, Vector2(91200, 600), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock20, Vector2(91080, 480), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock21, Vector2(9960, 360), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock22, Vector2(91200, 360), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock23, Vector2(91080, 240), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock24, Vector2(91200, 120), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock25, Vector2(91560, 1200), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock26, Vector2(91440, 1080), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock27, Vector2(91680, 1080), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock28, Vector2(91560, 960), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock29, Vector2(91440, 840), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock30, Vector2(91680, 840), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock31, Vector2(91560, 720), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock32, Vector2(92160, 240), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock33, Vector2(92280, 240), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock34, Vector2(92520, 360), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock35, Vector2(92160, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock36, Vector2(92280, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock37, Vector2(92400, 1440), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
		}

		if ((m_gamePlayScr.getMap()->getLevelNum() == 4) && !m_initialiseLevelFour)
		{
			manager.popAllPositions();
			updateEnts(rock2, Vector2(720 / 2, 600/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock3, Vector2(840 / 2, 600/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock4, Vector2(1080 / 2, 1320 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock5, Vector2(1080 / 2, 1440 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock6, Vector2(1080 / 2, 1560 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			//updateEnts(rock7, Vector2(2160 / 2, 1320 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock8, Vector2(2280 / 2, 720 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock9, Vector2(2280 / 2, 840 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock10, Vector2(2160 / 2, 720 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			/*updateEnts(rock11, Vector2(1080 / 2, 600 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock12, Vector2(1200 / 2, 600 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock13, Vector2(1440 / 2, 360 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock14, Vector2(2160 / 2, 240 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock15, Vector2(2040 / 2, 1440 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock16, Vector2(2400 / 2, 1320 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock17, Vector2(2520 / 2, 1320 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock18, Vector2(2640 / 2, 1320 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock19, Vector2(2760 / 2, 1440 / 2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);*/

			m_initialiseLevelFour = true;
		}
		if (m_initialiseLevelFour && m_gamePlayScr.getMap()->getLevelNum() != 4)
		{
			m_initialiseLevelFour = false;
		}

		if ((m_gamePlayScr.getMap()->getLevelNum() == 5) && !initialiseOnce)
		{
			manager.popAllPositions();
			updateEnts(rock2, Vector2(120/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock3, Vector2(240.2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock4, Vector2(480/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock5, Vector2(600/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock6, Vector2(240/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock7, Vector2(480/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock8, Vector2(360/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock9, Vector2(600/2, 1200/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock10, Vector2(120/2, 1200/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock11, Vector2(480/2, 1080/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock12, Vector2(360/2, 1080/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock13, Vector2(240/2, 1080/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock14, Vector2(960/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock15, Vector2(1080/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock16, Vector2(1200/2, 1320/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock17, Vector2(1080/2, 720/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock18, Vector2(960/2, 600/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock19, Vector2(1200/2, 600/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock20, Vector2(1080/2, 480/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock21, Vector2(960/2, 360/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock22, Vector2(1200/2, 360/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock23, Vector2(1080/2, 240/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock24, Vector2(1200/2, 120/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock25, Vector2(1560/2, 1200/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock26, Vector2(1440/2, 1080/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock27, Vector2(1680/2, 1080/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock28, Vector2(1560/2, 960/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock29, Vector2(1440/2, 840/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock30, Vector2(1680/2, 840/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock31, Vector2(1560/2, 720/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock32, Vector2(2160/2, 240/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock33, Vector2(2280/2, 240/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock34, Vector2(2520/2, 360/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			updateEnts(rock35, Vector2(2160/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock36, Vector2(2280/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);
			updateEnts(rock37, Vector2(2400/2, 1440/2), Vector2(60, 60), "ASSETS/IMAGES/ToiletRoll.bmp", true, false);

			initialiseOnce = true;
		}
		if (initialiseOnce && m_gamePlayScr.getMap()->getLevelNum() != 5)
		{
			initialiseOnce = false;
		}
	}


	m_currentLevel = tempMap.getLevelNum();

	std::vector<Vector2> passIn;
	for (int i = 0;i<5;i++)
	{
		passIn.push_back(savedPos[i]);
	}
	m_gamePlayScr.updatePositions(passIn);
	switch (m_currentMode)//gamestate
	{
	case GameState::intro:
		m_intro.update(m_currentMode);
		break;
	case GameState::splash://no process events for this screen
		m_splashScr.update(m_currentMode);
		break;
	case GameState::licence:
		m_licence.update(m_currentMode);
		break;
	case GameState::mainMenu://no process events for this screen
		m_mainMenuScr.update();
		m_currentLevel = 0;
		break;
	case GameState::gameplay://no process events for this screen
		m_gamePlayScr.update();
		manager.reset(m_gamePlayScr.getPauseMenu().getRewindALot(), m_gamePlayScr.getPauseMenu().getRewindALittle());
		if (botMode)
		{
			manager.botMove(m_gamePlayScr.getMap(), m_currentLevel, m_gamePlayScr.getPause());
		}

		break;
	case GameState::options://no process events for this screen
		m_optionsScr.update();
		break;
	case GameState::help:
		m_helpScr.update();
		break;
	case GameState::credits://no process events for this screen
		m_creditsScr.update();
		break;
	default:
		break;
	}

}

void Game::subSystemUpdate()
{
	switch (m_currentMode)//gamestate
	{

	case GameState::gameplay://no process events for this screen
		if ((m_event.type == SDL_JOYBUTTONDOWN || m_event.type == SDL_JOYAXISMOTION))
		{

		}
		manager.handleEvents(stick, m_gamePlayScr.getMapCorners(),m_gamePlayScr.getPause());
		m_gamePlayScr.handleEvents(m_event, m_currentMode, stick,m_currentLevel);
		break;
	default:
		break;
	}
	m_gamePlayScr.fixedUpdate(manager);
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	switch (m_currentMode)//gamestate
	{
	case GameState::intro:
		m_intro.render(m_renderer);
		break;
	case GameState::licence://no process events for this screen
		m_licence.render(m_renderer);
		break;
	case GameState::splash://no process events for this screen
		m_splashScr.render(m_renderer);
		break;
	case GameState::mainMenu://no process events for this screen
		m_mainMenuScr.render(m_renderer);
		break;
	case GameState::gameplay://no process events for this screen
		m_gamePlayScr.render(m_renderer, manager);
		manager.draw(m_renderer);
		break;
	case GameState::options://no process events for this screen
		m_optionsScr.render(m_renderer);
		break;
	case GameState::help:
		m_helpScr.render(m_renderer);
		break;
	case GameState::credits://no process events for this screen
		m_creditsScr.render(m_renderer);
		break;
	default:
		break;
	}

	SDL_RenderPresent(m_renderer);
}


void Game::clean()
{
	stick.close();
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	isRunning = false;
}




void Game::initEnts(Entity &t_ent,Vector2 t_pos,Vector2 t_size, std::string t_str, bool t_isAnim,bool t_botMode)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, m_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
	t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());


}

void Game::updateEnts(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim,bool t_botMode)
{
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.getComponent<SpriteComponent>().resetSprite();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, m_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
	t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());

}
