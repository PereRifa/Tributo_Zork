#ifndef _EXIT
#define _EXIT

#include "Entity.h"
#include "Room.h"


class Door : public Entity
{
public:
	bool doorstate;
	ROOMPOSITION doorposition;
	Room* origin;
	Room* destiny;

public:
	Door(ROOMPOSITION doorposition, Room* origin, Room* destiny) : doorstate(false), doorposition(doorposition), origin(origin), destiny(destiny), Entity("Laboratory Door", "Door", EXIT)
	{};
	~Door();
	void open(Room* origin, ROOMPOSITION playerposition);
	void close(Room* playerorigin, ROOMPOSITION playerposition);
};
#endif