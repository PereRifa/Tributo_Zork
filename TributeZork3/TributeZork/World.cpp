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

	entities.pushback(new Door(SOUTH, NORTH, entities[12], entities[12]));

	entities.pushback(new Door(WEST, EAST, entities[12], entities[13]));

	player = new Player("Dean", "Awesome scientific", entities[0]);
	entities.pushback(player);

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

		//kbhit test
		if (_kbhit())
		{
			
			//write commands;
			command[charcommandnum] = _getch();
			command[charcommandnum + 1] = '\0';
			printf("\rString: %s", command);//va imprimint l'estat de command
			charcommandnum++;
			if (command[charcommandnum - 1] == '\r'){//quant apretes enter, imprimeix el command i l'esborra
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
	if ((CompareWords(command[0]->C_Str(), "Quit")) || (CompareWords(command[0]->C_Str(), "quit")) || (CompareWords(command[0]->C_Str(), "q")))
	{
		printf("\nThe game is Over!! see you later.\n");
		return 1;
	}
	else
	{
		if (CompareWords(command[0]->C_Str(), "help"))
		{
			help();
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "open"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				entities[i]->open(entities[0], player->proompos);
			}
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "close"))
		{
			for (uint i = 0; i < entities.size(); i++)
			{
				entities[i]->close(entities[0], player->proompos);
			}
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "east"))
		{
			player->move(entities, EAST);
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "west"))
		{
			player->move(entities, WEST);
		}
		if (CompareWords(command[0]->C_Str(), "north"))
		{
			player->move(entities, NORTH);
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "south"))
		{
			player->move(entities, SOUTH);
			return 0;
		}
		if (CompareWords(command[0]->C_Str(), "go"))
		{
			if (CompareWords(command[1]->C_Str(), "east"))
			{
				player->move(entities, EAST);
				return 0;
			}
			if (CompareWords(command[1]->C_Str(), "west"))
			{
				player->move(entities, WEST);
			}
			if (CompareWords(command[1]->C_Str(), "north"))
			{
				player->move(entities, NORTH);
				return 0;
			}
			if (CompareWords(command[1]->C_Str(), "south"))
			{
				player->move(entities, SOUTH);
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