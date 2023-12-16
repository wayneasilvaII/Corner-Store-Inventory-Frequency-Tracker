#include <iostream>
#include <fstream>
#include "GroceryItem.h"
#include <set>

using namespace std;

std::set<GroceryItem> retrieveInventory() { //retrieve inventory from inventory.txt and write to frequency.dat
	set<GroceryItem> items;

	ifstream inFS;
	inFS.open("inventory.txt"); //open inventory.txt
	if (!inFS.is_open()) { //return empty set if file cannot be opened
		cout << "Could not open file inventory.txt." << endl; //error message
		return items;
	}

	string name;

	while (!inFS.eof()) { //read inventory.txt
		getline(inFS, name); //get name of item on each line
		GroceryItem* itemPtr = new GroceryItem(name); //create new item with name
		auto existingItem = items.find(*itemPtr); //check if item already exists in set
		
		if (existingItem != items.end()) { //if item already exists, remove it from set and create new item with existing quantity
			string existingName = existingItem->getName(); 
			int existingQuantity = existingItem->getQuantity();
			items.erase(*existingItem); //remove existing item from set
			itemPtr = new GroceryItem(existingName, existingQuantity); //create new item with existing name and quantity
		}

		itemPtr->addItem(); //add one to quantity of item
		items.insert(*itemPtr); //insert item into set
		delete itemPtr; //delete item pointer
	}

	//write items into frequency.txt
	ofstream outFS;
	outFS.open("frequency.dat"); //open frequency.dat
	if (!outFS.is_open()) { //return empty set if file cannot be opened
		cout << "Could not open file frequency.txt." << endl;
		return items;
	}

	for (auto it = items.begin(); it != items.end(); ++it) { //write items to frequency.dat
		outFS << it->getName() << " " << it->getQuantity() << endl; 
	}

	outFS.close(); //close frequency.dat
	inFS.close(); //close inventory.txt

	return items;
}

void printMenu() { //print menu
	cout << "1. Search for an item" << endl;
	cout << "2. Display all frequencies" << endl;
	cout << "3. Print histogram" << endl;
	cout << "4. Exit" << endl;
};

int main() { //main function
	int menuSelection;
	string searchItem;

	retrieveInventory(); //retrieve inventory and write to frequency.dat

	do {
		printMenu();

		try { //get the user choice and handle invalid input
			cin >> menuSelection;
			if (cin.fail()) { //if input is not an integer, throw runtime error
				throw runtime_error("Invalid input!");
			}
		}
		catch (runtime_error& excpt) { //catch runtime error and print error message
			cout << excpt.what() << endl;
			cin.clear(); //clear cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore input until new line
			continue;
		}
		//Handle the user choice
		switch (menuSelection) {
			//Search option
		case 1:
			cout << "Enter item to search: ";
			cin >> searchItem;

			for (GroceryItem item : retrieveInventory()){ //search for item
				if (item.getName() == searchItem) { //if item is found, print item name and quantity
					cout << item.getName() << " " << item.getQuantity() << endl;
					break;
				}
			}

			break;
		case 2:
			for (GroceryItem item : retrieveInventory()) { //search for item and print item name and frequency
				cout << item.getName() << " " << item.getQuantity() << endl;
			}
			break;
			
		case 3:
			for (GroceryItem item : retrieveInventory()) { //search for item and print item name and frequency as a histogram
				cout << item.getName() << " " << std::string(item.getQuantity(), '*') << endl; //print item name and quantity as a string of asterisks
			}
			cout << endl;
			break;
			
		case 4:
			cout << "Good Bye!" << endl;
			break;
		default:
			cout << "Invalid input!" << endl; //error message for invalid input
			break;
		}
	} while (menuSelection != 4); //loop will exit when the user enters 4

}
