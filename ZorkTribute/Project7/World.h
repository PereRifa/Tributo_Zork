#include<string.h>
#include<iostream>
#include"Room.h"
#include"Player.h"
#include"Exit.h"


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

	void printrooms(Room* Rooms) const;
	void CreateWorld();
	void Game();
	void HelloWorld() const;
	void WriteCommands();
	int gameplay(char* FirstWord, char* SeconWord);
	bool CompareWords(const char* Word1, const char* Word2);
	void help() const;
	int ChangeRoom();
	int go(char*);

};

#endif
