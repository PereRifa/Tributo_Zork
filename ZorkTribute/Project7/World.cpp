#include<string.h>
#include<iostream>
#include"World.h"

#define NUMBEROFROOMS 13
#define NUMBEROFDOORS 24

World::World()
{
	player1 = new Player;
	Rooms = new Room[NUMBEROFROOMS];
	Exits = new Doors[NUMBEROFDOORS];

	CreateWorld();
	
	HelloWorld();
	WriteCommands();
}
World::~World()
{
	delete player1;
	delete[] Rooms;
	delete[] Exits;
}
void World::printrooms(Room* Rooms){
	for (int i = 0; i < NUMBEROFROOMS; i++){
		cout << Rooms[i].name << endl;
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

	//Setup doors information;
	for (int i = 0; i < NUMBEROFDOORS; i++){
		switch (i){

		case 0:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 0;
			(Exits + i)->destiny = 1;
			break;
		case 1: strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 1;
			(Exits + i)->destiny = 0;
			break;


		case 2:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 0;
			(Exits + i)->destiny = 2;
			break;
		case 3:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 2;
			(Exits + i)->destiny = 0;
			break;


		case 4:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 2;
			(Exits + i)->destiny = 3;
			break;
		case 5:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 3;
			(Exits + i)->destiny = 2;
			break; 


		case 6:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 1;
			(Exits + i)->destiny = 3;
			break; 
		case 7:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 3;
			(Exits + i)->destiny = 1;
			break;


		case 8:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 4;
			(Exits + i)->destiny = 6;
			break;
		case 9:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 6;
			(Exits + i)->destiny = 4;
			break;


		case 10:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 6;
			(Exits + i)->destiny = 7;
			break;
		case 11:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 7;
			(Exits + i)->destiny = 6;
			break;


		case 12:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 7;
			(Exits + i)->destiny = 11;
			break; 
		case 13:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 11;
			(Exits + i)->destiny = 7;
			break;


		case 14:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 5;
			(Exits + i)->destiny = 8;
			break; 
		case 15:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 8;
			(Exits + i)->destiny = 5;
			break;


		case 16:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 8;
			(Exits + i)->destiny = 9;
			break; 
		case 17:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 9;
			(Exits + i)->destiny = 8;
			break;


		case 18:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 10;
			(Exits + i)->destiny = 11;
			break; 
		case 19:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 11;
			(Exits + i)->destiny = 10;
			break; 


		case 20:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "south");
			(Exits + i)->origin = 11;
			(Exits + i)->destiny = 12;
			break; 
		case 21:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "north");
			(Exits + i)->origin = 12;
			(Exits + i)->destiny = 11;
			break;

		case 22:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 12;
			(Exits + i)->destiny = 13;
			break; 
		case 23:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "east");
			(Exits + i)->origin = 13;
			(Exits + i)->destiny = 12;
			break; 
			}
		
	}
	
}
//Print initial screen info
void World::HelloWorld()
{
	printf("\n\tHello!! %s\n", player1->name);
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
int World::gameplay(char* FirstWord, char* SeconWord)
{

	if (CompareWords(FirstWord, "Quit") || CompareWords(FirstWord, "quit") || CompareWords(FirstWord, "q"))
	{
		return 1;
	}
	else
	{
		if ((CompareWords(FirstWord, "north") || CompareWords(FirstWord, "n")) && SeconWord == NULL){
			return gonorth();
		}
		if ((CompareWords(FirstWord, "south") || CompareWords(FirstWord, "s")) && SeconWord == NULL){
			return gosouth();
		}
		if ((CompareWords(FirstWord, "east") || CompareWords(FirstWord, "e")) && SeconWord == NULL){
			return goeast();
		}
		if ((CompareWords(FirstWord, "west") || CompareWords(FirstWord, "w")) && SeconWord == NULL){
			return gowest();
		}
		if (CompareWords(FirstWord, "go")){
			if (CompareWords(SeconWord, "north") || CompareWords(SeconWord, "n")){
				return gonorth();

			}
			if (CompareWords(SeconWord, "south") || CompareWords(SeconWord, "s")){
				return gosouth();

			}
			if (CompareWords(SeconWord, "east") || CompareWords(SeconWord, "e")){
				return goeast();
			}
			if (CompareWords(SeconWord, "west") || CompareWords(SeconWord, "w")){
				return gowest();
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
					if (((player1)->room == (Exits + i)->origin) && (CompareWords((Exits + i)->doorroomposition, (player1)->roomposition)))
					{
						if (CompareWords((Exits + i)->doorstate, "closed")){
							for (int j = 0; j < NUMBEROFDOORS; j++){

								if ((((Exits + j)->destiny) == (Exits + i)->origin) && (((Exits + j)->origin) == (Exits + i)->destiny))
								{
									strcpy_s(((Exits + i)->doorstate), "open");
									strcpy_s(((Exits + j)->doorstate), "open");
									printf("\nDoor Open\n");
									return 0;
								}
							}

						}
						if (CompareWords((Exits + i)->doorstate, "open")){
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
					if (((player1)->room == (Exits + i)->origin) && (CompareWords((Exits + i)->doorroomposition, (player1)->roomposition)))
					{
						if (CompareWords((Exits + i)->doorstate, "open")){
							for (int j = 0; j < NUMBEROFDOORS; j++){

								if ((((Exits + j)->destiny) == (Exits + i)->origin) && (((Exits + j)->origin) == (Exits + i)->destiny))
								{
									strcpy_s(((Exits + i)->doorstate), "closed");
									strcpy_s(((Exits + j)->doorstate), "closed");
									printf("\nDoor closed\n");
									return 0;
								}
							}

						}
						if (CompareWords((Exits + i)->doorstate, "closed")){
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
bool World::CompareWords(char* Word1, char* Word2)
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
	}
	else return false;

}
//print help menu
void World::help(){
	printf("\n\tHelp Menu:\n");
	printf("\nHurry up and get out of this place!!\n\nFor the escape you can use the commands: look, go, open, close, help, quit.\n");
	printf("and the directions: north, south, east, west.\n");

}
//function to change room
int World::ChangeRoom()
{
	for (int i = 0; i < NUMBEROFDOORS; i++){
		if (((player1)->room == (Exits + i)->origin) && (CompareWords((Exits + i)->doorroomposition, (player1)->roomposition)))
		{
	
			if (CompareWords((Exits + i)->doorstate, "open")){
				(player1)->room = (Exits + i)->destiny;
				
				return 0;
			}
		}
	} 
	return 1;
}
//move north
int World::gonorth()
{
	int going = 1;
	strcpy_s(((player1)->roomposition), "north");
	if (player1->room == 10){
		player1->room = 9;

	}
	if (player1->room == 5){
		player1->room = 3;
	}
	going = ChangeRoom();
	if (going == 0)
	{
		strcpy_s(((player1)->roomposition), "south");
		printf("\nChanged room now you are at: %s side of the %s\n", player1->roomposition, (Rooms + (player1->room))->name);
	}
	else {
		printf("\nIn fron of you, you can see %s\n", (Rooms + (player1->room))->North);
	}
	return 0;
}
//move south
int World::gosouth()
{
	int going = 1;
	strcpy_s(((player1)->roomposition), "south");
	if (player1->room == 9){
		player1->room = 10;

	}
	if (player1->room == 3){
		player1->room = 5;
	
	}
	going = ChangeRoom();
	if (going == 0)
	{
		strcpy_s(((player1)->roomposition), "north");
		printf("\nChanged room now you are at: %s side of the %s\n", player1->roomposition, (Rooms + (player1->room))->name);
	}
	else {
		printf("\nIn fron of you, you can see %s\n", (Rooms + (player1->room))->South);
	}
	return 0;
}
//move west
int World::gowest()
{
	int going = 1;
	strcpy_s(((player1)->roomposition), "west");
	if (player1->room == 5){
		player1->room = 4;
	
	}
	if ((player1->room == 12) && (CompareWords((Exits + 23)->doorstate, "open"))){
		printf("\nYou did it!! Now you can go back home... :D\n");
		return 1;
	}
	going = ChangeRoom();
	if (going == 0)
	{
		strcpy_s(((player1)->roomposition), "east");
		printf("\nChanged room now you are at: %s side of the %s\n", player1->roomposition, (Rooms + (player1->room))->name);
	}
	else {
		printf("\nIn fron of you, you can see %s\n", (Rooms + (player1->room))->West);
	}
	return 0;
}
//move east
int World::goeast()
{
	int going = 1;
	strcpy_s(((player1)->roomposition), "east");
	if (player1->room == 4){
		player1->room = 5;

	}
	going = ChangeRoom();
	if (going == 0)
	{
		strcpy_s(((player1)->roomposition), "west");
		printf("\nChanged room now you are at: %s side of the %s\n", player1->roomposition, (Rooms + (player1->room))->name);
	}
	else {
		printf("\nIn fron of you, you can see %s\n", (Rooms + (player1->room))->East);
	}

	return 0;
}