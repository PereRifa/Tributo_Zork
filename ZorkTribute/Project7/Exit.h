#include <string.h>
#include <iostream>
#include "mString.h"

#ifndef DOORS
#define DOORS

class Doors
{
public:
	bool doorstate;
	mString* doorroomposition;
	int origin;
	int destiny;

public:
	Doors(const char* roompos, const int from, const int to);
	
	~Doors();

};
#endif