#pragma once
#ifndef ITEMSFORSALE_H
#define ITEMSFORSALE_H
#endif
#include "ItemList.h"
#include "GeneralFunctions.h"
#include "Item.h"
#include "Solditems.h"

class ItemsForSale : public ItemList {
	int itemsForSale;
	string fileName = "Stockfile.txt";
public:
	void sellItem(SoldItems &soldItem);
	void replenish();
	void printReport();
};