
#ifndef _WORLD
#define _WORLD

#include<string.h>
#include"Room.h"

#include"Exit.h"
#include"mVector.h"

#define INITIALALLOCATION 40

class World
{
public:
	mVector<Entity*> entities;


public:
	World();
	~World();

	void CreateWorld();
	void Game();
	/*
	void printrooms(Room* Rooms) const;
	void CreateWorld();
	void Game();
	void HelloWorld() const;
	void WriteCommands();
	int gameplay(const mVector<mString*>& command);
	bool CompareWords(const char* Word1, const char* Word2);
	void help() const;
	int ChangeRoom();
	int go(const char*);
	*/
};

#endif
