#include"World.h"

#define NUMBEROFROOMS 13
#define NUMBEROFDOORS 24

World::World()
{
	
	CreateWorld();

}
World::~World()
{
	for (int i = 0; i < NUMBEROFROOMS; i++)
	{
		delete Rooms[i];
	}
	Rooms.clean();
	for (int i = 0; i < 6; i++)
	{
		delete Items[i];
	}
	Items.clean();
	for (int i = 0; i < NUMBEROFDOORS; i++)
	{
		delete Exits[i];
	}
	Exits.clean();
	delete player1[0];
	player1.clean();
	
}
void World::printrooms(Room* Rooms) const
{
	for (int i = 0; i < NUMBEROFROOMS; i++){
		printf(" %s", Rooms[i].name);
	}
}
void World::CreateWorld(){

	//setup player infromation;
	player1.pushback(new Player("Dean Whinchester", "fucking Badass"));
	
	//Setup Rooms Information;
	for (int i = 0; i < NUMBEROFROOMS; i++){
		Rooms.pushback(new Room(i));
	}
	//Setup Items
	Items.pushback(new Item("Inventory","you can put other items in to it"));
	Items.pushback(new Item("potato", "stupid sexy potato"));
	Items.pushback(new Item("chicken", "best food for niggas"));
	Items.pushback(new Item("glass", "stupid sexy potato"));
	Items.pushback(new Item("tity", "best food for niggas"));
	Items.pushback(new Item("popo", "you can put other items in to it"));
	player1[0]->insert(Items[1]);
	player1[0]->insert(Items[2]);
	player1[0]->insert(Items[3]);
	player1[0]->insert(Items[4]);
	player1[0]->insert(Items[5]);
	player1[0]->Look();
	//Setup Exits information;
	Exits.pushback(new Doors("east", 0, 1));
	Exits.pushback(new Doors("west", 1, 0));
	
	Exits.pushback(new Doors("south", 0, 2));
	Exits.pushback(new Doors("north", 2, 0));
	
	Exits.pushback(new Doors("east", 2, 3));
	Exits.pushback(new Doors("west", 3, 2));
	
	Exits.pushback(new Doors( "south", 1, 3));
	Exits.pushback(new Doors("north", 3, 1));
	
	Exits.pushback(new Doors("south", 4, 6));
	Exits.pushback(new Doors("north", 6, 4));
	
	Exits.pushback(new Doors("south", 6, 7));
	Exits.pushback(new Doors("north", 7, 6));
	
	Exits.pushback(new Doors("east", 7, 11));
	Exits.pushback(new Doors("west", 11, 7));
	
	Exits.pushback(new Doors("south", 5, 8));
	Exits.pushback(new Doors("north", 8, 5));
	
	Exits.pushback(new Doors("east", 8, 9));
	Exits.pushback(new Doors("west", 9, 8));
	
	Exits.pushback(new Doors("west", 10, 11));
	Exits.pushback(new Doors("east", 11, 10));

	Exits.pushback(new Doors("south", 11, 12));
	Exits.pushback(new Doors("north", 12, 11));
	
	Exits.pushback(new Doors("west", 12, 13));
	Exits.pushback(new Doors("east", 13, 12));
	
}
//Execute the game
void World::Game(){
	HelloWorld();
	WriteCommands();
}
//Print initial screen info
void World::HelloWorld() const
{
	printf("\n\tHello!! %s\n", player1[0]->name->C_Str());
	getchar();
	printf("\tYou come back to the underground laboratory you worked one year ago.\n");
	printf("This last year the laboratory had developed new pharmaceutical products in \n");
	printf("order to treat violent behavior in some people. Of course they haven not\n");
	printf(" tried them with humans yet! just with some monkeys, gorillas and chimpanzees.\n");
	printf("They keep the wild animals in the deepest room of the laboratory next to the research\n");
	printf("room where you’re now with Mr.Graham and Mrs.Diane doing your best to help humanity.\n");
	getchar();
	printf("\nAt the evening just before the end of the working day...\n");
	printf("\n*loud noise*\n");
	printf("\nhuh what was that!? it's comming from the room right behind you (east)\n");
	
	printf("\nThe sound of something breaking in to pieces followed by unhuman screams.\n");
	printf("\nHoly shit, some of the animals must have escaped, you’re in danger.\n");
	getchar();
	printf("It is time to get the hell out!!\n\n");
	getchar();
	printf("\tThe animals in the cages were very aggressive and now they run free around the\n");
	printf("laboratory. Maybe you will need some kind of weapons in order to keep all of you\n");
	printf("safe.Do not give up and do your best to pull out from the building the team of\n");
	printf("scientists, alive.\n");
	getchar();
}
//function to write player commands
void World::WriteCommands()
{
	
	int Exit = 0;
	char line[50];
	mString* commands;
	while (Exit == 0){
		printf("What to do now?\n\tWrite Command -> ");
		gets_s(line);
		commands = new mString(line);
		mVector<mString*> vcommands;
		commands->tokenize(vcommands);
		delete commands;
		Exit = gameplay(vcommands);
		for (int i = 0; i < vcommands.size(); i++)
		{
			delete vcommands[i];
		}
		vcommands.clean();
	}
}
//commands resolution (look, go, close, open) +(north, south, east, west)
int World::gameplay(const mVector<mString*>& commands)
{
	//const char* commands[0]->C_Str() = commands[0]->C_Str();

	if ((CompareWords(commands[0]->C_Str(), "Quit")) || (CompareWords(commands[0]->C_Str(), "quit")) || (CompareWords(commands[0]->C_Str(), "q")))
	{
		printf("\nThe game is Over!! see you later.\n");
		return 1;
	}
	else
	{
		if (commands.size() == 1){
			if (CompareWords(commands[0]->C_Str(), "north") || CompareWords(commands[0]->C_Str(), "n")){
				return go("north");
			}
			if (CompareWords(commands[0]->C_Str(), "south") || CompareWords(commands[0]->C_Str(), "s")){
				return go("south");
			}
			if (CompareWords(commands[0]->C_Str(), "east") || CompareWords(commands[0]->C_Str(), "e")){
				return go("east");
			}
			if (CompareWords(commands[0]->C_Str(), "west") || CompareWords(commands[0]->C_Str(), "w")){
				return go("west");
			}
			if (CompareWords(commands[0]->C_Str(), "help")){
				help();
				return 0;
			}
			if ((CompareWords(commands[0]->C_Str(), "inventory")) || (CompareWords(commands[0]->C_Str(), "inv")) || (CompareWords(commands[0]->C_Str(), "i"))){
				player1[0]->Look();
				return 0;
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (commands.size() == 2){
			//const char* commands[1]->C_Str() = commands[1]->C_Str();

			if (CompareWords(commands[0]->C_Str(), "go")){
				if (CompareWords(commands[1]->C_Str(), "north") || CompareWords(commands[1]->C_Str(), "n")){
					return go("north");

				}
				if (CompareWords(commands[1]->C_Str(), "south") || CompareWords(commands[1]->C_Str(), "s")){
					return go("south");

				}
				if (CompareWords(commands[1]->C_Str(), "east") || CompareWords(commands[1]->C_Str(), "e")){
					return go("east");
				}
				if (CompareWords(commands[1]->C_Str(), "west") || CompareWords(commands[1]->C_Str(), "w")){
					return go("west");
				}
				else{
					printf("\nThis command is not able, enter another command\n");
					return 0;
				}
				return 0;
			}
			if (CompareWords(commands[0]->C_Str(), "look")){
				if (CompareWords(commands[1]->C_Str(), "north") || CompareWords(commands[1]->C_Str(), "n")){
					printf("\n %s\n", Rooms[player1[0]->room]->North->C_Str());
					return 0;
				}
				if (CompareWords(commands[1]->C_Str(), "south") || CompareWords(commands[1]->C_Str(), "s")){
					printf("\n %s\n", Rooms[player1[0]->room]->South->C_Str());
					return 0;
				}
				if (CompareWords(commands[1]->C_Str(), "east") || CompareWords(commands[1]->C_Str(), "e")){
					printf("\n %s\n", Rooms[player1[0]->room]->East->C_Str());
					return 0;
				}
				if (CompareWords(commands[1]->C_Str(), "west") || CompareWords(commands[1]->C_Str(), "w")){
					printf("\n %s\n", Rooms[player1[0]->room]->West->C_Str());
					return 0;
				}
				else{
					printf("\nThis command is not able, enter another command\n");
					return 0;
				}

			}
			if (CompareWords(commands[0]->C_Str(), "pick"))
			{
				if (player1[0]->objectpicked == true){
					printf("\nYou already have one item, can not pick more than one at same time\n");
					return 0;
				}
				for (unsigned int i = 0; i < Items.size(); i++){
					if (CompareWords(commands[1]->C_Str(), Items[i]->name->C_Str())){
						Items[i]->took = true;
						player1[0]->objectpicked = true;
						printf("\nItem taken\n");
						return 0;
					}
				}
				printf("\nIt must be an item to pick it\n");
				return 0;
			}
			if (CompareWords(commands[0]->C_Str(), "drop"))
			{
				if (player1[0]->objectpicked == false){
					printf("\nYou do not have any item to drop\n");
					return 0;
				}
				for (unsigned int i = 0; i < Items.size(); i++){
					if (CompareWords(commands[1]->C_Str(), Items[i]->name->C_Str())&& Items[i]->took == true){
						Items[i]->took = false;
						player1[0]->objectpicked = false;
						printf("\nItem droped\n");
						return 0;
					}
				}
					printf("\nYou can not drop that\n");
					return 0;
			}
			if (CompareWords(commands[0]->C_Str(), "equip"))
			{
				if (player1[0]->equiped == true){
					printf("\nYou already have one item equiped, unequip it to equip another\n");
					return 0;
				}
				if (player1[0]->objectpicked == true){
					for (unsigned int i = 0; i < Items.size(); i++){
						if (CompareWords(commands[1]->C_Str(), Items[i]->name->C_Str()) && (Items[i]->took == true)){
							Items[i]->equiped = true;
							player1[0]->equiped = true;
							printf("\nItem equiped\n");
							Items[i]->took = false;
							player1[0]->objectpicked = false;
							return 0;
						}
					}
				}
				printf("\nIt must be an item you have to equip it\n");
				return 0;
			}
			if (CompareWords(commands[0]->C_Str(), "unequip"))
			{
				if (player1[0]->equiped == false){
					printf("\nYou do not have any item equiped\n");
					return 0;
				}
				if (player1[0]->equiped == true){
					for (unsigned int i = 0; i < Items.size(); i++){
						if (CompareWords(commands[1]->C_Str(), Items[i]->name->C_Str()) && (Items[i]->equiped == true)){
							Items[i]->equiped = false;
							player1[0]->equiped = false;
							printf("\nItem unequiped\n");
							Items[i]->took = true;
							player1[0]->objectpicked = true;
							return 0;
						}
					}
				}
				printf("\nYou can not unequip that, remember it must be an equiped item and be able to pick it after\n");
				return 0;
			}

			if (CompareWords(commands[0]->C_Str(), "open")){
				if (CompareWords(commands[1]->C_Str(), "door")){
					for (int i = 0; i < NUMBEROFDOORS; i++){
						if ((player1[0]->room == Exits[i]->origin) && (*(player1[0]->roomposition) == *(Exits[i]->doorroomposition)))
						{
							if (Exits[i]->doorstate == false){
								for (int j = 0; j < NUMBEROFDOORS; j++){

									if (((Exits[j]->destiny) == Exits[i]->origin) && ((Exits[j]->origin) == Exits[i]->destiny))
									{
										Exits[i]->doorstate = true;
										Exits[j]->doorstate = true;
										printf("\nDoor Open\n");
										return 0;
									}
								}

							}
							if (Exits[i]->doorstate == true){
								printf("\nThe door is already open\n");
								return 0;
							}
						}
					}

				}
				else{
					printf("\nThis command is not able, enter another command\n");
					return 0;
				}
				return 0;
			}


			if (CompareWords(commands[0]->C_Str(), "close")){
				if (CompareWords(commands[1]->C_Str(), "door")){
					for (int i = 0; i < NUMBEROFDOORS; i++){
						if ((player1[0]->room == Exits[i]->origin) && (*(player1[0]->roomposition) == *(Exits[i]->doorroomposition)))
						{
							if (Exits[i]->doorstate == true){
								for (int j = 0; j < NUMBEROFDOORS; j++){

									if (((Exits[j]->destiny) == Exits[i]->origin) && ((Exits[j]->origin) == Exits[i]->destiny))
									{
										Exits[i]->doorstate = false;
										Exits[j]->doorstate = false;
										printf("\nDoor closed\n");
										return 0;
									}
								}

							}
							if (Exits[i]->doorstate == false){
								printf("\nThe door is already closed\n");
							}
						}
					}
				}
				else{
					printf("\nThis command is not able, enter another command\n");
					return 0;
				}
				return 0;
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (commands.size() == 4){
			//const char* commands[1]->C_Str() = commands[1]->C_Str();
			//const char* commands[2]->C_Str() = commands[2]->C_Str();
			//const char* commands[3]->C_Str() = commands[3]->C_Str();
			if ((CompareWords(commands[0]->C_Str(), "put")) && (CompareWords(commands[2]->C_Str(), "into")))
			{
				if (player1[0]->objectpicked == true)
				{
					if ((CompareWords(commands[3]->C_Str(), "inventory")) && (player1[0]->list.size() < 5))
					{
						for (unsigned int i = 0; i < Items.size(); i++)
						{
							if (CompareWords(Items[i]->name->C_Str(), commands[1]->C_Str()) && Items[i]->took == true)
							{
								Items[i]->took = false;
								player1[0]->objectpicked = false;
								player1[0]->insert(Items[i]);
								printf("\nyou stored the item into the inventory\n");
								return 0;
							}
							
						}
					}
					else if ((player1[0]->list.size() == 5))
					{
						printf("\nInventory full\n");
						return 0;
					}
					else
					{
						printf("\nYou do not have any item that can be stored\n");
						return 0;
					}
				}
				else {
					printf("\nYou can't do that");
				}
				return 0;
			}
			if ((CompareWords(commands[0]->C_Str(), "get")) && (CompareWords(commands[2]->C_Str(), "from")))
			{
				if (player1[0]->objectpicked == false)
				{
					if (CompareWords(commands[3]->C_Str(), "inventory"))
					{
						for (unsigned int i = 0; i < Items.size(); i++)
						{
							if (CompareWords(Items[i]->name->C_Str(), commands[1]->C_Str())&& Items[i]->took == false)
							{
								for (unsigned int j = 0; j < player1[0]->list.size(); j++)
								{
									if (CompareWords(Items[i]->name->C_Str(), commands[1]->C_Str()))
									{
										player1[0]->remove(Items[i]);
										Items[i]->took = true;
										player1[0]->objectpicked = true;
										printf("\nyou picked the item from your inventory\n");
										return 0;
									}
									else if (j == player1[0]->list.size()-1){
										printf("\nYou do not have any item called like that in the inventory\n");
										return 0;
									}
								}
							}
							
						}
					}
				}

			}
			else printf("\nThis command is not able, enter another command\n");
			return 0;
			
		}
		else printf("\nThis command is not able, enter another command\n");
		return 0;


	}
}
//compare two words
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
//print help menu
void World::help() const{
	printf("\n\tHelp Menu:\n");
	printf("\nHurry up and get out of this place!!\n\nFor the escape you can use the commands: look, go, open, close, help, quit.\n");
	printf("and the directions: north, south, east, west.\n");

}
//function to change room
int World::ChangeRoom()
{
	for (int i = 0; i < NUMBEROFDOORS; i++){
		if ((player1[0]->room == Exits[i]->origin) && (*(player1[0]->roomposition) == *(Exits[i]->doorroomposition)))
		{
	
			if (Exits[i]->doorstate == true){
				player1[0]->room = Exits[i]->destiny;
				
				return 0;
			}
		}
	} 
	return 1;
}
//go or move 
int World::go(const char* Name)
{
	int going = 1;

	*(player1[0]->roomposition) = Name;

	if ((player1[0]->room == 10) && (Name == "north")){
		player1[0]->room = 9;
	}
	if ((player1[0]->room == 5) && (Name == "north")){
		player1[0]->room = 3;
	}

	if ((player1[0]->room == 9) && (Name == "south")){
		player1[0]->room = 10;
	}
	if ((player1[0]->room == 3) && (Name == "south")){
		player1[0]->room = 5;
	}

	if ((player1[0]->room == 5) && (Name == "west")){
		player1[0]->room = 4;

	}
	if ((player1[0]->room == 12) && Exits[23]->doorstate == true && (Name == "west")){
		printf("\nYou did it!! Now you can go back home... :D\n");
		return 1;
	}

	if ((player1[0]->room == 4) && (Name == "east")){
		player1[0]->room = 5;

	}

	going = ChangeRoom();
	if (going == 0)
	{
		if (Name == "north"){
			*(player1[0]->roomposition) = "south";
		}
		if (Name == "south"){
			*(player1[0]->roomposition) = "north";
		}
		if (Name == "east"){
			*(player1[0]->roomposition) = "west";
		}
		if (Name == "west"){
			*(player1[0]->roomposition) = "east";
		}
		printf("\nChanged room now you are at: %s side of the %s\n", player1[0]->roomposition->C_Str(), Rooms[player1[0]->room]->name->C_Str());
	}
	else {
		if (Name == "north"){
			printf("\n %s\n", Rooms[player1[0]->room]->North->C_Str());
			return 0;
		}
		if (Name == "south"){
			printf("\n %s\n", Rooms[player1[0]->room]->South->C_Str());
			return 0;
		}
		if (Name == "east"){
			printf("\n %s\n", Rooms[player1[0]->room]->East->C_Str());
			return 0;
		}
		if (Name == "west"){
			printf("\n %s\n", Rooms[player1[0]->room]->West->C_Str());
			return 0;
		}
	}
	return 0;
}