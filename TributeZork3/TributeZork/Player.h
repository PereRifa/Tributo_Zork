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
	int lasthp = hp;
	int attdmg = 10;
	int owntime = 1000;
	int coins = 25;


public:
	Player(const char* name, const char* description, Entity* room, CREATURETYPE subtype, mVector<Entity*>& world) : Creature(name, description, room, subtype, world){};
	void Look();
	bool move(ROOMPOSITION posroom);
	bool pick( const char* itemname);
	bool drop( const char* itemname);
	bool equip( const char* itemname);
	bool unequip( const char* itemname);
	bool attack();
	void buy(const char* item);
	int update(int timer);

};

#endif