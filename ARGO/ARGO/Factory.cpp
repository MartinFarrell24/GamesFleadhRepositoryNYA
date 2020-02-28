#include "Factory.h"



Character* CharacterFactory::initEntityCat(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
		t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
	t_ent.getComponent<AudioComponent>().LoadMusicFile(t_audioStr);
	return m_test;
}

Character* CharacterFactory::initEntityRock(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
		t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
	t_ent.getComponent<AudioComponent>().LoadMusicFile(t_audioStr);
	return m_test;
}

Character* CharacterFactory::initEntityFlag(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
		t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
	t_ent.getComponent<AudioComponent>().loadMusicFileLevel(t_audioStr);
	return m_test;
}

Character* CharacterFactory::initEntityPlatform(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
		t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
	t_ent.getComponent<AudioComponent>().LoadMusicFileBG(t_audioStr);
	return m_test;
}

Character* CharacterFactory::initEntityCactus(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<BotComponent>();
	t_ent.getComponent<BotComponent>().setBotMode(t_botMode);
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
	t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
	t_ent.getComponent<AudioComponent>().LoadMusicFileDeath(t_audioStr);
	return m_test;
}
