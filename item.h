#pragma once
#include <string>
#include <iostream>
using namespace std;

class item {
	string name;    //name of the product
	string group;   //group of the product (ex: coffee, carbonated drink)
	string desc;    //the description of a product
	int price;      //the price of a product
	int itemId;     //the code/Id of each product
	int stock;      //the number of stock initially
	int minStock = 3;
	item* list;
	
public:
	item() {																			   //constructor
		itemId = 0;
		price = 0;
		stock = 0;
	}

	item (int id,  int priceVal, string title, string brand, string intro, int totStock) { //member initialization
		this->itemId = id;
		this->price = priceVal;
		this->group = brand;
		this->name = title;
		this->desc = intro;
		this->stock = totStock;
	}

	~item() {					 //destructor

	}

	item* initialList() {		 //initializing item list
		item* arr = new item[100];

		item selection1(1, 600, "AQua Water", "Mineral Water", "Refreshing nature water in a bottle", 10);
		item selection2(2, 800, "Macchiato ", "Coffee", "Mini espresso coffee drink with a small amount of milk", 10);
		item selection3(3, 1000, "   7up    ", "Carbonated Drink", "Lemon-limed-flavored non-caffeinated soft drink", 10);
		item selection4(4, 1200, "Ultra Milk", "Dairy Product", "Full cream milk for daily purposes", 2);
		item selection5(5, 1000, "  Fanta   ", "carbonated drink", "Refreshing fruit-flavored soft drink", 0);

		arr[1] = selection1;
		arr[2] = selection2;
		arr[3] = selection3;
		arr[4] = selection4;
		arr[5] = selection5;

		this->list = arr;

		return list;
	}
	
	void startListItem() {	  //to start the list initialization
		list = initialList();
	}

	item* getList() {		  //to get the list
		return list;
	}
	
	void printItem() {		  //to print each item on menu
		cout << "\ncode: " << this->getItemId() <<"\n";
		cout << "name: " << this->getName();
		cout << " (" << this->getPrice() << "won)\n";

		if ((this->getStock()) <= 0)
			cout << "sorry (T.T) stock is currently not available\n";
		else {

		}
	}
	 
	int getPrice() {		 //to get the price
		return this->price;
	}

	int getItemId() {		 //to get the item Id
		return this->itemId;
	}

	int getStock() {		 //to get the stock value
		return this->stock;
	}

	int getMinStock() {      //to get the min stock value
		return minStock;
	}

	void setStock(int newItem) {
		this->stock += newItem;
	}

	string getName() {      //to get the name of the item
		return this->name;
	}

	string getGroup() {      //to get the group of the item
		return this->group;
	}

	string getDesc() {      //to get the description of the item
		return this->desc;
	}

	void printInfo() {      //to print the introduction of each item
		cout << "\n>>>>>>>>>>>>>>>>>" << this->getName() << "<<<<<<<<<<<<<<<<<\n\n";
		cout << this->getDesc();
		cout << "\n\nCategory: " << this->getGroup();
		cout << "\nPrice: " << this->getPrice() << "won";
		cout << "\nStock available: " << this->getStock() << "\n\n";
		cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<\n\n";
	}

};