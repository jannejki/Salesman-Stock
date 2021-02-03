#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "GeneralFunctions.h"
#include "ItemsForSale.h"
#include "ItemList.h"
#include "SoldItems.h"


using namespace std;

void main() {

	ItemsForSale items;
	SoldItems sold;
	int userInput = 0;

	while (userInput != -1) {
		cout << endl << "*************MAIN MENU*************" << endl;
		cout << "[1] Initialize (clear stock listing)\n" << +
			+"[2] Read stock listing from file\n" << +
			"[3] Add a new item to list\n" << +
			"[4] Sell an item\n" << +
			"[5] Replenish stock\n" << +
			"[6] Print a report\n";

		userInput = checkUserIntInput(1, 7);
		switch (userInput) {
		case 1: {
			items.initialize("Stockfile.txt");
			system("pause");
		}
			  break;

		case 2: {
			cout << endl << "**********STOCK***********" << endl;
			items.printVectorInfo(items.readStock("Stockfile.txt"));
			system("pause");
		}
			  break;
		case 3: {
			items.addItem("Stockfile.txt");
			system("pause");
		}
			  break;
		case 4: {
			items.sellItem(sold);
			system("pause");
		}
			  break;
		case 5: {
			items.replenish();
			system("pause");
		}
			  break;

		//prints a report that contains items in stock, sold items and revenue
		case 6: {
			cout << endl << "**************REPORT*************" << endl;
			items.printReport();
			sold.printReport();
			system("pause");
		}
			  break;

		// Next cases are not meant for normal users, only for testing
		case 997: {
			if (yesOrNo("WARNING! initializing Soldfile!"))
				sold.initialize("Soldfile.txt");
			system("pause");
		} break;
		case 998: {
			cout << endl << "**********SOLD***********" << endl;
			sold.readStock("Soldfile.txt");
		} break;
		}
	}
}