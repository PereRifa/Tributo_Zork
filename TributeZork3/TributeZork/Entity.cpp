#include "Entity.h"

void Entity::Look() const
{
	printf("\n%s\n\t%s", name->C_Str(), description->C_Str());
	if (list->empty() == false){
		printf("\n\tIt cointains: \n");
		for (unsigned int i = 0; i < list->size(); i++)
		{
			printf(" %s\n", list->atnode(i)->data.name->C_Str());
		}
	}
}

void Entity::insert(Entity* other)
{

}

void Entity::remove(Entity* other)
{

}

