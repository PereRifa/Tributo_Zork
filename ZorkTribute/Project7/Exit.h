#include <string.h>
#include <iostream>
#include "mString.h"

#ifndef DOORS
#define DOORS

class Doors
{
public:
	mString* doorstate;
	mString* doorroomposition;
	//char doorstate[50];
	//char doorroomposition[10];
	int origin;
	int destiny;

public:
	Doors();
	
	~Doors();

};
#endif