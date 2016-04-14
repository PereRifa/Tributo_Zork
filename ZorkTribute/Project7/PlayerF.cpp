#include"Player.h"



Player::Player()
{
	name = new mString("Dean Pinchester");
	roomposition = new mString("west");
	room = 0;
	
}

Player::~Player()
{
	delete name;
	delete roomposition;
}