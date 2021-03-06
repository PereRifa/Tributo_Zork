#ifndef _GORILLA
#define _GORILLA

#include "Creature.h"
#include "Entity.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>

class Gorilla: public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	Player* player = nullptr;
	CREATURETYPE subtype;
	int hp = 100;
	int lasthp = hp;
	int attdmg = 5;


public:
	Gorilla(Entity* room, CREATURETYPE subtype, mVector<Entity*>& world, Player* player) : player(player), Creature("Gorilla", "Big and strong Gorilla", room, subtype, world)
	{
		room->list.push_back(this);
	}
	void Look(){};
	bool move(ROOMPOSITION posroom);
	int update(int timer);

};

#endif};