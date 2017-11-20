#pragma once
#include <string>
#include "item.h"

class Weapon: public item
{
public:
	Weapon();
	Weapon::Weapon(std::string item_name, std::string item_description, int attack_stat, int mod, int item_id);
	~Weapon();

	int attack;			//The stat that gets to added to damage against monsters
	int modifier;		//Modifier value. Could be a crit multiplier or be put on to a list of modifiers for affinities/effects
	int id;				//ID of the item. Index value of inside the array of all the items in the
};

