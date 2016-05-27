#include "World.h"

World::World()
{
	CreateWorld();
}

World::~World()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}

void World::CreateWorld()
{
	entities.pushback(new Room("Laboratory", "laboratory", ROOM));
	entities.pushback(new Room("Laboratory2", "laboratory2", ROOM));
	entities.pushback(new Door(EAST, entities[0], entities[1]));
}

void World::Game()
{

}