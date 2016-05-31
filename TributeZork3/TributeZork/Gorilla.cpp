#include "Gorilla.h"

int Gorilla::update(int timer)
{
	
	if (creaturestate != DEAD)
	{
		switch (creaturestate)
		{
		case ATTACK: 
			if (timer >= owntime + 2000)
			{
				if (player->creaturestate == ATTACK && player->room == room)
				{
					player->owntime = timer;
					hp -= player->attdmg;
				}
				if (hp <= 0)
				{
					creaturestate = DEAD;
					printf("\nGorilla: *puff* dead x_x\n");
					player->creaturestate = NONE;
				}
				else{
					printf("\nGorilla attack and deal %d \n\tGorilla Health: %d", attdmg, hp);
					player->hp -= attdmg;
				}
				
				owntime = timer;
			}
			if (player->room != room)
			{
				creaturestate = MOVE;
				player->creaturestate = NONE;
				owntime = timer;
			}
			break;
		case MOVE: 
			if (timer >= owntime + 10000)
			{
				//random move
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
				//room exceptions;
				if ((room == world[10]) && (proompos == NORTH)){
					room = world[9];
				}
				if ((room == world[5]) && (proompos == NORTH)){
					room = world[3];
				}
				if ((room == world[9]) && (proompos == SOUTH)){
					room = world[10];
				}
				if ((room == world[3]) && (proompos == SOUTH)){
					room = world[5];
				}
				if ((room == world[5]) && (proompos == WEST)){
					room = world[4];
				}
				if ((room == world[4]) && (proompos == EAST)){
					room = world[5];
				}
				if (room == player->room)
				{
					creaturestate = ATTACK;
					return 0;
					break;
				}
				for (uint i = 0; i < world.size(); i++)
				{
					if (world[i]->next(room, proompos) == player->room && world[i]->next(room, proompos) != nullptr && timer < 20000)
					{
						world[i]->open(room, proompos);
						move(proompos);
						//	printf("\nI'm a Gorilla and i move!!\n");
						creaturestate = ATTACK;
						owntime = timer;
						return 0;
						break;
					}
					else if (world[i]->next(room, proompos) != player->room)
					{
						world[i]->open(room, proompos);
						move(proompos);
						owntime = timer;
						return 0;
						break;
					}
				}
			}
			break;
		case DEAD:	break;
		case NONE:
			if (timer > owntime + 10000)
			{
				creaturestate = MOVE;
				owntime = timer;
				return 0;
			}
			break;
		}
		
	}
	return 0;
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
//	printf("\n%s\n", room->name->C_Str());

	return ret;
}