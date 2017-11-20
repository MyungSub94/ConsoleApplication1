#pragma once
#include "item.h"
#include "Actor.h"
#include <string>

enum res_type: int {HEALTH, MANA};
typedef enum res_type RESOURCE_TYPE;

class RecoveryItem : public item
{
public:
	RecoveryItem();

	int recover_amount;
	RESOURCE_TYPE recover_type;

	RecoveryItem(std::string name, std::string descr, int item_type, int amount,
				 RESOURCE_TYPE resource_type, int item_count, int item_id);
	int useRecoveryItem();				//Returns the amount healed


	~RecoveryItem();
};

