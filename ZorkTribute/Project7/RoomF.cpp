#include "Room.h"

Room::Room(unsigned int i)
{
	entity_type = ROOM;
	description = new mString("normal room");

	switch (i){
	case 0: name = new mString("Laboratory I: Rise Project");
			North = new mString(" you can see a table with some documents and research stuff.\n");
			South = new mString("a door that goes to the warehouse and some tables next to it with lots of investigation stuff.\n");
			East = new mString("a door, behind it it's the bestiary\n");
			West = new mString("your own table with the results of the research, you know everything in them ofcourse.\n");
		break;
	case 1: name = new mString("Bestiary\n");
			North = new mString("few jails with animals inside! make sure they are all in their jails.\n");
			South = new mString("a door that goes to the Laboratory II: Planet project. \n");
			East = new mString("jails in this side, some of them are broken and there are no animals left.\n");
			West = new mString("a door that goes to your Laboratory I, where you work in the Rise project\n");
		break;
	case 2: name = new mString("Warehouse\n");
			North = new mString("a door that goes to your Laboratory I, where you work in the Rise project\n");
			South = new mString("a huge shelving filled with chemical products\n");
			East = new mString("a door that goes to the Laboratory II.\n");
			West = new mString("multiple freezers with speciments and drugs inside.\n");
		break;
	case 3: name = new mString("Laboratory II: Planet Project\n");
			North = new mString("there's a door, behind it, it's the bestiary, it seems that some of them has disapeared\n");
			South = new mString("a door that goes to the laboratory III: Ape Project\n");
			East = new mString("Coffe machine\n");
			West = new mString("the warehouse door and a corridor further south\n");
		break;
	case 4: name = new mString("Laboratory II: Planet Project\n");
			North = new mString("some tables\n");
			South = new mString("a door that goes to the dinning room\n");
			East = new mString("there's te rest of Laboratory II, look there's a coffe machine, some working places...\n");
			West = new mString("A picture of a monkey in the wall, looks like an artwork\n");
		break;
	case 5: name = new mString("Laboratory II: Planet Project\n");
			North = new mString("there's a door, behind it it's the bestiary\n");
			South = new mString("a door, goes to the Laboratory III: Apes Project\n");
			East = new mString("Coffe machine\n");
			West = new mString("the rest of the office and a gate at the end of it\n");
		break;
	case 6: name = new mString("Bar\n");
			North = new mString("the Laboratory II door\n");
			South = new mString("the Dinning room for taking a break\n");
			East = new mString("some table where you can have lunch, but now it's not that time\n");
			West = new mString("the bar, and behind it the kitchen with its warehouse\n");
		break;
	case 7: name = new mString("Dinning Room\n");
			North = new mString("In the north side of this room you can see a table with some documents and research stuff.\n");
			South = new mString("more investigation stuff and a get");
			East = new mString("there's a door, behind it it's the bestiary");
			West = new mString("your oun table with the results of the research, maybe you should read them.");
		break;
	case 8: name = new mString("Laboratory III: of the Apes");
			North = new mString("In the north side of this Lab there's a door to the other lab, some screams can be heard.\n");
			South = new mString("more investigation stuff and a get\n");
			East = new mString("there's a door, behind it it's the Dressing room\n");
			West = new mString("A wall\n");
		break;
	case 9: name = new mString("Dressing Room");
			North = new mString("In the north side of this room you can monkeys dancing.. an amazing artwork\n");
			South = new mString("a larg Vestuary womens at the west side and mans at the east\n");
			East = new mString("Womens vestuary ^.^... but it is empty :/\n");
			West = new mString("A Wall\n");
		break;
	case 10:name = new mString("Dressing Room\n");
			North = new mString("at the end of the room you can see monkeys dancing... an amazing artwork\n");
			South = new mString("the end of the vestuary\n");
			East = new mString("Womens vestuary ^.^... but it is empty :/\n");
			West = new mString("a door to the office\n");
		break;
	case 11:name = new mString("Office\n");
			North = new mString("The reception of the laboratory, there is a picture of a monkey with a dress... i should leave this place -.-\n");
			South = new mString("the end of the vestuary\n");
			East = new mString("Dressing room you should change your dress before going to the laboratory\n");
			West = new mString("a door that goes to the dinning room\n");
		break;
	case 12:name = new mString("Hall\n");
			North = new mString("a door that goes to the office room\n");
			South = new mString("a wall\n");
			East = new mString("a wall\n");
			West = new mString("the exit\n");
		break;
	}
}

Room::~Room()
{
}
