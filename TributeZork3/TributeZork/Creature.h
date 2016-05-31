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
	CREATURETYPE subtype;
	int hp;
	int attdmg;


public:
	Creature(const char* name, const char* description, Entity* room, CREATURETYPE subtype) : subtype(subtype), room(room), Entity(name, description, CREATURE){};
	virtual void Look();
	virtual	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	virtual bool pick(mVector<Entity*>& entities, const char* itemname){ return false; };
	virtual bool drop(mVector<Entity*>& entities, const char* itemname){ return false; };
	virtual bool equip(mVector<Entity*>& entities, const char* itemname){ return false; };
	virtual bool unequip(mVector<Entity*>& entities, const char* itemname){ return false; };
	virtual void update(int timer);

};

#endif