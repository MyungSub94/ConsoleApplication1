#include "stdafx.h"
#include "RecoveryItem.h"


RecoveryItem::RecoveryItem()
{
}

RecoveryItem::RecoveryItem(std::string item_name, std::string descr, int item_type,
							int amount, RESOURCE_TYPE resource_type, int item_count, int item_id)
{
	name = item_name;
	description = descr;
	type = item_type;
	next_item = NULL;
	recover_amount = amount;
	recover_type = resource_type;
	count = item_count;
	id = item_id;
}

int RecoveryItem::useRecoveryItem()
{
	count--;
	return recover_amount;
}

RecoveryItem::~RecoveryItem()
{
}
