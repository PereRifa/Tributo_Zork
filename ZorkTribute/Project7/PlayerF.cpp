#include<string>
#include<iostream>
#include"Player.h"



Player::Player()
{
	strcpy(name, "Dean Winchester");
	room = 0;
	*roomposition = NULL;

}

Player::~Player()
{

}