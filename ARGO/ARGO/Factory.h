#ifndef FACTORY
#define FACTORY
#include "Character.h" 
class Factory
{
public:

	virtual Character* initEntityCat(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer) = 0;
	virtual Character* initEntityRock(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer) = 0;
	virtual Character* initEntityFlag(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer) = 0;
	virtual Character* initEntityPlatform(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer) = 0;
	virtual Character* initEntityCactus(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer) = 0;

};
#endif	//!FACTORY

#ifndef CHARACTERFACTORY
#define CHARACTERFACTORY
class CharacterFactory : public Factory
{
private:
	Character* m_test;
public:
	// do init ents stuff here when you get back
	Character* initEntityCat(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer);
	Character* initEntityRock(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer);
	Character* initEntityFlag(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer);
	Character* initEntityPlatform(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer);
	Character* initEntityCactus(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, const char* t_audioStr, bool t_botMode, SDL_Renderer& t_renderer);

};
#endif	//!CHARACTERFACTORY