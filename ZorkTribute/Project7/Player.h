#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	mString* roomposition;
	int room;
	bool objectpicked = false;
	bool equiped = false;
	
	
public:
	Player(const char* p_name, const char* p_description);
	~Player();
	void Look() const;
};

#endif