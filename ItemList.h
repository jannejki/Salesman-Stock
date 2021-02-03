#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Item.h"

using namespace std;

class ItemList {
protected:
	vector<Item> itemsToSave;
	int forSale = 0;
	unsigned __int64 longestName = 0;
public:
	ItemList();
	void initialize(string fileName);
	virtual bool saveFile(string fileName, vector<Item> item);
	virtual vector<Item> readStock(string text);
	virtual void addItem(string fileName);
	virtual void printVectorInfo(vector<Item> printItems);
	virtual ~ItemList() = default;
};
