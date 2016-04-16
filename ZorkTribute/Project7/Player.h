#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	mString* roomposition;
	int room;
	
	
public:
	Player(const char* p_name, const char* p_description);
	~Player();
};

#endif