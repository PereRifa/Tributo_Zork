#include<string.h>
#include<iostream>
#include"Room.h"
#include"World.h"
#include"MemLeaks.h"


int main()
{
	ReportMemoryLeaks();
	{


		World* NewWorld = new World;

		NewWorld->Game();
		
		delete NewWorld;

		getchar();
	}
}