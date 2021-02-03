#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "generalFunctions.h"

/*This .cpp file is for functions that can be used everywhere in code*/

using namespace std;

/*asks a question from user that can only be answered
with 'y' for YES or 'n' for NO. returns true if 'y' and false if 'n'.*/
bool yesOrNo(string question) {
	string userInput;
	while (1) {
		cout << question << " (y/n): ";
		cin >> userInput;
		if (userInput == "y") {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return true;
		}
		else if (userInput == "n") {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}
		else {
			cout << "You must enter 'y' for YES or 'n' for NO!" << endl;
		}
	}
}

/*asks a multiple choise question from user that can be answered with a number between min and max.
numbers 997 and 998 are meant for debugging/testing. returns user answer. */
int checkUserIntInput(int min, int max) {

	cout << endl << "enter number between " << min << " - " << max << " or write 'exit' to exit: ";
	int value = 0;
	string lineRead;
	getline(cin, lineRead);
	stringstream convert(lineRead);
	convert >> value;
	if (value >= min && value <= max || value == 997 || value == 998) {
		return value;
	}
	else if (lineRead == "exit") {
		return -1;
	}
	else {
		cout << endl << "!!!!!!!ERROR!!!!!!!!" << endl << "You must enter number between " << min << " - " << max << " or write 'exit' to exit!" << endl << endl;
	}
}

/*asks user to enter price, price must have 2 decimals. returns price as a float.*/
float priceInput(string text) {
	string wholeNumber;
	int euros;
	int decimals;
	float price;
	char mark;
	while (1) {
		cout << text << endl;
		getline(cin, wholeNumber);
		stringstream convert(wholeNumber);
		if (!(convert >> euros >> mark >> decimals)) {
			cout << "ERROR! you must enter price with 2 decimals!" << endl;
		}
		else if (decimals > 99) {
			cout << "ERROR! there can't be more than 2 decimals!" << endl;
		}
		else {
			price = euros + (((float)decimals) / 100);
			return price;
		}
	}
}