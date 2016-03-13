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
	int x;
	int y;

	Doors();
	~Doors();

};
#endif