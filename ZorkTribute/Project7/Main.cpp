#include<string>
#include<iostream>
#include"Room.h"
#include"World.h"

using namespace std;

int main()
{

	World* NewWorld = new World;
	cout << "Player name:  " << NewWorld->player1->name << endl;

	delete NewWorld;
	getchar();
	;

}