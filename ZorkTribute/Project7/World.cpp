#include<string>
#include<iostream>
#include"Room.h"
#include"World.h"

using namespace std;

World::World()
{
	player1 = new Player;
	Rooms = new Room[10];
	Exits = new Doors[10];

	CreateWorld(Rooms);

	printrooms(Rooms);
	

}

World::~World()
{
	delete[] Rooms;
}

void World::printrooms(Room* Rooms){
	for (int i = 0; i < 10; i++){
		cout << Rooms[i].name << endl;
	}
}
void World::CreateWorld(Room* Rooms){
	for (int i = 0; i < 10; i++){
		switch (i){
		case 0: Rooms[i].name = "r0";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 1: Rooms[i].name = "r1";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 2: Rooms[i].name = "r2";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 3: Rooms[i].name = "r3";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 4: Rooms[i].name = "r4";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 5: Rooms[i].name = "r5";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 6: Rooms[i].name = "r6";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 7: Rooms[i].name = "r7";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 8: Rooms[i].name = "R8";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		case 9: Rooms[i].name = "Exit";
			Rooms[i].North = "In the north side of this room you can see a table with some documents and research stuff.\n";
			Rooms[i].South = "more investigation stuff and a get";
			Rooms[i].East = "there's a door, behind it it's the bestiary";
			Rooms[i].West = "your oun table with the results of the research, maybe you should read them.";
			break;
		}
	}
}