#ifndef _ENTITY_
#define _ENTITY_

#include "mString.h"
#include "mVector.h"


class Entity
{
public:
	mString* name;
	mString* description;
	mVector<Entity*> list;

public:
	Entity(){};
	Entity(const char* ed_name, const char* ed_description);
	virtual ~Entity(){};
	virtual void Look() const;
	virtual void insert(Entity* other);
	virtual void remove(Entity* other);
	
};

#endif;
