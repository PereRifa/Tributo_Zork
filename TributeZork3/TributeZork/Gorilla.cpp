#include "Gorilla.h"

void Gorilla::update(int timer)
{
	if (timer >= owntime + 6000)
	{
		printf("\nI'm a Gorilla and i move\n");
		owntime = timer;
	}
}

bool Gorilla::move(ROOMPOSITION roomposition)
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