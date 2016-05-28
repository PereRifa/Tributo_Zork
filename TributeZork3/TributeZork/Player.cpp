#include "Player.h"
#include "World.h"

void Player::Look() const
{}

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

	proompos = roomposition;
	Entity* temp = nullptr;
	uint i = 0;
	for (i = 0; i < entities.size(); i++)
	{
		temp = entities[i]->move(room, proompos);
		if (temp != nullptr)
		{
			room = temp;
			break;
		}
	}
	printf("\n%s\n", room->name->C_Str());
	printf("\n%s\n", room->description->C_Str());
	
	return true;
}