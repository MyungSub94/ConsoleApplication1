#include "stdafx.h"
#include "weapon.h"


Weapon::Weapon()
{
	attack = 1;
	modifier = 1;
}

//Creates weapon which takes the attack stat, any modifiers, and the weapon's id
Weapon::Weapon(std::string item_name, std::string item_description, int attack_stat, int mod, int item_id)
{
	name = item_name;
	description = item_description;
	attack = attack_stat;
	modifier = mod;
	id = item_id;
	type = WEAPON;
}

Weapon::~Weapon()
{

}
