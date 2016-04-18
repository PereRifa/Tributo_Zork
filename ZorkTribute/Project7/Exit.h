#ifndef _DOORS
#define _DOORS

#include "Entity.h"

class Doors : public Entity
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