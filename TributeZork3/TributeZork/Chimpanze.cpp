#include "Chimpanze.h"

void Chimpanze::Look()
{
	printf("\nChimpanze Store:\n");
	if (list.empty() == false)
	{
		printf("\tIt cointains: \n");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf("\n	%s", list.atnode(i)->data->name->C_Str());
			for (uint j = 0; j < world.size(); j++)
			{
				if (world[j]->name == list.atnode(i)->data->name)
				{
					if (world[j]->name == world[62]->name)
						printf(" (10 coins)\n");
					else if (world[j]->name == world[63]->name)
						printf(" (15 coins)\n");
					else if (world[j]->name==world[28]->name)
						printf(" (12 coins)\n");
					else printf(" (8 coins)\n");
					continue;
				}
			}
		}
	}
	else printf("\nThe chimpanze store is empty\n\n");
}