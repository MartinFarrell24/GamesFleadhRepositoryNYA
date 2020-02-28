#ifndef CHARACTER
#define CHARACTER
#include <iostream>
#include "Entity.h"
#include "Vector2.h"
#include "AudioComponent.h"
#include "BotComponent.h"
#include "BodyComponent.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "EntityManager.h"

class Character
{
public:
	Character() {}
	virtual ~Character() {}
	virtual void addEntityFromFactory(Entity& t_ent) = 0;
};
#endif // CHARACTER

#ifndef CAT
#define CAT
class Cat: public Character
{
	
public:
	void addEntityFromFactory(Entity& t_ent) {  std::cout << "Entity cat" << std::endl; }
};
#endif	//!CAT

#ifndef FLAG
#define FLAG
class Flag: public Character
{
private:
	
public:
	void addEntityFromFactory(Entity& t_ent) { std::cout << "Entity flag" << std::endl;  }
};
#endif	//!FLAG

#ifndef ROCK
#define ROCK
class Rock : public Character
{
public:
	void addEntityFromFactory(Entity& t_ent) {  std::cout << "Entity rock" << std::endl; }
};
#endif	//!ROCK

#ifndef PLATFORM
#define PLATFORM
class Platform: public Character
{
public:
	void addEntityFromFactory(Entity& t_ent) {  std::cout << "Entity platform" << std::endl; }
};
#endif // !PLATFORM

#ifndef CACTUS
#define CACTUS
class Cactus: public Character
{

public:
	void addEntityFromFactory(Entity& t_ent) {  std::cout << "Entity cactus" << std::endl;  }

};
#endif // !CACTUS


