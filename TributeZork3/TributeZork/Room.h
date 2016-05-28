#ifndef _ROOM
#define _ROOM

#include "Entity.h"

class Room : public Entity
{

public:
	Room(const char* name, const char* description, ETYPES type) : Entity(name, description, type){};
	void Look() const;
};
#endif