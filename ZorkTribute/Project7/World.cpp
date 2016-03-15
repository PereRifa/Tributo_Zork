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
	
	printrooms(Rooms);
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
		case 0: strcpy_s(((Rooms + i)->name), "r1");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 1: strcpy_s(((Rooms + i)->name), "r2");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 2: strcpy_s(((Rooms + i)->name), "r3");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 3: strcpy_s(((Rooms + i)->name), "r4");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 4: strcpy_s(((Rooms + i)->name), "r4.1");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 5: strcpy_s(((Rooms + i)->name), "r4.2");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 6: strcpy_s(((Rooms + i)->name), "r5");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 7: strcpy_s(((Rooms + i)->name), "r6");
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
		case 11: strcpy_s(((Rooms + i)->name), "r9");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
			break;
		case 12: strcpy_s(((Rooms + i)->name), "r10. Exit");
			strcpy_s(((Rooms + i)->North), "In the north side of this room you can see a table with some documents and research stuff.\n");
			strcpy_s(((Rooms + i)->South), "more investigation stuff and a get");
			strcpy_s(((Rooms + i)->East), "there's a door, behind it it's the bestiary");
			strcpy_s(((Rooms + i)->West), "your oun table with the results of the research, maybe you should read them.");
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
			(Exits + i)->destiny = 10;
			break; 
		case 13:  strcpy_s(((Exits + i)->doorstate), "closed");
			strcpy_s(((Exits + i)->doorroomposition), "west");
			(Exits + i)->origin = 10;
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
		SecondWord = "\0";
		do
		{
			printf("Write Command-> ");
			gets_s(Command);
			FirstWord = strtok_s(Command, " ", &TokCommand);
		} while (FirstWord == NULL);
		SecondWord = strtok_s(NULL, " ", &TokCommand);

		Exit = move(FirstWord, SecondWord, player1, Rooms, Exits);
		
	}
}

int World::move(char* FirstWord, char* SeconWord, Player* player1, Room* Rooms, Doors* Exits)
{
	if (CompareWords(FirstWord, "Quit") || CompareWords(FirstWord, "quit") || CompareWords(FirstWord, "q"))
	{
		return 1;
	}
	else
	{
		if ((CompareWords(FirstWord, "north") || CompareWords(FirstWord, "n")) && (SeconWord == NULL)){
				strcpy_s(((player1)->roomposition), "north");
		}
		if ((CompareWords(FirstWord, "south") || CompareWords(FirstWord, "s")) && (SeconWord == NULL)){
			strcpy_s(((player1)->roomposition), "south");
		}
		if ((CompareWords(FirstWord, "east") || CompareWords(FirstWord, "e")) && (SeconWord == NULL)){
			strcpy_s(((player1)->roomposition), "east");
		}
		if ((CompareWords(FirstWord, "west") || CompareWords(FirstWord, "w")) && (SeconWord == NULL)){
			strcpy_s(((player1)->roomposition), "west");
		}
		if (CompareWords(FirstWord, "go")){
			if (CompareWords(SeconWord, "north") || CompareWords(SeconWord, "n")){
				strcpy_s(((player1)->roomposition), "north");
			}
			if (CompareWords(SeconWord, "south") || CompareWords(SeconWord, "s")){
				strcpy_s(((player1)->roomposition), "south");
			}
			if (CompareWords(SeconWord, "east") || CompareWords(SeconWord, "e")){
				strcpy_s(((player1)->roomposition), "east");
			}
			if (CompareWords(SeconWord, "west") || CompareWords(SeconWord, "w")){
				strcpy_s(((player1)->roomposition), "west");
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (CompareWords(FirstWord, "look")){
			if (CompareWords(SeconWord, "north") || CompareWords(SeconWord, "n")){
				printf("\n %s", (Rooms+ player1->room)->North); //not the end;
			}
			if (CompareWords(SeconWord, "south") || CompareWords(SeconWord, "s")){
				printf("\n %s", Rooms->South);
			}
			if (CompareWords(SeconWord, "east") || CompareWords(SeconWord, "e")){
				printf("\n %s", Rooms->East);
			}
			if (CompareWords(SeconWord, "west") || CompareWords(SeconWord, "w")){
				printf("\n %s", Rooms->West);
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (CompareWords(FirstWord, "open")){
			if (CompareWords(SeconWord, "door")){
				for (int i = 0; i < NUMBEROFDOORS; i++){
					if ((player1->room == (Exits + i)->origin) && (player1->roomposition == (Exits + i)->doorroomposition))
					{
						if ((Exits + i)->doorstate == "closed"){
							for (int j = 0; j < NUMBEROFDOORS; j++){
								if ((((Exits + j)->destiny) == (Exits + i)->origin) && (((Exits + i)->origin) == (Exits + i)->destiny))
								{
									strcpy_s(((Exits + j)->doorstate), "open");
									strcpy_s(((Exits + j)->doorstate), "open");
								}
							}
							printf("\nDoor Open\n");
						}
						if ((Exits+i)->doorstate == "open"){
							printf("\nThe door is already open\n");
						}
					}
				}
					
				}
				
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (CompareWords(FirstWord, "close")){
			if (CompareWords(SeconWord, "door")){
				if (Exits->doorstate == "open"){
					Exits->doorstate = "closed";
					printf("\nDoor closed\n");
					//Not done
				}
				if (Exits->doorstate == "closed"){
					printf("\nThe door is already open\n");
				}
			}
			else{
				printf("\nThis command is not able, enter another command\n");
				return 0;
			}
		}
		if (CompareWords(FirstWord, "help") && SeconWord == NULL){
			help();
		};
	}
	return 0;

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