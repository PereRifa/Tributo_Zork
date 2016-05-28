#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	ROOMPOSITION proompos;
	Entity* room;



public:
	Player(const char* name, const char* description) : Entity(name, description, CREATURE){};
	
	void Look() const;
	void update(int timer);
};

#endif