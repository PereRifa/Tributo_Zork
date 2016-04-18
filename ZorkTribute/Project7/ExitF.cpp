#include "Exit.h"


Doors::Doors(const char* roompos, const int from, const int to) : doorstate(false), doorroomposition(new mString(roompos)), origin(from), destiny(to), Entity("Laboratory Door", "A Special door for Laboratories"){};

Doors::~Doors()
{
	delete name;
	delete description;
	delete doorroomposition;
}