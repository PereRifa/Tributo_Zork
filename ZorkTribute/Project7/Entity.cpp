#include "Entity.h"


Entity::Entity(const char* ed_name, const char* ed_description) : name(new mString(ed_name)), description(new mString(ed_description))
{

	entity_type = ENTITY;

};

void Entity::insert(Entity* other)
{
	list.pushback(other);
};
void Entity::remove(Entity* other)
{
	for (unsigned int i = 0; i < list.size(); i++)
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

void Entity::Look()	{
	printf("\nIt is a %s", name->C_Str());
	printf("\n%s", description->C_Str());
	if (list.empty() == 1){
		printf("\nIt cointains: ");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf(" %s,", list[i]->name->C_Str());
		}
	}
}