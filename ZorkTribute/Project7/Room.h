#include "Entity.h"

#ifndef _ROOM
#define _ROOM

class Room : public Entity
{
public:
	mString* North;
	mString* South;
	mString* East;
	mString* West;

public:
	Room(const unsigned int i);
	~Room();
	void Look() const;
};
#endif