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
	void CreateWorld();
	void HelloWorld();
	void WriteCommands();
	int gameplay(char* FirstWord, char* SeconWord);
	bool CompareWords(char* Word1, char* Word2);
	void help();
	int ChangeRoom();
	int goeast();
	int gowest();
	int gonorth();
	int gosouth();
};

#endif
