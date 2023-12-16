#include "GroceryItem.h"
#include <string>

//Implementation for GroceryItem

//Constructor for GroceryItem
//@param name - the name of the grocery item
GroceryItem::GroceryItem(std::string& name) {
	this->name = name;
	this->quantity = 0;
}

//Constructor for GroceryItem with quantity (overloaded)
//@param name - the name of the grocery item
//@param quantity - the quantity of the grocery item
GroceryItem::GroceryItem(std::string name, int quantity) {
	this->name = name;
	this->quantity = quantity;
}

//Accessors

//Get the name of the grocery item
//@returns - the name of the grocery item
std::string GroceryItem::getName() const {
	return name;
}

//Get the quantity of the grocery item
//@returns - the quantity of the grocery item
int GroceryItem::getQuantity() const {
	return quantity;
}

//Mutators

//Add one to the quantity of the grocery item
void GroceryItem::addItem() {
	quantity++;
}

//Remove one from the quantity of the grocery item
void GroceryItem::removeItem() {
	quantity--;
}

//Overloaded < operator
//@param other - the other grocery item to compare to
//@returns - true if this grocery item's name is less than the other grocery item's name, false otherwise
bool GroceryItem::operator<(const GroceryItem& other) const {
	return name.compare(other.getName()) < 0;
}