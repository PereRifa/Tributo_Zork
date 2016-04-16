#include"Player.h"

Player::Player(const char* p_name, const char* p_description) : Entity(p_name, p_description)
{
	
	entity_type = PLAYER;
	roomposition = new mString("west");
	room = 0;
	
}

Player::~Player()
{
	delete roomposition;
}