#ifndef _ITEM
#define _ITEM

#include "Entity.h"

class Item : public Entity
{
public:
	bool equiped = false;
	bool took = false;
public:
	Item(const char* i_name, const char* i_description) : Entity(i_name, i_description)
	{
		entity_type = ITEM;
		
	}
	~Item()
	{
		delete name;
		delete description;
	}
};

#endif;