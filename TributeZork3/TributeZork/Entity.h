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
	PLAYER,
	ENEMY,
};

class Entity
{
public:
	mString* name;
	mString* description;
	ETYPES type;
	DLList<Entity>* list;

public:
	Entity(){};
	Entity(const char* name, const char* description, ETYPES type) : name(new mString(name)), description(new mString(description)), type(type){};
	virtual ~Entity()
	{
		list->~DLList();
	};
	virtual void Look() const;
	virtual void insert(Entity* other);
	virtual void remove(Entity* other);

};

#endif;
