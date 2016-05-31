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
	srand(time(NULL));
	//Rooms setup
	entities.pushback(new Room("Laboratory I: Rise Project", "The lab where you conduct your research. There are 2 doors (south and east).", ROOM));
	entities.pushback(new Room("The Bestiary", "A place full of jails, with wild and agressive animals inside. There are 2 doors (west and south).", ROOM));
	entities.pushback(new Room("The Warehouse", "A room filled with shelves and freezers with chemicals. There are 2 doors (north and east).", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project", "A huge lab with tables and reserch stuff. There are 3 doors (north, west, south) and a large corridor further south (south -> west)", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project, west corridor", "A large corridor full of monkey pictures. There is 1 door at south and the rest of the lab at east", ROOM));
	entities.pushback(new Room("Laboratory II: Planet Project, south", "A huge lab with tables and reserch stuff. There are 3 doors (north, west, south) and a large corridor further south (west)", ROOM));
	entities.pushback(new Room("Bar", "A typical office bar with tables and bar. There are 2 doors (north and south).", ROOM));
	entities.pushback(new Room("Dinning Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Laboratory III: of the Apes", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Dressing Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Dressing Room", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Office", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Hall", "A place full of jails, with wild and agressive animals inside", ROOM));
	entities.pushback(new Room("Exit", "A place full of jails, with wild and agressive animals inside", ROOM));

	//Doors setup
	entities.pushback(new Door(EAST, WEST, entities[0], entities[1]));
	entities.pushback(new Door(SOUTH, NORTH, entities[0], entities[2]));
	entities.pushback(new Door(EAST, WEST, entities[2], entities[3]));
	entities.pushback(new Door(SOUTH, NORTH, entities[1], entities[3]));
	entities.pushback(new Door(SOUTH, NORTH, entities[4], entities[6]));
	entities.pushback(new Door(SOUTH, NORTH, entities[6], entities[7]));
	entities.pushback(new Door(EAST, WEST, entities[7], entities[11]));
	entities.pushback(new Door(SOUTH, NORTH, entities[5], entities[8]));
	entities.pushback(new Door(EAST, WEST, entities[8], entities[9]));
	entities.pushback(new Door(WEST, EAST, entities[10], entities[11]));
	entities.pushback(new Door(SOUTH, NORTH, entities[11], entities[12]));
	entities.pushback(new Door(WEST, EAST, entities[12], entities[13]));
	
	for (uint i = 0; i < 10; i++)
	{
		entities.pushback(new Item("axe", "Red axe, used in case of fire", nullptr));
		entities.pushback(new Item("adrenaline", "Power up all states for a short period of time", nullptr));
		entities.pushback(new Item("repellent", "keep enemies far away for a shor period of time", nullptr));
	}
	for (uint i = 0; i < entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			uint j = rand() % 13;
			entities[j]->list.push_back(entities[i]);
			entities[i]->insert(entities[j]);

		}
	}
	player = new Player("Dean", "Awesome scientific", entities[0], PLAYER, entities);
	entities.pushback(player);
	entities.pushback(new Gorilla(entities[1], GORILLA, entities, player));

}

void World::Game()
{
	
	char command[COMMANDBUFFER];
	bool firsttimeinloop = true;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;
	int Exit = 0;

	//timeGetTime()
	initialtime = GetTickCount();
	while (Exit == 0){
		//Executa el codi cada x milisegons (DELAY)
		currenttime = GetTickCount();
		if (currenttime >= (initialtime + DELAY)){
			initialtime = currenttime;
		}

		//update
		for (uint i = 0; i < entities.size(); i++)
			entities[i]->update(currenttime);

		//kbhit write commands
		if (_kbhit())
		{
			//write commands;
			command[charcommandnum] = _getch();
			command[charcommandnum + 1] = '\0';
			printf("\rString: %s", command);
			charcommandnum++;
			if (command[charcommandnum - 1] == '\r'){
				printf("\rYour command is: %s\n", command);
				command[charcommandnum - 1] = '\0';
				charcommandnum = 0;
				Exit = WriteCommands(command);
			}	
		}
	}
	getchar();
}

int World::WriteCommands(const char* command)
{
	int ret = 0;
	mString* commands;
	commands = new mString(command);
	mVector<mString*> vcommands;
	commands->tokenize(vcommands);
	delete commands;
	ret = gameplay(vcommands);
	for (unsigned int i = 0; i < vcommands.size(); i++)
	{
		delete vcommands[i];
	}
	vcommands.clean();
	return ret;
}
int World::gameplay(const mVector<mString*>& command)
{
	//quit game;
	if ((CompareWords(command[0]->C_Str(), "Quit")) || (CompareWords(command[0]->C_Str(), "quit")) || (CompareWords(command[0]->C_Str(), "q")))
	{
		printf("\nThe game is Over!! see you later.\n");
		return 1;
	}
	else
	{
		//print help menu;
		if (CompareWords(command[0]->C_Str(), "help"))
		{
			help();
			return 0;
		}
		//Look inventory and room ---------- look item left;
		if ((CompareWords(command[0]->C_Str(), "inventory")) || (CompareWords(command[0]->C_Str(), "inv")) || (CompareWords(command[0]->C_Str(), "i")))
		{
			player->Look();
		}
		if (CompareWords(command[0]->C_Str(), "look") && CompareWords(command[1]->C_Str(), "room"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (entities[i] == player->room && entities[i]->type == ROOM)
					entities[i]->Look();
			}
		}
		if (CompareWords(command[0]->C_Str(), "look"))
		{
			if (CompareWords(command[1]->C_Str(), "north"))
			{
				for (uint i = 0; i < entities.size(); i++)
				{
					if (entities[i]->next(player->room, NORTH) != nullptr)
					{
						printf("\nAt north there is %s\n", entities[i]->next(player->room, NORTH)->name->C_Str());
						return 0;
					}
				}
			}
			else if (CompareWords(command[1]->C_Str(), "south"))
			{
				for (uint i = 0; i < entities.size(); i++)
				{
					if (entities[i]->next(player->room, SOUTH) != nullptr)
					{
						printf("\nAt south there is %s\n", entities[i]->next(player->room, SOUTH)->name->C_Str());
						return 0;
					}
				}
			}
			else if (CompareWords(command[1]->C_Str(), "east"))
			{
				for (uint i = 0; i < entities.size(); i++)
				{
					if (entities[i]->next(player->room, EAST) != nullptr)
					{
						printf("\nAt east there is %s\n", entities[i]->next(player->room, EAST)->name->C_Str());
						return 0;
					}
				}
			}
			else if (CompareWords(command[1]->C_Str(), "west"))
			{
				for (uint i = 0; i < entities.size(); i++)
				{
					if (entities[i]->next(player->room, WEST) != nullptr)
					{
						printf("\nAt west there is %s\n", entities[i]->next(player->room, WEST)->name->C_Str());
						return 0;
					}
				}
			}
			else
			{
				printf("\nYou are at %s\n", player->room->name->C_Str());
				return 0;			}
		}
		if (CompareWords(command[0]->C_Str(), "look"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == ITEM && CompareWords(command[1]->C_Str(), entities[i]->name->C_Str()))
				{
					entities[i]->Look();
					return 0;
				}
			}
		}
		//Look equiped;
		if (CompareWords(command[0]->C_Str(), "look"))
		{
			if (CompareWords(command[1]->C_Str(), "equiped"))
			{
					for (uint i = 0; i < player->equiped.size(); i++)
						player->equiped.atnode(i)->data->Look();
			}
		}
		//pick item
		if (CompareWords(command[0]->C_Str(), "pick"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (CompareWords(command[1]->C_Str(), entities[i]->name->C_Str()))
				{
					if (player->pick(entities[i]->name->C_Str()))
						break;
					
				}
			}
			return 0;
		}
		//Drop item
		if (CompareWords(command[0]->C_Str(), "drop"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (CompareWords(command[1]->C_Str(), entities[i]->name->C_Str()))
				{
					if (player->drop(entities[i]->name->C_Str()))
						break;
				}
			}
			return 0;
		}
		//Equip item;
		if (CompareWords(command[0]->C_Str(), "equip"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (CompareWords(command[1]->C_Str(), entities[i]->name->C_Str()) == true)
				{
					if (player->equip(entities[i]->name->C_Str()))
						break;
				}
			}
			return 0;
		}
		//Unequip item;
		if (CompareWords(command[0]->C_Str(), "unequip"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				if (CompareWords(command[1]->C_Str(), entities[i]->name->C_Str()))
				{
					if (player->unequip(entities[i]->name->C_Str()))
						break;
				}
			}
			return 0;
		}
		//Open/Close doors; ------------- comparewords(2 == door);
		if (CompareWords(command[0]->C_Str(), "open"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				entities[i]->open(player->room, player->proompos);
			}
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "close"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				entities[i]->close(player->room, player->proompos);
			}
			return 0;
		}
		//Move player and print actual room;
		if (CompareWords(command[0]->C_Str(), "east"))
		{
			if (player->move(EAST) == true)
				player->proompos = WEST;
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "west"))
		{
			if(player->move(WEST) == true)
				player->proompos = EAST;
			if (player->room == entities[13])
				return 1;
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "north"))
		{
			if (player->move(NORTH) == true)
				player->proompos = SOUTH;
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "south"))
		{
			if (player->move(SOUTH) == true)
				player->proompos = NORTH;
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "go"))
		{
			if (CompareWords(command[1]->C_Str(), "east"))
			{
				if (player->move(EAST) == true)
					player->proompos = WEST;
				return 0;
			}
			if (CompareWords(command[1]->C_Str(), "west"))
			{
				if (player->move(WEST) == true)
					player->proompos = EAST;
				if (player->room == entities[13])
					return 1;
				return 0;
			}
			if (CompareWords(command[1]->C_Str(), "north"))
			{
				if(player->move(NORTH) == true)
					player->proompos = SOUTH;
				return 0;
			}
			if (CompareWords(command[1]->C_Str(), "south"))
			{
				if (player->move(SOUTH) == true)
					player->proompos = NORTH;
				return 0;
			}
		}
		return 0;
	}
}

bool World::CompareWords(const char* Word1, const char* Word2)
{
	int count = 0;
	if (Word1 != NULL){
		do
		{
			if (*Word1 != *Word2)
			{
				count = 1;
				return false;
			}
			*Word2++;
		} while (*Word1++);
		if (count == 0)
		{
			return true;
		}
		else return false;
	}
	else return false;

}

void World::help() const{
	printf("\n\tHelp Menu:\n");
	printf("\nHurry up and get out of this place!!\n\nFor the escape you can use the commands: ");
	printf("\nlook <direction>, look <item>, look room, inventory/inv/i.");
	printf("\ngo <direction>, open/close door.");
	printf("\npick/drop <item>, put/get <item> into/from <item>, equip/unequip <item>.");
	printf("\ncraft (open craft menu), craft <item>");
	printf("\nHelp, Quit/quit/q.\n");
	printf("\nand use use this directions: north/n, south/s, east/e, west/w.\n");

}
