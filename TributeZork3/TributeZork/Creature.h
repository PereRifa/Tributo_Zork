#ifndef _CREATURE
#define _CREATURE

#include "Entity.h"

enum CREATURETYPE
{
	PLAYER,
	MONKEY,
	GORILLA
};

class Creature : public Entity
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	DLList<Entity*> equiped;
	mVector<Entity*>& world;
	CREATURETYPE subtype;
	int hp;
	int attdmg;


public:
	Creature(const char* name, const char* description, Entity* room, CREATURETYPE subtype, mVector<Entity*>& world) : subtype(subtype), room(room), world(world), Entity(name, description, CREATURE){};
	virtual void Look();
	virtual	bool move(ROOMPOSITION posroom);
	virtual bool pick(const char* itemname){ return false; };
	virtual bool drop( const char* itemname){ return false; };
	virtual bool equip( const char* itemname){ return false; };
	virtual bool unequip( const char* itemname){ return false; };
	virtual void update(int timer);

};

#endif