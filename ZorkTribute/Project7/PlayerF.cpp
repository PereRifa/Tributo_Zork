#include<string.h>
#include<iostream>
#include"Player.h"



Player::Player()
{
	name = new mString("Dean Pinchester");
	roomposition = new mString("unknown");
	room = 0;
	
}

Player::~Player()
{
	delete name;
	delete roomposition;
}