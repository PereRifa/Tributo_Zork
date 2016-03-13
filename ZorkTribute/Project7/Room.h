#include<string>
#include<iostream>

using namespace std;

#ifndef ROOM
#define ROOM

class Room
{
public:
	string name;
	string North;
	string South;
	string East;
	string West;

public:
	Room();
	~Room();
		
};

#endif