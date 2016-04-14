#include<string.h>
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