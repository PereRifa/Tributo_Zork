#include "Exit.h"


bool Door::open(Entity* playerorigin, ROOMPOSITION playerposition)
{
	if (((playerorigin == origin) && (playerposition == doorposition)) || ((playerorigin == destiny) && (playerposition == othersidedoor)))
	{
		if (doorstate == false)
		{
			doorstate = true;
			printf("\nDoor open\n");
			return true;
		}
		else if (doorstate == true){
			printf("\nThe door is already open\n");
			return false;
		}
	}
	return false;
}

bool Door::close(Entity* playerorigin, ROOMPOSITION playerposition)
{
	if (((playerorigin == origin) && (playerposition == doorposition)) || ((playerorigin == destiny) && (playerposition == othersidedoor)))
	{
		if(doorstate == true)
		{
			doorstate = false;
			printf("\nDoor closed\n");
			return true;
		}
		else if(doorstate == false){
			printf("\nThe door is already closed\n");
			return false;
		}
	}
	return false;
}

Entity* Door::move(Entity* room, ROOMPOSITION& position)
{
	if (doorstate == true && position == doorposition && room == origin)
	{
		return destiny;
	}
	else if (doorstate == true && position == othersidedoor && room == destiny)
	{
		return origin;
	}
	else return nullptr;
}