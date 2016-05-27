#include "Exit.h"

void Door::open(Room* playerorigin, ROOMPOSITION playerposition)
{
	if ((playerorigin == origin) && (playerposition == doorposition))
	{
		if (doorstate == false){
			for (int j = 0; j < 50; j++){ //change 50 for MaxEntitys

			//	if ((origin == ) && ((Exits[j]->origin) == Exits[i]->destiny))
				{
					doorstate = true;
				//	Exits[j]->doorstate = true;
					printf("\nDoor open\n");
				}
			}

		}
		if (doorstate == true){
			printf("\nThe door is already open");
		}
	}
}

void Door::close(Room* playerorigin, ROOMPOSITION playerposition)
{
	if ((playerorigin == origin) && (playerposition == doorposition))
	{
		if (doorstate == true){
			for (int j = 0; j < 50; j++){ //change 50 for MaxEntitys

				//	if ((origin == ) && ((Exits[j]->origin) == Exits[i]->destiny))
				{
					doorstate = true;
					//	Exits[j]->doorstate = true;
					printf("\nDoor closed\n");
				}
			}

		}
		if (doorstate == false){
			printf("\nThe door is already closed");
		}
	}
}