
#ifndef _WORLD
#define _WORLD

#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <string.h>
#include <Windows.h>
#include <time.h>
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "mVector.h"

#define INITIALALLOCATION 40
#define DELAY 1000
#define COMMANDBUFFER 50

class World
{
public:
	mVector<Entity*> entities;
	Player* player;

public:
	World();
	~World();

	void CreateWorld();
	void Game();
	int WriteCommands(const char* command);
	int gameplay(const mVector<mString*>& command);
	bool CompareWords(const char* Word1, const char* Word2);
	void help() const;
	
	/*
	
	void HelloWorld() const;

	int ChangeRoom();
	int go(const char*);
	*/
};

#endif
