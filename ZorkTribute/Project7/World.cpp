#include<string.h>
#include<iostream>
#include"World.h"

#define NUMBEROFROOMS 13
#define NUMBEROFDOORS 24

World::World()
{
	player1 = new Player();
	Rooms = new Room[NUMBEROFROOMS];
	CreateWorld();

}
World::~World()
{
	delete player1;
	delete[] Rooms;

}
void World::printrooms(Room* Rooms) const
{
	for (int i = 0; i < NUMBEROFROOMS; i++){
		printf(" %s", Rooms[i].name);
	}
}
void World::CreateWorld(){
	
	//Setup Rooms Information;
	for (int i = 0; i < NUMBEROFROOMS; i++){
		switch (i){
		case 0: strcpy_s(((Rooms + i)->name), "Laboratory I: Rise Project\n");
			strcpy_s(((Rooms + i)->North), " you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "a door that goes to the warehouse and some tables next to it with lots of investigation stuff.\n");
			strcpy_s(((Rooms + i)->East), "a door, behind it it's the bestiary\n");
			strcpy_s(((Rooms + i)->West), "your own table with the results of the research, you know everything in them ofcourse.\n");
			break;
		case 1: strcpy_s(((Rooms + i)->name), "Bestiary\n");
			strcpy_s(((Rooms + i)->North), "few jails with animals inside! make sure they are all in their jails.\n");
			strcpy_s(((Rooms + i)->South), "a door that goes to the Laboratory II: Planet project. \n");
			strcpy_s(((Rooms + i)->East), "jails in this side, some of them are broken and there are no animals left.\n");
			strcpy_s(((Rooms + i)->West), "a door that goes to your Laboratory I, where you work in the Rise project\n");
			break;
		case 2: strcpy_s(((Rooms + i)->name), "Warehouse\n");
			strcpy_s(((Rooms + i)->North), "a door that goes to your Laboratory I, where you work in the Rise project\n");
			strcpy_s(((Rooms + i)->South), "a huge shelving filled with chemical products\n");
			strcpy_s(((Rooms + i)->East), "a door that goes to the Laboratory II.\n");
			strcpy_s(((Rooms + i)->West), "multiple freezers with speciments and drugs inside.\n");
			break;
		case 3: strcpy_s(((Rooms + i)->name), "Laboratory II: Planet Project\n");
			strcpy_s(((Rooms + i)->North), "there's a door, behind it, it's the bestiary, it seems that some of them has disapeared\n");
			strcpy_s(((Rooms + i)->South), "a door that goes to the laboratory III: Ape Project\n");
			strcpy_s(((Rooms + i)->East), "Coffe machine\n");
			strcpy_s(((Rooms + i)->West), "the warehouse door and a corridor further south\n");
			break;
		case 4: strcpy_s(((Rooms + i)->name), "Laboratory II: Planet Project\n");
			strcpy_s(((Rooms + i)->North), "some tables\n");
			strcpy_s(((Rooms + i)->South), "a door that goes to the dinning room\n");
			strcpy_s(((Rooms + i)->East), "there's te rest of Laboratory II, look there's a coffe machine, some working places...\n");
			strcpy_s(((Rooms + i)->West), "A picture of a monkey in the wall, looks like an artwork\n");
			break;
		case 5: strcpy_s(((Rooms + i)->name), "Laboratory II: Planet Project\n");
			strcpy_s(((Rooms + i)->North), "there's a door, behind it it's the bestiary\n");
			strcpy_s(((Rooms + i)->South), "a door, goes to the Laboratory III: Apes Project\n");
			strcpy_s(((Rooms + i)->East), "Coffe machine\n");
			strcpy_s(((Rooms + i)->West), "the rest of the office and a gate at the end of it\n");
			break;
		case 6: strcpy_s(((Rooms + i)->name), "Bar\n");
			strcpy_s(((Rooms + i)->North), "the Laboratory II door\n");
			strcpy_s(((Rooms + i)->South), "the Dinning room for taking a break\n");
			strcpy_s(((Rooms + i)->East), "some table where you can have lunch, but now it's not that time\n");
			strcpy_s(((Rooms + i)->West), "the bar, and behind it the kitchen with its warehouse\n");
			break;
		case 7: strcpy_s(((Rooms + i)->name), "Dinning Room\n");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 8: strcpy_s(((Rooms + i)->name), "Laboratory III: of the Apes");
			strcpy_s(((Rooms + i)->North), "In the north side of this Lab there's a door to the other lab, some screams can be heard.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get\n");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the Dressing room\n");
			strcpy_s(((Rooms + i)->West), "A wall\n");
			break;
		case 9: strcpy_s(((Rooms + i)->name), "Dressing Room");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can monkeys dancing.. an amazing artwork\n");
			strcpy_s(((Rooms + i)->South), "a larg Vestuary womens at the west side and mans at the east\n");
			strcpy_s(((Rooms + i)->East), "Womens vestuary ^.^... but it is empty :/\n");
			strcpy_s(((Rooms + i)->West), "A Wall\n");
			break;
		case 10: strcpy_s(((Rooms + i)->name), "Dressing Room\n");
			strcpy_s(((Rooms + i)->North), "at the end of the room you can see monkeys dancing... an amazing artwork\n");
			strcpy_s(((Rooms + i)->South), "the end of the vestuary\n");
			strcpy_s(((Rooms + i)->East), "Womens vestuary ^.^... but it is empty :/\n");
			strcpy_s(((Rooms + i)->West), "a door to the office\n");
			break;
		case 11: strcpy_s(((Rooms + i)->name), "Office\n");
			strcpy_s(((Rooms + i)->North), "The reception of the laboratory, there is a picture of a monkey with a dress... i should leave this place -.-\n");
			strcpy_s(((Rooms + i)->South), "the end of the vestuary\n");
			strcpy_s(((Rooms + i)->East), "Dressing room you should change your dress before going to the laboratory\n");
			strcpy_s(((Rooms + i)->West), "a door that goes to the dinning room\n");
			break;
		case 12: strcpy_s(((Rooms + i)->name), "Hall\n");
			strcpy_s(((Rooms + i)->North), "a door that goes to the office room\n");
			strcpy_s(((Rooms + i)->South), "a wall\n");
			strcpy_s(((Rooms + i)->East), "a wall\n");
			strcpy_s(((Rooms + i)->West), "the exit\n");
			break;
		}
	}

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
	printf("\n\tHello!! %s\n", player1->name->C_Str());
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
	char Command[50];
	char *FirstWord;
	char *SecondWord;
	char *TokCommand;
	
	int Exit = 0;
	
	while (Exit == 0){

		SecondWord = NULL;
		do
		{
			printf("What to do now?\n\tWrite Command -> ");
			gets_s(Command);
			FirstWord = strtok_s(Command, " ", &TokCommand);
		} while (FirstWord == NULL);
		SecondWord = strtok_s(NULL, " ", &TokCommand);

		Exit = gameplay(FirstWord, SecondWord);
		
	}
}
//commands resolution (look, go, close, open) +(north, south, east, west)
int World::gameplay(const char* FirstWord,const char* SeconWord)
{

	if (CompareWords(FirstWord, "Quit") || CompareWords(FirstWord, "quit") || CompareWords(FirstWord, "q"))
	{
		printf("\nThe game is Over!! see you later.\n");
		return 1;
	}
	else
	{
		if ((CompareWords(FirstWord, "north") || CompareWords(FirstWord, "n")) && SeconWord == NULL){
			return go("north");
		}
		if ((CompareWords(FirstWord, "south") || CompareWords(FirstWord, "s")) && SeconWord == NULL){
			return go("south");
		}
		if ((CompareWords(FirstWord, "east") || CompareWords(FirstWord, "e")) && SeconWord == NULL){
			return go("east");
		}
		if ((CompareWords(FirstWord, "west") || CompareWords(FirstWord, "w")) && SeconWord == NULL){
			return go("west");
		}
		if (CompareWords(FirstWord, "go")){
			if (CompareWords(SeconWord, "north") || CompareWords(SeconWord, "n")){
				return go("north");

			}
			if (CompareWords(SeconWord, "south") || CompareWords(SeconWord, "s")){
				return go("south");

			}
			if (CompareWords(SeconWord, "east") || CompareWords(SeconWord, "e")){
				return go("east");
			}
			if (CompareWords(SeconWord, "west") || CompareWords(SeconWord, "w")){
				return go("west");
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
			return 0;
		}
		if (CompareWords(FirstWord, "look")){
			if (CompareWords(SeconWord, "north") || CompareWords(SeconWord, "n")){
				printf("\n %s\n", (Rooms + player1->room)->North);
				return 0;
			}
			if (CompareWords(SeconWord, "south") || CompareWords(SeconWord, "s")){
				printf("\n %s\n", (Rooms + player1->room)->South);
				return 0;
			}
			if (CompareWords(SeconWord, "east") || CompareWords(SeconWord, "e")){
				printf("\n %s\n", (Rooms + player1->room)->East);
				return 0;
			}
			if (CompareWords(SeconWord, "west") || CompareWords(SeconWord, "w")){
				printf("\n %s\n", (Rooms + player1->room)->West);
				return 0;
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}

		}
		if (CompareWords(FirstWord, "open")){
			if (CompareWords(SeconWord, "door")){
				for (int i = 0; i < NUMBEROFDOORS; i++){
					if (((player1)->room == Exits[i]->origin) && (*(player1->roomposition) == *(Exits[i]->doorroomposition)))
					{
						printf("roomposition: %s", *(player1->roomposition));
						printf("doorroomposition: %s", *(Exits[i]->doorroomposition));
						printf("Bool: %d", *(player1->roomposition) == *(Exits[i]->doorroomposition));
						if (Exits[i]->doorstate == false){
							for (int j = 0; j < NUMBEROFDOORS; j++){

								if (((Exits[j]->destiny) == Exits[i]->origin) && ((Exits[j]->origin) == Exits[i]->destiny))
								{
									Exits[i]->doorstate=true;
									Exits[j]->doorstate=true;
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


		if (CompareWords(FirstWord, "close")){
			if (CompareWords(SeconWord, "door")){
				for (int i = 0; i < NUMBEROFDOORS; i++){
					printf("roomposition: %s", *(player1->roomposition));
					printf("doorroomposition: %s", *(Exits[i]->doorroomposition));
					printf("Bool: %d", *(player1->roomposition) == *(Exits[i]->doorroomposition));
					if (((player1)->room == Exits[i]->origin) && (*(player1->roomposition) == *(Exits[i]->doorroomposition)))
					{
						if (Exits[i]->doorstate== true){
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
		if (CompareWords(FirstWord, "help") && SeconWord == NULL){
			help();
			return 0;
		}
		else{
			printf("\nThis command is not able, enter another command\n");
			return 0;
		}
	}
	return 0;
	
		
	
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
		if (((player1)->room == Exits[i]->origin) && (*(player1->roomposition) == *(Exits[i]->doorroomposition)))
		{
	
			if (Exits[i]->doorstate == true){
				(player1)->room = Exits[i]->destiny;
				
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

	*((player1)->roomposition) = Name;

	if ((player1->room == 10) && (Name == "north")){
		player1->room = 9;
	}
	if ((player1->room == 5) && (Name == "north")){
		player1->room = 3;
	}

	if ((player1->room == 9) && (Name == "south")){
		player1->room = 10;
	}
	if ((player1->room == 3)  && (Name == "south")){
		player1->room = 5;
	}

	if ((player1->room == 5) && (Name == "west")){
		player1->room = 4;

	}
	if ((player1->room == 12) && Exits[23]->doorstate == true && (Name == "west")){
		printf("\nYou did it!! Now you can go back home... :D\n");
		return 1;
	}

	if ((player1->room == 4) && (Name == "east")){
		player1->room = 5;

	}

	going = ChangeRoom();
	if (going == 0)
	{
		if (Name == "north"){
			*((player1)->roomposition) = "south";
		}
		if (Name == "south"){
			*((player1)->roomposition) = "north";
		}
		if (Name == "east"){
			*((player1)->roomposition) = "west";
		}
		if (Name == "west"){
			*((player1)->roomposition) = "east";
		}
		printf("\nChanged room now you are at: %s side of the %s\n", player1->roomposition->C_Str(), (Rooms + (player1->room))->name);
	}
	else {
		if (Name == "north"){
			printf("\n %s\n", (Rooms + player1->room)->North);
			return 0;
		}
		if (Name == "south"){
			printf("\n %s\n", (Rooms + player1->room)->South);
			return 0;
		}
		if (Name == "east"){
			printf("\n %s\n", (Rooms + player1->room)->East);
			return 0;
		}
		if (Name == "west"){
			printf("\n %s\n", (Rooms + player1->room)->West);
			return 0;
		}
	}
	return 0;
}