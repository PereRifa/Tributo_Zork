#include "Player.h"
#include "World.h"

void Player::Look()
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

void Player::update(int timer)
{
	if (timer >= owntime + 3000)
	{
	//	printf("\nit s my time and it s now or never\n");
		owntime = timer;
	}
}
bool Player::move(mVector<Entity*>& entities, ROOMPOSITION roomposition)
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
			ret = true;
			continue;
		}
	}
	printf("\nRoom position: %d", roomposition);
	printf("\n%s", room->name->C_Str());
	printf("\n%s\n", room->description->C_Str());
	
	return ret;
}

bool Player::pick(){};
bool Player::drop(){};
bool Player::equip(){};
bool Player::unequip(){};