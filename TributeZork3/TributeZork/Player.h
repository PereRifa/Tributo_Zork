#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	Entity* equiped = nullptr;
	


public:
	Player(const char* name, const char* description, Entity* room) : room(room), Entity(name, description, CREATURE){};
	
	void Look();
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	bool pick(mVector<Entity*>& entities, const char* itemname);
	bool drop(mVector<Entity*>& entities, const char* itemname);
	bool equip(mVector<Entity*>& entities, const char* itemname);
	bool unequip(mVector<Entity*>& entities, const char* itemname);
	void update(int timer);

};

#endif