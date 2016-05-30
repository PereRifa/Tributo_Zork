#ifndef _ENTITY_
#define _ENTITY_

#include "mString.h"
#include "mVector.h"
#include "DLinkedList.h"


enum ETYPES
{
	ROOM,
	EXIT,
	ITEM,
	CREATURE
};

enum ROOMPOSITION
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Entity
{
public:
	mString* name;
	mString* description;
	ETYPES type;
	DLList<Entity*> list;
	int owntime = 0;

public:
	Entity(){};
	Entity(const char* name, const char* description, ETYPES type) : name(new mString(name)), description(new mString(description)), type(type){};
	virtual ~Entity()
	{
		delete name;
		delete description;
	};
	virtual void Look();
	virtual void insert(Entity* other);
	virtual bool open(Entity* room, ROOMPOSITION position){ return false; };
	virtual bool close(Entity* room, ROOMPOSITION position){ return false; };
	virtual void update(int time){};
	virtual Entity* move(Entity* room, ROOMPOSITION& position){ return nullptr; };
};

#endif;
