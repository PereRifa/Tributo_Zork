#ifndef _CREATURE
#define _CREATURE

#include "Entity.h"

enum CREATURETYPE
{
	PLAYER,
	MONKEY,
	CHIMPANZE,
	GORILLA
};

enum STATE
{
	ATTACK,
	MOVE,
	DEAD,
	NONE
};

class Creature : public Entity
{
public:

	STATE creaturestate = NONE;
	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	DLList<Entity*> equiped;
	mVector<Entity*>& world;
	CREATURETYPE subtype;
	int hp;
	int lasthp;
	int attdmg;


public:
	Creature(const char* name, const char* description, Entity* room, CREATURETYPE subtype, mVector<Entity*>& world) : subtype(subtype), room(room), world(world), Entity(name, description, CREATURE){};
	~Creature(){};
	virtual void Look();
	virtual	bool move(ROOMPOSITION posroom);
	virtual bool pick(const char* itemname){ return false; };
	virtual bool drop( const char* itemname){ return false; };
	virtual bool equip( const char* itemname){ return false; };
	virtual bool unequip( const char* itemname){ return false; };
	virtual int update(int timer);

};

#endif