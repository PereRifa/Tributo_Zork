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
	DLList<Entity>* list;
	int owntime = 0;

public:
	Entity(){};
	Entity(const char* name, const char* description, ETYPES type) : name(new mString(name)), description(new mString(description)), type(type){};
	virtual ~Entity()
	{
		delete name;
		delete description;
		delete list;
	};
	virtual void Look() const;
	virtual void insert(Entity* other);
	virtual void remove(Entity* other);
	virtual void open(Entity* room, ROOMPOSITION position){};
	virtual void close(){};
	virtual void update(int time){};
};

#endif;
