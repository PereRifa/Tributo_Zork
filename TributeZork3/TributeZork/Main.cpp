#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>


#include "memleaks.h"
#include "World.h"



int main()
{
	ReportMemoryLeaks();
	{

		World* NewWorld = new World();

		NewWorld->Game();

		delete NewWorld;

	}
	return 0;
}