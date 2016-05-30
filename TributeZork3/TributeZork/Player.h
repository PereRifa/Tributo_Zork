#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	


public:
	Player(const char* name, const char* description, Entity* room) : room(room), Entity(name, description, CREATURE){};
	
	void Look();
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	bool pick();
	bool drop();
	bool equip();
	bool unequip();
	void update(int timer);

};

#endif