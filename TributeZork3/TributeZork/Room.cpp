#include "Room.h"

void Room::Look()
{
	printf("\n%s:\n\n\t- %s", name->C_Str(), description->C_Str());
	if (list.empty() == false){
		printf("\n\n\tIt cointains: \n");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf(" %s\n", list.atnode(i)->data->name->C_Str());
		}
	}
	else printf("\nThe Room is empty\n\n");
}
