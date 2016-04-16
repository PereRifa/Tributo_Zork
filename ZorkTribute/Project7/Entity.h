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
	MyEntity entity_type;
	mVector<Entity*> list;

public:
	Entity(){};
	Entity(const char* ed_name, const char* ed_description) : name(new mString(ed_name)), description(new mString(ed_description))
	{
	
		entity_type = ENTITY;

	};
	virtual ~Entity(){};

	virtual void Look()
	{
		printf("\nIt is a %s", name->C_Str());
		printf("\n%s", description->C_Str());
		if (list.empty() == 0){
			printf("\nIt cointains: ");
			for (unsigned int i = 0; i < list.size(); i++)
			{
				printf(" %s,", list[i]->name->C_Str());
			}
		}
	}
	virtual void insert(Entity* other)
	{
		list.pushback(other);
	};
	virtual void remove(Entity* other)
	{
	for (unsigned int i = 0; i< list.size(); i++)
	{
		if (list[i]->name == other->name)
		{
			while (i < list.size() + 1)
			{
				list[i] = list[i + 1];
				i++;
			}
			list.pop_back();
		}
	}
	}
	
};

#endif;
