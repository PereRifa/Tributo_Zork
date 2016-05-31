#ifndef _CHIMPANZE
#define _CHIMPANZE

#include "Creature.h"
#include "Entity.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>

class Chimpanze : public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	Player* player = nullptr;
	CREATURETYPE subtype;
	int hp = 150;
	

public:
	Chimpanze(Entity* room, CREATURETYPE subtype, mVector<Entity*>& world, Player* player) : player(player), Creature("chimpanze", "Old and wize chimpanze", room, subtype, world)
	{
		room->list.push_back(this);
	}
	void Look();
	int update(int timer){ return 0; };

};

#endif};