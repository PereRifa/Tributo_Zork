
#ifndef _WORLD
#define _WORLD

#include<string.h>
#include"Room.h"
#include"Player.h"
#include"Exit.h"
#include"mVector.h"

class World
{
public:
	mVector<Player*> player1;
	mVector<Room*> Rooms;
	mVector<Doors*> Exits;

public:
	World();
	~World();

	void printrooms(Room* Rooms) const;
	void CreateWorld();
	void Game();
	void HelloWorld() const;
	void WriteCommands();
	int gameplay(const char* FirstWord, const char* SeconWord);
	bool CompareWords(const char* Word1, const char* Word2);
	void help() const;
	int ChangeRoom();
	int go(const char*);

};

#endif
