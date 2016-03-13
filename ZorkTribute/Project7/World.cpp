#include<string>
#include<iostream>
#include"Room.h"
#include"World.h"

using namespace std;

#define NUMBEROFROOMS 13
#define NUMBEROFDOORS 24

World::World()
{
	player1 = new Player;
	Rooms = new Room[NUMBEROFROOMS];
	Exits = new Doors[NUMBEROFDOORS];

	CreateWorld(Rooms);

	printrooms(Rooms);
	

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
void World::CreateWorld(Room* Rooms){
	
	//Setup Rooms Information;
	for (int i = 0; i < NUMBEROFROOMS; i++){
		switch (i){
		case 0: Rooms[i].name = "r1";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 0;
			Rooms[i].y = 0;
			break;
		case 1: Rooms[i].name = "r2";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 0;
			break;
		case 2: Rooms[i].name = "r3";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 0;
			Rooms[i].y = 1;
			break;
		case 3: Rooms[i].name = "r4";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 1;
			break;
		case 4: Rooms[i].name = "r4.1";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 0;
			Rooms[i].y = 2;
			break;
		case 5: Rooms[i].name = "r4.2";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 2;
			break;
		case 6: Rooms[i].name = "r5";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 0;
			Rooms[i].y = 3;
			break;
		case 7: Rooms[i].name = "r6";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 3;
			break;
		case 8: Rooms[i].name = "R7";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 2;
			Rooms[i].y = 3;
			break;
		case 9: Rooms[i].name = "R7.1";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 2;
			Rooms[i].y = 4;
			break;
		case 10: Rooms[i].name = "R8";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 4;
			break;
		case 11: Rooms[i].name = "R9";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 0;
			Rooms[i].y = 4;
			break; 
		case 12: Rooms[i].name = "Exit (r10)";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			Rooms[i].x = 1;
			Rooms[i].y = 5;
			break;
		}
	}

	//Setup doors information;
	for (int i = 0; i < NUMBEROFDOORS; i++){
		switch (i){
		case 0:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 0;
			Exits[i].y = 0;
			break;
		case 1:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 1;
			Exits[i].y = 0;
			break;
		case 2:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 0;
			Exits[i].y = 0;
			break;
		case 3:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 0;
			Exits[i].y = 1;
			break;
		case 4:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 0;
			Exits[i].y = 1;
			break;
		case 5:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 1;
			Exits[i].y = 1;
			break;
		case 6:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 1;
			Exits[i].y = 0;
			break;
		case 7:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 1;
			Exits[i].y = 1;
			break;
		case 8:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 0;
			Exits[i].y = 2;
			break;
		case 9:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 0;
			Exits[i].y = 3;
			break;
		case 10:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 1;
			Exits[i].y = 2;
			break;
		case 11:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 1;
			Exits[i].y = 3;
			break;
		case 12:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 1;
			Exits[i].y = 3;
			break;
		case 13:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 2;
			Exits[i].y = 3;
			break;
		case 14:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 0;
			Exits[i].y = 3;
			break;
		case 15:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 0;
			Exits[i].y = 4;
			break;
		case 16:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 0;
			Exits[i].y = 4;
			break;
		case 17:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 1;
			Exits[i].y = 4;
			break;
		case 18:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 1;
			Exits[i].y = 4;
			break;
		case 19:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 2;
			Exits[i].y = 4;
			break;
		case 20:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "South";
			Exits[i].x = 1;
			Exits[i].y = 4;
			break;
		case 21:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "North";
			Exits[i].x = 1;
			Exits[i].y = 5;
			break;
		case 22:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "West";
			Exits[i].x = 1;
			Exits[i].y = 5;
			break;
		case 23:  Exits[i].doorstate = "Open";
			Exits[i].doorroomposition = "East";
			Exits[i].x = 0;
			Exits[i].y = 5;
			break;
			}
		
	}
}