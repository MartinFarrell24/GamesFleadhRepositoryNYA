#pragma once
#include "Component.h"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <array>
#include <SDL.h>

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Entity
{
private:
	bool alive = true;
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitset;
	std::string ComponentTag;
	
public:
	Entity();
	bool getAlive();
	void destroy();
	void update();
	void render(SDL_Renderer* t_screen);

	
	template <typename T> bool hasComponent() const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

	template <typename T> void deleteComp(T* t) const
	{
		
		components.erase(
			std::remove_if(components.begin(), components.end(), [t](const T& comp) {
			return &comp == t;
		}),
			components.end()
			);
	}
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&& ... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitset[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}
	template <typename T, typename... TArgs>
	T& addComponent2(TArgs&& ... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		
		c->init();
		return *c;
	}
	template <typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	inline std::string getComponentString()
	{
		return ComponentTag;
	}

	inline void setComponentString(std::string t_str)
	{
		ComponentTag = t_str;
	}
};