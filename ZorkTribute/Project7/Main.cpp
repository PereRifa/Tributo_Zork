#include<string>
#include<iostream>
#include"Room.h"
#include"World.h"
#include"memleaks.h"
using namespace std;

int main()
{
	ReportMemoryLeaks();
	World* NewWorld = new World;


	delete NewWorld;
	getchar();
	;

}