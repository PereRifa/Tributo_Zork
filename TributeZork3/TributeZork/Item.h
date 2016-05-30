#ifndef _ITEM
#define _ITEM

#include "Entity.h"

class Item : public Entity
{
public:
	bool equiped = false;
	bool took = false;
	Entity* room;

public:
	Item(const char* name, const char* description, Entity* room) : Entity(name, description, ITEM), room(room){};
};

#endif;