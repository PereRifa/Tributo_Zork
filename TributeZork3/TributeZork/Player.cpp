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
bool Player::move(ROOMPOSITION roomposition)
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

bool Player::pick( const char* itemname)
{
	if (list.size() < 10)
	{
		for (uint i = 0; i < room->list.size(); i++)
		{
			if (room->list.atnode(i)->data->name->C_Str() == itemname)
			for (uint j = 0; j < world.size(); j++)
			{
				if (room->list.atnode(i)->data == world[j])
				{
					room->list.remove(room->list.atnode(i));
					list.push_back(world[j]);
					world[j]->insert(this);
					printf("\nItem %s picked\n", world[j]->name->C_Str());
					return true;
				}
			}
		}
	}
	return false;
};
bool Player::drop(const char* itemname)
{	
	if (list.size() > 0)
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
	else if (equiped.empty() == false)
	{
		if (equiped.atnode(0)->data->name->C_Str() == itemname)
		{
			printf("\nItem droped\n");
			room->list.push_back(equiped.atnode(0)->data);
			equiped.atnode(0)->data->insert(room);
			equiped.remove(equiped.atnode(0));
			return true;
		}
		else if (equiped.size() == 2)
			if (equiped.atnode(1)->data->name->C_Str() == itemname)
			{
				printf("\nItem droped\n");
				room->list.push_back(equiped.atnode(1)->data);
				equiped.atnode(1)->data->insert(room);
				equiped.remove(equiped.atnode(1));
				return true;
			}
	}
	return false;
};

bool Player::equip( const char* itemname)
{
	for (uint i = 0; i < list.size(); i++)
		{
			if (list.atnode(i)->data->name->C_Str() == itemname)
			{
				printf("\nTaking item from inventory:");
				if (equiped.size() == 2)
				{
					list.push_back(equiped.atnode(1)->data);
					equiped.push_back(list.atnode(i)->data);
					list.remove(list.atnode(i));
					printf("  %s equiped\n", list.atnode(i)->data->name->C_Str());
					return true;
				}
				else
				{
					equiped.push_back(list.atnode(i)->data);
					printf("  %s equiped\n", list.atnode(i)->data->name->C_Str());
					list.remove(list.atnode(i));
					return true;
				}
			}
		}
	return false; 
};

bool Player::unequip( const char* itemname)
{
	if (list.size() < 10)
	{
		for (uint i = 0; i < equiped.size(); i++)
			if (equiped.atnode(i)->data->name->C_Str() == itemname)
			{
				list.push_back(equiped.atnode(i)->data);
				printf("\nItem %s unequiped\n", equiped.atnode(i)->data->name->C_Str());
				equiped.remove(equiped.atnode(i));
				return true;
			}
	}
	else printf("\nUnable to unequip item\n");
	return false; 
};