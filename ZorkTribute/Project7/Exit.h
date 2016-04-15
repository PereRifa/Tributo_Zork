#ifndef DOORS
#define DOORS

#include <string.h>
#include "mString.h"
#include "Entity.h"

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