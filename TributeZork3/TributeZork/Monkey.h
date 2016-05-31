#ifndef _MONKEY
#define _MONKEY


#include "Creature.h"
#include "Entity.h"
#include "Player.h"

class Monkey : public Creature
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	Player* player = nullptr;
	CREATURETYPE subtype;
	int hp = 50;
	int attdmg = 5;


public:
	Monkey(const char* name, const char* description, Entity* room, CREATURETYPE subtype, mVector<Entity*> world, Player* player) : player(player), Creature("Monkey", "Little monkey", room, subtype, world){}
	void Look();
	bool move(ROOMPOSITION posroom);
	int update(int timer);

};

#endif};