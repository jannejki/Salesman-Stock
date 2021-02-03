#include "SoldItems.h"

/*Prints list of sold items and calculates the revenue.*/
void SoldItems::printReport() {
	cout << "sold items: " << endl;
	string name, price;
	float revenue = 0;
	ifstream readFile("Soldfile.txt");
	if (readFile.is_open()) {
		if (!(readFile.peek() == ifstream::traits_type::eof())) {
			printVectorInfo(readStock("Soldfile.txt"));
			while (getline(readFile, name, ';')) {
				getline(readFile, price);
				revenue += stof(price);
			}
		}
		else
			cout << "no items sold!" << endl;
	}
	else 
		cout << "ERROR! Unable to open file" << endl;
	
	readFile.close();
	cout << "Total money earned: " << revenue << endl << endl;
}
