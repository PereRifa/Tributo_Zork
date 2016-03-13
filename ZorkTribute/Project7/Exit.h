#include<string>
#include<iostream>

using namespace std;

#ifndef DOORS
#define DOORS

class Doors
{
public:
	string doorstate;
	string doorroomposition;
	int room1;
	int room2;

	Doors();
	~Doors();

};
#endif