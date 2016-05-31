#ifndef _GORILLA
#define _GORILLA

#include "Creature.h"
#include "Entity.h"

class Gorilla: public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	CREATURETYPE subtype;
	int hp = 100;
	int attdmg = 10;


public:
	Gorilla(Entity* room, CREATURETYPE subtype) : Creature("Gorilla", "Big and strong Gorilla", room, subtype){}
	void Look(){};
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	void update(int timer);

};

#endif};