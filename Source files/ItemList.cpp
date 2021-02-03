#include "ItemList.h"
#include "GeneralFunctions.h"

ItemList::ItemList() {
}

/*Empties the whole file.*/
void ItemList::initialize(string fileName) {
	if (yesOrNo("Are you sure? all items will be deleted!")) {
		ofstream emptyFile;
		emptyFile.open(fileName);
		if (emptyFile.is_open()) {
			emptyFile.open(fileName, ios::binary | ios::out | ios::trunc);
			cout << endl << "Cleared! " << endl;
			emptyFile.close();
		}
		else {
			cout << "ERROR! Unable to open file!" << endl;
		}
	}
}

/*saves items to file. returns true if file is opened
  and returns false if file is unable to open.*/
bool ItemList::saveFile(string fileName, vector<Item> item) {
	ofstream writeFile(fileName, ios::app);
	if (writeFile.is_open()) {
		for (auto v : item)
			writeFile << v;
		writeFile.close();
		return true;
	}
	else {
		cout << endl << "Unable to open file" << endl;
		return false;
	}
}

/*Reads files and creates vector of objects from those and returns the vector..*/
vector<Item> ItemList::readStock(string text) {
	string name, price;
	forSale = 0;
	ifstream readFile(text);
	vector<Item> printItems;

	if (readFile.is_open()) {
		if (!(readFile.peek() == ifstream::traits_type::eof())) {
			while (getline(readFile, name, ';')) {
				getline(readFile, price);
				printItems.push_back(Item(name, stof(price)));
				forSale++;
			}
		}
	}
	else {
		cout << endl << "ERROR! Unable to open file" << endl;
	}
	return printItems;
}

/*Asks name and price from the user and creates item objects to vector,
  after user is done adding item info, function saves vector to file and 
  then clears vector.*/
void ItemList::addItem(string fileName) {
	cout << endl << "********ADD ITEM********" << endl;
	string tempName;
	float tempPrice;
	char userInput;

	cout << "Give name of the item ('exit' to exit): ";
	getline(cin, tempName);

	if (tempName == "exit") {
		return;
	}
	tempPrice = priceInput("Give price of the item: ");
	itemsToSave.push_back(Item(tempName, tempPrice));

	if (yesOrNo("Do you want to add another item?")) {
		addItem(fileName);
	}
	else {
		if (yesOrNo("\nDo you want to save stock?\nWARNING! if not saved, items will be lost!")) {
			if (saveFile(fileName, itemsToSave)) {
				cout << endl << "ITEMS SAVED!" << endl;
			}
			else {
				cout << "ERROR! something went wrong, items not saved!" << endl;
			}
		}
		itemsToSave.clear();
	}
}

/*takes a vector of items as a parameter and then prints items*/
void ItemList::printVectorInfo(vector<Item> printItems) {

	if (printItems.size() != 0) {
		unsigned __int64 longestName = 0;
		int listNumber = 1;

		for (auto v : printItems) {
			if (v.outputName().length() > longestName) {
				longestName = v.outputName().length();
			}
		}
		longestName = static_cast<unsigned __int64>((longestName + 10));
		cout << "item:" << setw(longestName) << "Price:" << fixed << setprecision(2) << endl;
		for (auto v : printItems) {
			if (listNumber <= 9) {
				cout << listNumber << ". " << v.outputName() << setw(longestName +2 - v.outputName().length()) << v.outputPrice() << endl;
			}
			else {
				cout << listNumber << ". " << v.outputName() << setw(longestName +1 - v.outputName().length()) << v.outputPrice() << endl;
			}
			listNumber++;
		}
		cout << endl;
	}
	else {
		cout << "no items to be sold!" << endl;
	}
}