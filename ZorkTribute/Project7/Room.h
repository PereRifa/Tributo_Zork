#include"mString.h"

#ifndef ROOM
#define ROOM

class Room
{
public:
	mString* name;
	mString* North;
	mString* South;
	mString* East;
	mString* West;

public:
	Room(const unsigned int i);
	~Room();
};
#endif