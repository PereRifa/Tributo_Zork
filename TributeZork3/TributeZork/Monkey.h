#ifndef _MONKEY
#define _MONKEY


#include "Creature.h"
#include "Entity.h"

class Monkey : public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	CREATURETYPE subtype;
	int hp = 50;
	int attdmg = 5;


public:
	Monkey(const char* name, const char* description, Entity* room, CREATURETYPE subtype) : Creature("Monkey", "Little monkey", room, subtype){}
	void Look();
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	void update(int timer);

};

#endif};