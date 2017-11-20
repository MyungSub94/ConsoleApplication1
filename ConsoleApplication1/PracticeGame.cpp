#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

//Classes for game combat
#include "Actor.h"		//Class for PC, enemies, and NPC (maybe other stuff if I want to spaghetti it in)
#include "weapon.h"		//Class for weapons that players and enemies use
#include "armor.h"		//Class for armor that players and enemies use
#include "Spell.h"		//Creates spells for player

void buildPlayer(Actor &player);
void buildEnemy(Actor &enemy);
void battleFlowSystem(Actor &player, Actor &enemy);		//Controls the flow of battle
void battleSystemGUI(Actor &player, Actor &enemy, bool &end_flag);		//Builds the GUI of the battle sytem
void battleInfoBuilder(Actor player, Actor enemy);		//Displays name, hp, mana
void enemyPhase(Actor &player, Actor &enemy);			//Figures out what enemy will do
void basicAttack(Actor attacker, Actor &defender);			//Called when an actor issues a basic attack
void buildSpellBook(Actor &player);					//Constructs all the spells player will have
void spellPageGUI(Actor &player, Actor &enemy);

int main()
{
	Actor player, enemy;
	buildPlayer(player);
	buildEnemy(enemy);
	battleFlowSystem(player, enemy);

    return 0;
}

void buildPlayer(Actor &player)
{
	actor_stats player_stats = { 10, 10, 10, 10, 10 };
	actor_equipment player_equipment;
	Armor player_armor;
	Weapon player_weapon;

	player_weapon = {"Test Weapon", "This is just a test", 10, 0, 0};
	player_armor = { "Test Armor", "This is just a test", 5, 5, 0, 0};
	player_equipment.weapon = player_weapon;
	player_equipment.armor = player_armor;

	player = Actor("Test1", 100, 100, player_stats, player_equipment);
	buildSpellBook(player);
}

void buildEnemy(Actor & enemy)
{
	actor_stats enemy_stats = { 15, 5, 5, 5, 5 };
	actor_equipment enemy_equipment;
	Armor enemy_armor;
	Weapon enemy_weapon;

	enemy_weapon = { "Enemy Weapon", "Testing this", 11, 0, 0 };
	enemy_armor = { "Enemy Armor", "Testing this", 5, 5, 0, 0 };
	enemy_equipment.weapon = enemy_weapon;
	enemy_equipment.armor = enemy_armor;

	enemy = Actor("Enemy1", 100, 100, enemy_stats, enemy_equipment);
}

//Controls the flow of battle. Calls GUI Builder and the Enemy Phase controller.
//Ends with enemy dies for the sheer sake of testing at the moment
void battleFlowSystem(Actor &player, Actor &enemy)
{
	bool end_flag = true;
	while(end_flag)
	{
		battleSystemGUI(player, enemy, end_flag);
		Sleep(1850);
		system("CLS");
	}
}

//Called to build the GUI of the battle screen. Called at beginning of battle and end of enemy phase
void battleSystemGUI(Actor &player, Actor &enemy, bool &end_flag)
{
	int player_damage = 0,
		enemy_damage = 0,
		player_cost = 0,
		enemy_cost = 0;
	int menu_choice = 9;

	battleInfoBuilder(player, enemy);			//Call the GUI to display stats
	//Shows choices for the primary GUI screen
	std::cout << "| 1. Attack\n| 2. Spells\n| 3. Items\n| 4. Guard\n| 5. Escape\n";
	std::cout << "------------------------------------\n";

	//Switch statement to control the GUI inputs. Conditional to check if input is valid
	do
	{
		std::cin >> menu_choice;		//Stores input into choosing one of the GUI menu options

		switch (menu_choice)
		{
		//Case for basic attack
		case 1: basicAttack(player, enemy);
				break;
		//Case for using a spell
		case 2: spellPageGUI(player, enemy);
				break;
		//Case for escaping/BUG TESTING TO BREAK OUT OF GAME
		case 5: end_flag = false;
				std::cout << "Retreating...\n";
				break;

		default: std::cin.clear();
				 std::cin.ignore(1);
				 break;
		}
	} while (std::cin.fail() || menu_choice > 5 || menu_choice < 0);

	if(end_flag)
	{
		enemyPhase(player, enemy);
	}
}

//Function call that shows the HP/MP and names of those involved in battle
void battleInfoBuilder(Actor player, Actor enemy)
{
	std::cout << "------------------------------------\n";
	std::cout << "| " << player.name << "         |  "
		<< "| " << enemy.name << "        |\n";
	std::cout << "| HP: " << player.health << " / " << player.max_health << " |  "
		<< "| HP: " << enemy.health << " / " << enemy.max_health << " |\n";
	std::cout << "| MP: " << player.mana << " / " << player.max_mana << " |  "
		<< "| MP: " << enemy.mana << " / " << enemy.max_mana << " |\n";
	std::cout << "------------------------------------\n";
}

//Function that is called during enemy phase
//TODO Build a decision tree-esque system to decide smarter AI
void enemyPhase(Actor &player, Actor &enemy)
{
	//TODO SOME SMART WAY TO DECIDE BUT HERES A SWITCH STATEMENT
	int enemy_choice = 1;

	switch (enemy_choice)
	{
	case 1: basicAttack(enemy, player);
		break;
	default: break;
	}
}

//Method that calculates a basic attack done by player.
//Make the calculation more robust/interesting later down the line
void basicAttack(Actor attacker, Actor &defender)
{
	int damage_roll;

	//TODO Add in hit chance, crit rate, and strengths/weaknesses
	damage_roll = (attacker.temp_stats.strength + attacker.equipment.weapon.attack) -
				  (defender.temp_stats.constitution + defender.equipment.armor.phys_value);
	defender.removeHealth(damage_roll);
	std::cout << attacker.name << " dealt " << damage_roll << " damage!\n";
}

//Hard codes spells the player will have to use in combat
//TODO: Build a more robust spell system. Use a database system to call in spell information
void buildSpellBook(Actor &player)
{
	Spell *temp_spell;			//Holds a spell. Call new for every spell hard coded into the game

	temp_spell = new Spell("Magic Attack", "This is a magical attack", 2, 10, 10, MAGICAL);
	player.spell_book[0] = temp_spell;
	temp_spell = new Spell("Physical Attack", "This is a physical attack", 2, 10, 10, PHYSICAL);
	player.spell_book[1] = temp_spell;
	temp_spell = new Spell("Heal", "This is a heal", 1, 10, 10, HEAL);
	player.spell_book[2] = temp_spell;
	temp_spell = new Spell("Power Boost", "This buffs strength and aptitude", 20, 0, 10, UTILITY);
	player.spell_book[3] = temp_spell;
	player.spell_book[4] = NULL;
}

void spellPageGUI(Actor &player, Actor &enemy)
{
	int player_damage = 0, enemy_damage = 0,
		player_cost = 0, enemy_cost = 0,
		spell_choice = 0, index = 0;

	system("CLS");
	battleInfoBuilder(player, enemy);

	//Loops until the spell list hits a "NULL" spell or hits the max spell count
	while (player.spell_book[index] != NULL || index >= MAX_SPELL)
	{
		std::cout << index + 1 << ". " << player.spell_book[index]->name
				  << "  Cost: " << player.spell_book[index]->cost << " MP\n";
		index++;
	}
	std::cout << "------------------------------------\n";

	//TODO: Check for bad inputs later?
	std::cin >> spell_choice;
	spell_choice--;		//Decrements to get index value of spell
	player.spell_book[spell_choice]->castSpell(player, enemy);
}