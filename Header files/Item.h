#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

class Item {
	string name;
	float price;
	friend std::ostream& operator<<(std::ostream& out, Item& s);
public:
	void operator()();
	Item(string name, float price);
	string outputName();
	float outputPrice();
};