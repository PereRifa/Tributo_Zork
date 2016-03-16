
#include<iostream>


#ifndef ROOM
#define ROOM

class Room
{
public:
	char name[40];
	char North[250];
	char South[250];
	char East[250];
	char West[250];

public:
	Room();
	~Room();
};
#endif