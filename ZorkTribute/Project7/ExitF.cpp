#include "Exit.h"


Doors::Doors(const char* roompos, const int from, const int to) : doorstate(false), doorroomposition(new mString(roompos)), origin(from), destiny(to)
{
	name = new mString("Laboratory Door");
	description = new mString("A special door for keeping labaratories safe");
	entity_type = EXIT;

};

Doors::~Doors()
{
}