#pragma once
#ifndef SPELL_H
#define SPELL_H
#include <string>
#include "Actor.h"

//ENUM Type that will determine the way in which the spell will target and do damage
enum s_type : int { PHYSICAL = 0, MAGICAL = 1, HEAL = 2, UTILITY = 3};
typedef enum s_type spell_class;

class Actor;

class Spell
{
public:
	Spell();

	std::string name;
	std::string description;
	double modifier;
	int base_damage;
	int cost;
	spell_class type;

	Spell(std::string spell_name, std::string descr, double mod, int base, int spell_cost, spell_class s_type);
	void castSpell(Actor &caster, Actor &target);

	~Spell();
};

#endif