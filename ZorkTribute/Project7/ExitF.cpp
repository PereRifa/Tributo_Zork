#include <string.h>
#include <iostream>
#include "Exit.h"
#include "mString.h"

Doors::Doors(const char* roompos, const int from, const int to) : doorstate(false), doorroomposition(new mString(roompos)), origin(from), destiny(to)
{
	/*doorstate = false;
	doorroomposition = new mString(roompos);
	origin = from;
	destiny = to;*/
};

Doors::~Doors()
{
}