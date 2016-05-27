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
	//Rooms setup
	entities.pushback(new Room("Laboratory I: Rise Project", "The lab where you conduct your research. There are 2 doors (south and east).", ROOM));
	entities.pushback(new Room("The Bestiary", "A place full of jails, with wild and agressive animals inside. There are 2 doors (west and south).", ROOM));
	entities.pushback(new Room("The Warehouse", "A room filled with shelves and freezers with chemicals. There are 2 doors (north and east).", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project", "A huge lab with tables and reserch stuff. There are 3 doors (north, west, south) and a large corridor further south (south -> west)", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project, west corridor", "A large corridor full of monkey pictures. There is 1 door at south and the rest of the lab at east", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project", "A huge lab with tables and reserch stuff. There are 3 doors (north, west, south) and a large corridor further south (west)", ROOM));
	entities.pushback(new Room("Bar", "A typical office bar with tables and bar. There are 2 doors (north and south).", ROOM));
	entities.pushback(new Room("Dinning Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Laboratory III: of the Apes", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Dressing Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Dressing Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Office", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Hall", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Exit", "A place full of jails, with wild and agressive animals inside", ROOM));

	//Doors setup
	entities.pushback(new Door(EAST, entities[0], entities[1]));
	entities.pushback(new Door(WEST, entities[1], entities[0]));

	entities.pushback(new Door(SOUTH, entities[0], entities[2]));
	entities.pushback(new Door(NORTH, entities[2], entities[0]));

	entities.pushback(new Door(EAST, entities[2], entities[3]));
	entities.pushback(new Door(WEST, entities[3], entities[2]));

	entities.pushback(new Door(SOUTH, entities[1], entities[3]));
	entities.pushback(new Door(NORTH, entities[3], entities[1]));

	entities.pushback(new Door(SOUTH, entities[4], entities[6]));
	entities.pushback(new Door(NORTH, entities[6], entities[4]));

	entities.pushback(new Door(SOUTH, entities[6], entities[7]));
	entities.pushback(new Door(NORTH, entities[7], entities[6]));

	entities.pushback(new Door(EAST, entities[7], entities[11]));
	entities.pushback(new Door(WEST, entities[11], entities[7]));

	entities.pushback(new Door(SOUTH, entities[5], entities[8]));
	entities.pushback(new Door(NORTH, entities[8], entities[5]));

	entities.pushback(new Door(EAST, entities[8], entities[9]));
	entities.pushback(new Door(WEST, entities[9], entities[8]));

	entities.pushback(new Door(WEST, entities[10], entities[11]));
	entities.pushback(new Door(EAST, entities[11], entities[10]));

	entities.pushback(new Door(SOUTH, entities[12], entities[12]));
	entities.pushback(new Door(NORTH, entities[11], entities[11]));

	entities.pushback(new Door(WEST, entities[12], entities[13]));
	entities.pushback(new Door(EAST, entities[13], entities[12]));

	entities.pushback(new Player("Dean", "Awesome scientific"));

}

void World::Game()
{

}