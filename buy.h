#pragma once
#include "item.h"
#include <iostream>
using namespace std;

class buy : public item
{
	int i;       //number of bought
	int series;  //series of vending machine (id)
	int id;      //item Id
public:
	buy() {																//constructor
		i = 0;
		series = 0;
		id = 0;
	}

	void updateStock(int vmId, int wantItem) {							//update stock value everytime an item is bought
		i = -1;
		id = wantItem;
		series = vmId;
		notifyOwnerBought();											//send owner a notification that an item has been bought
		item::getList()[id].setStock(i);
		if (item::getList()[id].getStock() < item::getMinStock()) {
			notifySupplier();											//notify owner if an item stock is under 3
			notifyOwnerStock();											//send owner a notification that an item has been restocked
		}
		else {
			
		}

	}

	void notifySupplier() {												//supplier notification sent form
		cout << "***Notification request to management center***\n\n";
		cout << "item specification\n";
		cout << "name: " << item::getList()[id].getName() << "\nItem ID: " << id;
		cout << "\nThis item's stock of vending machine "<<series<<" is under the minimum stock set. Please resupply this product.\n******";
	}

	void notifyOwnerBought() {											//owner item bought notification sent form
		cout << "\n\n**Notification to owner**\n";
		cout << "\nVending Machine ID: " << series;
		cout << "\nUpdate:";
		cout << "an item is sold just now, Item ID: " << id << "(" << item::getList()[id].getName() << ")\n****";
	}

	void notifyOwnerStock() {											//owner item restock notification sent form
		cout << "\n\n**Notification to owner**\n";
		cout << "\nVending Machine ID: " << series;
		cout << "\nUpdate:";
		cout << "a request of supply (of Item ID: " << id << "(" << item::getList()[id].getName() << ") has just been sent to the management center\n****";
	}

};

