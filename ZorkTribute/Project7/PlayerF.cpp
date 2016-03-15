#include<string>
#include<iostream>
#include"Player.h"



Player::Player()
{
	strcpy_s(name, "Dean Winchester");
	room = 0;
	*roomposition = NULL;

}

Player::~Player()
{

}