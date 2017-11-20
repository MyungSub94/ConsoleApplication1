#include "stdafx.h"
#include "Spell.h"
#include <iostream>


Spell::Spell()
{
	name = "NULL";
}

//Spell construction
Spell::Spell(std::string spell_name, std::string descr, double mod,
			int base, int spell_cost, spell_class s_type)
{
	name = spell_name;
	description = descr;
	modifier = mod;
	base_damage = base;
	cost = spell_cost;
	type = s_type;
}

//Cast very basic spells based on type of spell
//TODO create a system in which when a type is read, create unique damage outputs for spells
//Or create a system like Persona/SMT where spells are roughly the same but strength/weakness plays a big role
void Spell::castSpell(Actor &caster, Actor &target)
{
	int damage_dealt = 0,
		net_damage = 0,
		duration = 0;
	double buff_ratio = 0.0;

	switch (type)
	{
	case PHYSICAL:				//Case if the spell type is physical
		damage_dealt = (base_damage + (caster.temp_stats.strength / 2) + (caster.temp_stats.proficiency / 2))
			* modifier;
		net_damage = damage_dealt - (target.temp_stats.constitution + target.equipment.armor.phys_value);
		target.removeHealth(net_damage);			//Set enemy's new health
		caster.removeMana(cost);					//Set mana cost
		std::cout << caster.name << " dealt " << net_damage << " physical damage to " << target.name << "!\n";
		break;
	case MAGICAL:				//Case if the spell type is magical
		damage_dealt = base_damage + caster.temp_stats.aptitude * modifier;
		net_damage = damage_dealt - (target.temp_stats.fortitude + target.equipment.armor.mag_value);
		target.removeHealth(net_damage);
		caster.removeMana(cost);
		std::cout << caster.name << " dealt " << net_damage << " magical damage to " << target.name << "!\n";
		break;
	case HEAL:					//Case if the spell type is a heal. CURRENTLY ONLY HEALS USER
		damage_dealt = base_damage + caster.temp_stats.aptitude * modifier;
		caster.recoverHealth(damage_dealt);
		caster.removeMana(cost);
		std::cout << caster.name << " healed for " << damage_dealt << std::endl;
		break;
	case UTILITY:			//Case if spell type is a utility/buff spell
		buff_ratio = modifier * 1.1;
		caster.temp_stats.strength = caster.temp_stats.strength * buff_ratio;
		caster.temp_stats.aptitude = caster.temp_stats.aptitude * buff_ratio;
		std::cout << caster.name << " raised strength and aptitude!\n";
		break;
	default:
		break;
	}
}

Spell::~Spell()
{
}
