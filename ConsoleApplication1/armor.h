#pragma once
#include <string.h>
#include "item.h"

class Armor:public item
{
public:
	Armor();
	Armor(std::string item_name, std::string item_descrpition,
		int armor_value, int magic_value, int armor_modifier, int armor_id);
	virtual ~Armor();

	int phys_value;			//Value added to subtract incoming physical damage
	int mag_value;
	int modifier;		//Modifier value. Use for attribute damage or special things like crit reduction. Index value on an array
	int id;				//ID of the item. Index value of a list of armor items in the game
};

