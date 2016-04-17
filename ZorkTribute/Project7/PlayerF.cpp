#include"Player.h"

Player::Player(const char* p_name, const char* p_description) : Entity(p_name, p_description)
{
	
	entity_type = PLAYER;
	roomposition = new mString("west");
	room = 0;
	
}

void Player::Look(){
	if (list.empty() == false){
		printf("\nInventory\n\tIt cointains: \n");
		for (unsigned int i = 0; i < list.size(); i++)
		{
			printf(" %s\n", list[i]->name->C_Str());
		}
	}
	else printf("\nYour inventory is empty\n\n");
}

Player::~Player()
{
	delete roomposition;
}