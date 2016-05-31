#ifndef _EXIT
#define _EXIT

#include "Entity.h"
#include "Room.h"
#include "Player.h"

class Door : public Entity
{
public:
	bool doorstate;
	ROOMPOSITION doorposition;
	ROOMPOSITION othersidedoor;
	Entity* origin;
	Entity* destiny;

public:
	Door(ROOMPOSITION doorposition, ROOMPOSITION otherside, Entity* origin, Entity* destiny) : doorstate(false), doorposition(doorposition), othersidedoor(otherside), origin(origin), destiny(destiny), Entity("Laboratory Door", "Door", EXIT)
	{};
	
	bool open(Entity* playerorigin, ROOMPOSITION playerposition);
	bool close(Entity* playerorigin, ROOMPOSITION playerposition);
	Entity* move(Entity* proom, ROOMPOSITION& position);
	Entity* next(Entity* room, ROOMPOSITION position) const;
};
#endif