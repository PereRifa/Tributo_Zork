#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity
{
public:

	ROOMPOSITION proompos = EAST;
	Entity* room = nullptr;
	


public:
	Player(const char* name, const char* description, Entity* room) : room(room), Entity(name, description, CREATURE){};
	
	void Look() const;
	bool move(mVector<Entity*>& entities, ROOMPOSITION posroom);
	void update(int timer);
};

#endif