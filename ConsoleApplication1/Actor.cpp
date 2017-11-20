#include "stdafx.h"
#include "Actor.h"
#include <string>


Actor::Actor()
{
	name = "NULL";
	health = 100;
	mana = 100;
}

//Constructs a typical character that would be in a battle sequence
Actor::Actor(std::string act_name, int act_hp, int act_mp, actor_stats act_stats, actor_equipment act_equip)
{
	name = act_name;
	health = act_hp;
	max_health = act_hp;
	mana = act_mp;
	max_mana = act_mp;
	stats = act_stats;
	temp_stats = stats;
	equipment = act_equip;
}

Actor::~Actor()
{
}

int Actor::removeHealth(int damage)			//Sets new health equal the amount as passed parameter
{
	health = health - damage;
	return health;
}

int Actor::recoverHealth(int amount)
{	
	health = health + amount;

	if(health > max_health)
	{
		health = max_health;
	}

	return health;
}

int Actor::removeMana(int cost)
{
	mana = mana - cost;
	return mana;
}

//Function called after a battle ends so that any buffs/debuffs are not accounted for in next batttles
void Actor::resetActorStats()
{
	temp_stats = stats;
}

//Function called during a full heal/restoring
void Actor::setActorResourceMax()
{
	health = max_health;
	mana = max_mana;
}