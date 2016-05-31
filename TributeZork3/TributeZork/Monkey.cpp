#include "Monkey.h"


void Monkey::update(int timer)
{
	if (timer >= owntime + 3000)
	{
		//	printf("\nit s my time and it s now or never\n");
		owntime = timer;
	}
}
bool Monkey::move(mVector<Entity*>& entities, ROOMPOSITION roomposition)
{
	bool ret = false;
	proompos = roomposition;
	Entity* temp = nullptr;
	uint i = 0;
	for (i = 0; i < entities.size(); i++)
	{
		temp = entities[i]->move(room, proompos);
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
