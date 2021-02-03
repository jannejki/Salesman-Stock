#include "ItemsForSale.h"

/*Prints list of items in stock and then asks user which item user wants to sell
  Then creates a vector of items without the item that is sold, overwrites the 
  Stockfile.txt with the vector and adds the sold item to Soldfile.txt*/
void ItemsForSale::sellItem(SoldItems& soldItem) {

	int userInput = 0, removeCounter = 1;
	string name, priceString;
	float price;
	fstream findItem("Stockfile.txt");
	vector<Item> vecSoldItem;

	if (findItem.is_open() && !(findItem.peek() == ifstream::traits_type::eof())) {

		while (userInput <= 0 || userInput > forSale) {
			cout << endl << "*********SELL ITEM********" << endl;
			printVectorInfo(readStock("Stockfile.txt"));
			cout << "What item you want to sell?";
			userInput = checkUserIntInput(1, forSale);
			if (userInput == -1)
				return;
		}
		while (getline(findItem, name, ';')) {
			getline(findItem, priceString);
			stringstream convertPrice(priceString);
			convertPrice >> price;

			if (removeCounter != userInput) {
				itemsToSave.push_back(Item(name, price));
			}
			else {
				vecSoldItem.push_back(Item(name, price));
				if (!soldItem.saveFile("Soldfile.txt", vecSoldItem)) {
					cout << "something went wrong while saving items to Soldfile! " << endl;
				}
			}
			removeCounter++;
		}
		ofstream findItem("Stockfile.txt", ofstream::trunc);
		if (!saveFile("Stockfile.txt", itemsToSave)) {
			cout << "something went wrong while saving stockfile!" << endl;
		}
		else {
			itemsToSave.clear();
			findItem.close();
			itemsForSale -= 1;
			cout << "SOLD!" << endl;
		}
	}
	else if (findItem.is_open() && (findItem.peek() == ifstream::traits_type::eof())) {
		cout << "no items to be sold!" << endl;
	}
	else {
		cout << "ERROR! can not open the Stock file." << endl;
	}
}

/*Adds 11 items to item vector, adds vector to Stockfile.txt, then clears vector.*/
void ItemsForSale::replenish() {
	if (itemsToSave.size() == 0) {
		itemsToSave.push_back(Item("muki", 50.0));
		itemsToSave.push_back(Item("lasi", 100.0));
		itemsToSave.push_back(Item("kuppi", 75.0));
		itemsToSave.push_back(Item("puhelin", 300.0));
		itemsToSave.push_back(Item("tietokone", 999.0));
		itemsToSave.push_back(Item("lamppu", 30.0));
		itemsToSave.push_back(Item("kaiutin", 60.0));
		itemsToSave.push_back(Item("poyta", 300.0));
		itemsToSave.push_back(Item("kuulokkeet", 123.0));
		itemsToSave.push_back(Item("kello", 22.0));
		itemsToSave.push_back(Item("nappis", 124.0));

		if (saveFile("Stockfile.txt", itemsToSave)) {
			cout << "STOCK REPLENISHED!" << endl;
			itemsForSale += 11;
			itemsToSave.clear();
		}
		else {
			cout << "something went wrong!" << endl;
		}
	}
}

/*Prnts list of items in Stock*/
void ItemsForSale::printReport() {
	cout << "Items in stock: " << endl;
	printVectorInfo(readStock("Stockfile.txt"));
	cout << endl;
}
