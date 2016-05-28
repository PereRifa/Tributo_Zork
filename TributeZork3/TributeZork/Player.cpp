#include "Player.h"

void Player::Look() const
{}

void Player::update(int timer)
{
	if (timer >= owntime + 3000)
	{
		printf("\nit s my time and it s now or never\n");
		owntime = timer;
	}
}