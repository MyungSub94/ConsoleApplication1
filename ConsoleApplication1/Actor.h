#pragma once
#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include "weapon.h"
#include "armor.h"

const int MAX_SPELL = 5;

struct actor_stats			//Stats of player that will determine combat
{
	int strength;		//Determines phyiscal spells and basic attacks
	int proficiency;	//Determines crit chance, hit rate, and dodge
	int aptitude;		//Determines magic modifiers and spell hit rate. Replaces strength for basic attack if stat is high enough
	int constitution;	//Determines phyiscal defense
	int fortitude;		//Determines magical defense
};

struct actor_equipment		//Equipment of player that determines modifiers from stats
{
	Weapon weapon;			//Bonus to damage. Can have bonus modifiers. One weapon per character
	Armor armor;			//Bonus to damage mitigation. One armor per character

	//TODO. BUILD A REAL INVENTORY SYSTEM
	//Currentls holds the ID of each item
	int inventory[10];		
};

class Spell;				//Forward declaration of Spell class

class Actor
{
public:
	//Constructors/destructors
	Actor();
	Actor(std::string, int, int, actor_stats, actor_equipment);
	virtual ~Actor();

	//Public variables
	std::string name;
	int max_health;				//Holds the max health to prevent overheal/reset hp bar
	int max_mana;				//Holds max mana
	actor_stats stats;			//Holds base stats of the actor
	actor_stats temp_stats;		//Holds stats when receiving a temporary buff
	actor_equipment equipment;		//Struct that holds weapon, armor, and any items of actor
	Spell *spell_book[MAX_SPELL];			//An array of pointers to spells

	//Sets health and mana after damage or casting spell
	int removeHealth(int damage);
	int recoverHealth(int amount);
	int removeMana(int cost);

	void resetActorStats();			//Sets character stats to their neutral state
	void setActorResourceMax();			//Sets character's hp/mp to the max values

	int health;
	int mana;
};

#endif