#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>


#include "memleaks.h"
#include "World.h"

#define DELAY 1000
#define COMMANDBUFFER 50

int main()
{
	ReportMemoryLeaks();
	{

		World* NewWorld = new World();

		NewWorld->Game();

		delete NewWorld;
		/*
		char command[COMMANDBUFFER];
		bool firsttimeinloop = true;
		unsigned int currenttime = 0;
		unsigned int initialtime = 0;
		unsigned int charcommandnum = 0;
		//timeGetTime()
		initialtime = GetTickCount();

		while (command[0] != 'e'){
			//Executa el codi cada x milisegons (DELAY)
			currenttime = GetTickCount();
			if (currenttime >= (initialtime + DELAY)){
				printf("Hy.\n");
				initialtime = currenttime;
			}

			//kbhit test
			if (_kbhit())
			{
				if (charcommandnum < (COMMANDBUFFER - 2)){
					command[charcommandnum] = _getch();
					command[charcommandnum + 1] = '\0';
					printf("String: %s\n", command);//va imprimint l'estat de command
					charcommandnum++;
					if (command[charcommandnum - 1] == '\r'){//quant apretes enter, imprimeix el command i l'esborra
						printf("Your command is: %s\n", command);
						command[charcommandnum] = '\0';
						charcommandnum = 0;
					}
				}
				else{
					command[COMMANDBUFFER - 1] = '\0';
				}
			}
	}*/
	}
	return 0;
}