#pragma once
#include <string>

//Type that defines what the type of item. Used to determine if it an equipable or a use item
enum i_type : int { WEAPON, ARMOR, RECOVERY, BATTLE, KEYITEM };
typedef i_type ITEM_TYPE;

class item
{
public:
	item();
	~item();
	int id;
protected:
	std::string name;
	std::string description;
	int type;				//Type: equipable item, key item, or a battle use item
	item *next_item;			//Pointer to build a linked list as the inventory
	int count;			//Number of the item owned
};