#include <string.h>
#include <stdio.h>
#include "mString.h"


#ifndef PLAYER
#define PLAYER

class Player
{
public:
	mString* name;
	mString* roomposition;
	int room;
	
	
public:
	Player();
	~Player();
};

#endif