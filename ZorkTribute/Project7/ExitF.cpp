#include <string>
#include <iostream>
#include "Exit.h"

using namespace std;

Doors::Doors()
{
	*doorstate = NULL;
	*doorroomposition = NULL;
	origin = NULL;
	destiny = NULL;
}
Doors::~Doors()
{
}