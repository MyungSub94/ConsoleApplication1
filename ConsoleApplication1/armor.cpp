#include "stdafx.h"
#include "armor.h"


Armor::Armor()
{
}

Armor::Armor(std::string item_name, std::string item_descrpition,
			int armor_value, int magic_value, int armor_modifier, int armor_id)
{ 
	name = item_name;
	description = item_descrpition;
	phys_value = armor_value;
	mag_value = magic_value;
	modifier = armor_modifier;
	id = armor_id;
	type = ARMOR;
}

Armor::~Armor()
{
}
