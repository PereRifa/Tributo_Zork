#include<string>
#include<iostream>
#include"Room.h"
#include"Player.h"
#include"Exit.h"

using namespace std;

#ifndef WORLD
#define WORLD

class World
{
public:
	Player* player1;
	Room* Rooms;
	Doors* Exits;

public:
	World();
	~World();
	
	void printrooms(Room* Rooms);
	void CreateWorld(Room* Rooms);
};

#endif
