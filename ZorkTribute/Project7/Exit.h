#include<string.h>
#include<iostream>


#ifndef DOORS
#define DOORS

class Doors
{
public:
	char doorstate[10];
	char doorroomposition[10];
	int origin;
	int destiny;

	Doors();
	~Doors();

};
#endif