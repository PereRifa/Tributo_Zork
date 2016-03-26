#include <string.h>
#include <iostream>
#include "Exit.h"


Doors::Doors()
{
	*doorstate = NULL;
	*doorroomposition = NULL;
	origin;
	destiny;
}
Doors::~Doors()
{
}