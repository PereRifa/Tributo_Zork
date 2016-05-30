#ifndef _ITEM
#define _ITEM

#include "Entity.h"

class Item : public Entity
{
public:
	Entity* room;

public:
	Item(const char* name, const char* description, Entity* room) : Entity(name, description, ITEM), room(room){};
	void insert(Entity* other);
};

#endif;