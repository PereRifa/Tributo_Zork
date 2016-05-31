#ifndef _PLAYER
#define _PLAYER

#include "Creature.h"
#include "Entity.h"

class Player : public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	DLList<Entity*> equiped;
	int hp = 200;
	int attdmg = 5;
	


public:
	Player(const char* name, const char* description, Entity* room, CREATURETYPE subtype) : Creature(name, description, room, subtype){};
	void Look();
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	bool pick(mVector<Entity*>& entities, const char* itemname);
	bool drop(mVector<Entity*>& entities, const char* itemname);
	bool equip(mVector<Entity*>& entities, const char* itemname);
	bool unequip(mVector<Entity*>& entities, const char* itemname);
	void update(int timer);

};

#endif