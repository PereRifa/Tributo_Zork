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
			printf("\nChanged of Room: now at %s\n", room->name->C_Str());
			return true;
			continue;
		}
	}
	printf("\n%s\n", room->name->C_Str());
	
	return ret;
}

bool Player::pick(mVector<Entity*>& entities, const char* itemname)
{
	if (list.size() < 10)
	{
		for (uint i = 0; i < room->list.size(); i++)
		{
			if (room->list.atnode(i)->data->name->C_Str() == itemname)
			for (uint j = 0; j < entities.size(); j++)
			{
				if (room->list.atnode(i)->data == entities[j])
				{
					room->list.remove(room->list.atnode(i));
					list.push_back(entities[j]);
					entities[j]->insert(this);
					printf("\nItem %s picked\n", entities[j]->name->C_Str());
					return true;
				}
			}
		}
	}
	return false;
};
bool Player::drop(mVector<Entity*>& entities, const char* itemname)
{
	if (equiped != nullptr)
	{
		if (equiped->name->C_Str() == itemname)
		{
			room->list.push_back(equiped);
			equiped->insert(room);
			equiped = nullptr;
			return true;
		}
	}
	else if (list.size() > 0)
	{
		for (uint i = 0; i < list.size(); i++)
		{
			if (list.atnode(i)->data->name->C_Str() == itemname)
			{
					printf("\nItem %s removed from inventory\n", list.atnode(i)->data->name->C_Str());
					room->list.push_back(list.atnode(i)->data);
					list.atnode(i)->data->insert(room);
					list.remove(list.atnode(i));		
					return true;
			}
		}
	}
	return false;
};

bool Player::equip(mVector<Entity*>& entities, const char* itemname)
{
	for (uint i = 0; i < list.size(); i++)
	{
		printf("\nfinding item\n");
		if (list.atnode(i)->data->name->C_Str() == itemname)
			printf("\nTrying to equip item\n");
			if (equiped != nullptr)
			{
				list.push_back(equiped);
				equiped = list.atnode(i)->data;
				list.remove(list.atnode(i));
				printf("\nItem %s equiped\n", equiped->name->C_Str());
				return true;
			}
			else
			{
				equiped = list.atnode(i)->data;
				list.remove(list.atnode(i));
				printf("\nItem %s equiped\n", equiped->name->C_Str());
				return true;
			}
		
	}
	printf("\nUnable to equip item\n");
	return false; 
};

bool Player::unequip(mVector<Entity*>& entities, const char* itemname)
{
	if (equiped != nullptr)
	{
		if (list.size() < 10)
		{
			if (equiped->name->C_Str()== itemname)
			{
				list.push_back(equiped);
				printf("\nItem %s unequiped\n", equiped->name->C_Str());
				equiped = nullptr;
				return true;
			}
		}
		else printf("\nUnable to unequip item\n");
	}
	else printf("\nYou dont have any item equiped\n");
	return false; 
};