#include "Gorilla.h"

void Gorilla::update(int timer)
{
	
	if (creaturestate != DEAD)
	{
		if (creaturestate != NONE)
		{
			if (creaturestate == MOVE)
				if (timer >= owntime + 6000)
				{
					switch (rand() % 4)
					{
					case 0: proompos = NORTH;
						break;
					case 1: proompos = SOUTH;
						break;
					case 2: proompos = EAST;
						break;
					case 3: proompos = WEST;
					}
					for (uint i = 0; i < world.size(); i++)
					{
						if (world[i]->next(room, proompos) != player->room && world[i]->next(room, proompos) != nullptr)
						{
							world[i]->open(room, proompos);
							move(proompos);
							printf("\nI'm a Gorilla and i move!!\n");
							owntime = timer;
							break;
						}
						else
						{
						}						
					}
				}
		}
		else
		{
			if (timer > owntime + 10000)
			{
				creaturestate = MOVE;
				owntime = timer;
			}
		}
	}
	
}

bool Gorilla::move(ROOMPOSITION roomposition)
{
	bool ret = false;
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
		}
	}
	printf("\n%s\n", room->name->C_Str());

	return ret;
}