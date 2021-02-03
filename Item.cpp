#include "Item.h"

Item::Item(string name, float price) {
	this->name = name;
	this->price = price;
}

string Item::outputName() {
	return name;
}

float Item::outputPrice() {
	return price;
}

/*overloaded operator for easier writing to file.*/
ostream& operator<<(std::ostream& out, Item& s) {
	out << s.outputName() << ";" << s.outputPrice() << endl;
	return out;
}

