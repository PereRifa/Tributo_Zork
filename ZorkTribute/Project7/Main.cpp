#include<string.h>
#include<iostream>
#include"Room.h"
#include"World.h"
#include"memleaks.h"


int main()
{
	ReportMemoryLeaks();

	World* NewWorld = new World;

	NewWorld->Game();

	getchar();

	delete NewWorld;
}