#include "Player.h"
#include "World.h"

void Player::Look()
{
	printf("\nPlayer:\n\tHealth:  %d / 200\n\tCurrent Attack power:  %d\n\n\tInventory:\n", hp, attdmg);
	if (list.empty() == false)
	{
		printf("\tIt cointains: \n");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf(" %s\n", list.atnode(i)->data->name->C_Str());
		}
	}
	else printf("\nYour inventory is empty\n\n");
}

int Player::update(int timer)
{
	attdmg = 5;
	if (equiped.size() != 0)
	{
		if (equiped.atnode(0)->data->name == world[26]->name)
			attdmg += 10;
		if (equiped.atnode(1) != nullptr)
			if (equiped.atnode(1)->data->name == world[26]->name)
				attdmg += 10;
	}

	if (hp < lasthp)
	{
		lasthp = hp;
		printf("\n\tPlayer Health: %d\n", hp);
	}
	if (hp <= 0)
	{
		creaturestate = DEAD;
	}
	switch (creaturestate)
		{
		case ATTACK: 
			if (timer >= owntime + 2000)
			{
				printf("\nDean Winchester attack and deal %d", attdmg);
				owntime = timer;
			}
			break;
		case NONE:
			if (timer >= owntime + 3000)
			{
				owntime = timer;
			}
			break;
		case DEAD:
			printf("\nYou are Dead!! :(\n");
			return 1;
	}
	return 0;
}

bool Player::move(ROOMPOSITION roomposition)
{
	bool ret = false;
	proompos = roomposition;
	Entity* temp = nullptr;
	uint i = 0;
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

	for (i = 0; i < world.size(); i++)
	{
		temp = world[i]->move(room, proompos);
		
		if (temp != nullptr)
		{
			room = temp;
			printf("\nChanged of Room: now at %s\n", room->name->C_Str());
			if (room == world[13]){
				printf("\nYou did it!! Now you can go back home... :D\n");
			}
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
					equiped.remove(equiped.atnode(1));
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

bool Player::attack()
{
	if(creaturestate == ATTACK)
		return true;
	else return false;

}