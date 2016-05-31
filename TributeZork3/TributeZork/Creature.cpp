#include "Creature.h"

#include "World.h"

void Creature::Look()
{
	if (list.empty() == false)
	{
		printf("\nInventory\n\tIt cointains: \n");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf(" %s\n", list.atnode(i)->data->name->C_Str());
		}
	}
	else printf("\nYour inventory is empty\n\n");
}

void Creature::update(int timer)
{
	if (timer >= owntime + 3000)
	{
		//	printf("\nit s my time and it s now or never\n");
		owntime = timer;
	}
}
bool Creature::move(ROOMPOSITION roomposition)
{
	bool ret = false;
	proompos = roomposition;
	Entity* temp = nullptr;
	uint i = 0;
	for (i = 0; i < world.size(); i++)
	{
		temp = world[i]->move(room, proompos);
		if (temp != nullptr)
		{
			room = temp;
			printf("\nChanged of Room: now at %s\n", room->name->C_Str());
			return true;
			continue;
		}
	}
	printf("\n%s\n", room->name->C_Str());

	return ret;
}
