#include <string>
#include <stdio.h>

using namespace std;

#ifndef PLAYER
#define PLAYER

class Player
{
public:
	string name;
	int x, y;
	string roomposition;
	int acutualroom;

	Player();
	~Player();

};

#endif