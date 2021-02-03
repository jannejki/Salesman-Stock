#pragma once
#ifndef SoldItems_H
#define SoldItems_H
#endif

#include "ItemList.h"

class SoldItems : public ItemList {
	string fileName = "Solditems.txt";
public: 
	void printReport();
};
