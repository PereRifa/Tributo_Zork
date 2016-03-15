#include<string.h>
#include<iostream>
#include"Room.h"
#include"World.h"



#define NUMBEROFROOMS 13
#define NUMBEROFDOORS 24

World::World()
{
	player1 = new Player;
	Rooms = new Room[NUMBEROFROOMS];
	Exits = new Doors[NUMBEROFDOORS];

	CreateWorld();
	
	
	WriteCommands();
	//printrooms(Rooms);
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
		case 0: strcpy_s(((Rooms + i)->name), "Laboratory: 1\n");
			strcpy_s(((Rooms + i)->North), " you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "a door and some tables next to it with lots of investigation stuff.\n");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary\n");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, you know everything in them ofcourse.\n");
			break;
		case 1: strcpy_s(((Rooms + i)->name), "Bestiary\n");
			strcpy_s(((Rooms + i)->North), "few jails with animals inside! make sure they are all in their jails.\n");
			strcpy_s(((Rooms + i)->South), "a door withing the office. hmm some coffe would be great now, or maybe not. :/\n");
			strcpy_s(((Rooms + i)->East), "more jails in this side, it seems they are all okey.\n");
			strcpy_s(((Rooms + i)->West), "a door that goes to your laboratory (laboratory n.1)\n");
			break;
		case 2: strcpy_s(((Rooms + i)->name), "Warehouse\n");
			strcpy_s(((Rooms + i)->North), "a door that goes to your laboratory (laboratory n.1)\n");
			strcpy_s(((Rooms + i)->South), "a huge shelving filled with chemical products\n");
			strcpy_s(((Rooms + i)->East), "a door to go to the office: hmm some coffe would be great now, :D.\n");
			strcpy_s(((Rooms + i)->West), "multiple freezers with speciments and drugs inside.\n");
			break;
		case 3: strcpy_s(((Rooms + i)->name), "Office\n");
			strcpy_s(((Rooms + i)->North), "there's a door, behind it it's the bestiary\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get\n");
			strcpy_s(((Rooms + i)->East), "Coffe machine\n");
			strcpy_s(((Rooms + i)->West), "the warehouse door and a corridor further south\n");
			break;
		case 4: strcpy_s(((Rooms + i)->name), "Office");
			strcpy_s(((Rooms + i)->North), "some tables with where officers usualy work\n");
			strcpy_s(((Rooms + i)->South), "a door that goes to the dinning room\n");
			strcpy_s(((Rooms + i)->East), "there's te rest of office room, coffe machine, some working places...\n");
			strcpy_s(((Rooms + i)->West), "a wall\n");
			break;
		case 5: strcpy_s(((Rooms + i)->name), "Office");
			strcpy_s(((Rooms + i)->North), "there's a door, behind it it's the bestiary\n");
			strcpy_s(((Rooms + i)->South), "a door, goes to the room 8");
			strcpy_s(((Rooms + i)->East), "Coffe machine\n");
			strcpy_s(((Rooms + i)->West), "the rest of the office and a gate at the end of it\n");
			break;
		case 6: strcpy_s(((Rooms + i)->name), "Dinning Room");
			strcpy_s(((Rooms + i)->North), "the office's door\n");
			strcpy_s(((Rooms + i)->South), "the rest room for taking a nap\n");
			strcpy_s(((Rooms + i)->East), "some table where you can have lunch, but now it's not that time\n");
			strcpy_s(((Rooms + i)->West), "the bar, and behind it the kitchen with its warehouse\n");
			break;
		case 7: strcpy_s(((Rooms + i)->name), "Nap Room");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 8: strcpy_s(((Rooms + i)->name), "r7");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 9: strcpy_s(((Rooms + i)->name), "r8");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 10: strcpy_s(((Rooms + i)->name), "r8.1");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 11: strcpy_s(((Rooms + i)->name), "library");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 12: strcpy_s(((Rooms + i)->name), "Laboratory entrance");
			strcpy_s(((Rooms + i)->North), "a door that goes to the previous room\n");
			strcpy_s(((Rooms + i)->South), "nothing");
			strcpy_s(((Rooms + i)->East), "nothing");
			strcpy_s(((Rooms + i)->West), "Exit\n");
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

		Exit = move(FirstWord, SecondWord/*, player1, Rooms, Exits*/);
		
	}
}

int World::move(char* FirstWord, char* SeconWord/*, Player* player1, Room* Rooms, Doors* Exits*/)
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
				printf("\n %s\n", (Rooms + player1->room)->North); //not the end;
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
						if (CompareWords((Exits+i)->doorstate, "closed")){
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
		else printf("\nThis command is not able, enter another command\n");
		return 0;
	}
}
bool World::CompareWords(char* Word1, char* Word2)
{
	int count = 0;
	if (Word1 != NULL){
		while (*Word1++){
			*Word2++;
			if (*Word1 != *Word2)
			{
				count = 1;
				return false;
			}
		}
		if (count == 0)
		{
			return true;
		}
	}
	else return false;

}
void World::help(){
	printf("\nHelp Menu:\n");
}
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