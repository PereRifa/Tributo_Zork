#include <string>
#include <iostream>
#include "Exit.h"

using namespace std;

Doors::Doors()
{
	doorstate = "open";
	doorroomposition = "none";
	x = 0;
	y = 0;
}
Doors::~Doors()
{
}