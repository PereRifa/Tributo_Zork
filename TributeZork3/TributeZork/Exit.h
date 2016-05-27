#ifndef _EXIT
#define _EXIT

#include "Entity.h"
#include "Room.h"


class Door : public Entity
{
public:
	bool doorstate;
	ROOMPOSITION doorposition;
	Entity* origin;
	Entity* destiny;

public:
	Door(ROOMPOSITION doorposition, Entity* origin, Entity* destiny) : doorstate(false), doorposition(doorposition), origin(origin), destiny(destiny), Entity("Laboratory Door", "Door", EXIT)
	{};
	
	void open(Room* origin, ROOMPOSITION playerposition);
	void close(Room* playerorigin, ROOMPOSITION playerposition);
};
#endif