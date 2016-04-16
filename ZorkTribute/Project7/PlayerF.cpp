#include"Player.h"

Player::Player(const char* p_name, const char* p_description)
{
	name = new mString(p_name);
	description = new mString(p_description);
	entity_type = PLAYER;
	roomposition = new mString("west");
	room = 0;
	
}

Player::~Player()
{
	delete roomposition;
}