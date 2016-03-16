#include <string.h>
#include <stdio.h>



#ifndef PLAYER
#define PLAYER

class Player
{
public:
	char name[20];
	int room;
	char roomposition[10];
	
public:
	Player();
	~Player();
};

#endif