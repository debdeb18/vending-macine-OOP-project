#pragma once
#include <iostream>
#include "item.h"
#include "transaction.h"

class vendingMachine : public transaction
{
	int Id = 2020;
	bool systemStatus;
public: 
	vendingMachine() {			//constructor
		systemStatus = true;
	}

	~vendingMachine() {			//destructor

	}

	int getId() {				//to get the vending machine id
		return Id;
	}

	void startList() {			//to start the list
		transaction::startListItem();
	}

	void welcome() {			//the welcome format
		cout << "Thirsty? feed me some coin and I'll give you drink(s)\n";
		cout << "insert your coin c('-'c) \nmin 600 won :P\n**Only coin 10, 50, 100, 500 is supported\n";
		
		transaction::printBalance();  //print current balance
		transaction::addCoin();		  //to input user coin

		while (transaction::getBalance() < 600) {   //loop will stop after min coin of 600 won is inputted
			cout << "insert more coin (p'-')p \nmin 600 won :P\n";
			transaction::addCoin();
		}
	
	}

	void menuList() { //it print the menu
		cout << "\n\n>>>>>>>>>>>>>>>>>>> menu <<<<<<<<<<<<<<<<<<<\n";
		for (int i = 1; i <= 5; i++) {
			transaction::getList()[i].printItem();
		}
		cout << "\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<\n\n";
		transaction::printBalance();
	}

	bool getSystemStatus() { //send system status of broken or not
		return systemStatus;
	}

	void setSystemStatus(bool send) {
		systemStatus = send;
	}

	void takingSelection() {  //taking the user choice of item
		int money = transaction::getBalance(); //initialize current balance
		int wantItem;						   //keep the users choosen item Id
		int bill;							   //keep the choosen item price

		do {
			wantItem = choice(); //initializing the user choosen item Id
			transaction::getList()[wantItem].printInfo(); //print the introduction
			transaction::printBalance(); //print the current balance
			bill = transaction::getList()[wantItem].getPrice(); //initialize the choosen item's price

		} while (checkStock(wantItem) == false); //will repeat if the choosen item's stock is empty

		do {
			if (money >= bill) { //if current balance sufficient
				select(bill, wantItem, getId()); //run the select function
				if (getDone() == false) { //if return to menu
					break;
				}
			}
			else {
				moreCoin(bill);  //if current balance is not sufficient
				select(bill, wantItem, getId()); //run the select function
				if (getDone() == false) { //if return to menu
					break;
				}
			}
		} while (0);
	}

	bool checkStock(int id) { //check if stock is available
		int i = id;
		if (transaction::getList()[i].getStock() <= 0) { //if stock is not available
			cout << "Sorry item is not available \nPlease select another one\n";
			return false;
		}
		else { //if stock is available
			return true;
		}
	}
};


