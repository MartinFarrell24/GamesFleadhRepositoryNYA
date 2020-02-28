#include "Entity.h"
#include "SpriteComponent.h"
Entity::Entity()
{

}

bool Entity::getAlive()
{
	return alive;
}

void Entity::destroy()
{
	alive = false;
}

void Entity::update()
{
	for (auto& c : components)c->update();
	
}

void Entity::render(SDL_Renderer* t_screen)
{
	for (auto& c : components)c->render();
}
