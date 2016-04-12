#include <string.h>
#include <iostream>
#include "Exit.h"
#include "mString.h"

Doors::Doors()
{
	doorstate = new mString("closed");
	doorroomposition = new mString("unknown");
	origin;
	destiny;
}

Doors::~Doors()
{
}