#ifndef _ENTITY_
#define _ENTITY_

#include "mString.h"
#include "mVector.h"
enum MyEntity
{
	ENTITY,
	ROOM,
	EXIT,
	PLAYER,
	ITEM
};
class Entity
{
public:
	mString* name;
	mString* description;

public:
	Entity(){};
	virtual ~Entity(){};
};

#endif;
