#ifndef _ITEM
#define _ITEM

#include "Entity.h"

class Item : public Entity
{
public:
	bool equiped = false;
	bool took = false;
	int room;

public:
	Item(const char* i_name, const char* i_description, int roompos) : Entity(i_name, i_description), room(roompos){};
	~Item()
	{
		delete name;
		delete description;
	}
};

#endif;