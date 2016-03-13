#include <string>
#include <iostream>
#include "Exit.h"

using namespace std;

Doors::Doors()
{
	doorstate = "open";
	doorroomposition = "none";
	room1 = 0;
	room2 = 0;
}
Doors::~Doors()
{
}