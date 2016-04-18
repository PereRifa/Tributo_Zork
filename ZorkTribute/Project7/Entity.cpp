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
	int count = list.size();
	int  i = 0;
	while (i<count)
	{
		if (list[list.size()-1]->name != other->name)
		{
				list.pushfront(list[list.size()-1]);
				list.pop_back();
		}
		i++;
	}
	list.pop_back();

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