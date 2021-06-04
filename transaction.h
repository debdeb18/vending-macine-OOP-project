#pragma once
#include <iostream>
#include "item.h"
#include "coin.h"
#include "buy.h"
using namespace std;


class transaction : public coin, public buy
{
	int transId;
	int balance;
	int itemSel;
	int proceed;
	bool done;
public:
	transaction() { // constructor
		balance = 0;
		done = false;
		itemSel = 0;
		proceed = true;
		transId = 0;
	}

	~transaction() { //destructor

	}

	void updateBalance(int coinVal) { //update current balance
		int coinInOut = coinVal;
		balance += coinInOut;
	}

	void addCoin() { //input user's inputted coin
		int coinIn;
		cin >> coinIn;
		updateBalance(coinRead(coinIn)); //update balance
		printBalance(); //print current balance
	}

	int getBalance() { //to get balance
		return balance;
	}

	void printBalance() {//to print current balance
		cout << "\t\tcurrent balance: " << getBalance() << "won\n\n";
	}

	void menuList() {//to print the menu's list
		for (int i = 1; i <= 5; i++) {
			buy::getList()[i].printItem();
		}
	}

	int choice() { //to check if the user's choice is availablee
		int id;
		
		do {
			cout << "\nyou may choose the drink you want\ntype in the code number below\n";
			cin >> id;
			if (id < 0 || id > 5) { //if code invalid, send error message
				cout << "\nError. the product code is not available please try again\n\n\n";
			}
			else {
				break;
			}
		} while (1); //repeat if user's input is error

		return id;
	}

	void select(int bill, int id, int vmId) { //to print out selectioin menu of continue or cancel
		int bought = bill;

		if (getDone() == true) { //if back to menu, exit function
			return;
		}
		else {
			cout << "Do you want to buy(1) or cancel(0)?\n"; 

			do {
				cout << "Type the selection number\n";
				cin >> proceed;

				if (proceed == 1) { //if user select buy, proceed
					buy::updateStock(vmId, id); //update item's stock
					buyItem(); //run buyItem function
					changeCoin(bought); //reducing coin ->> balance - item's price
					break;
				}
				if (proceed == 0) { //if cancel, the dont proceed
					cancel();//run cancel function instead
					break;
				}
				else
					cout << "choice not available\n\n";
			} while (proceed == 1 || 0); //repeat if user's choice not available
		}
	}

	void moreCoin(int price) { //if coin is not enough then ask continue or back to menu
		cout << "\nyour balance is not enough..";
		cout << "Do you want to back to menu(0) or continue(1) or cancel(2)?\n";
		do {
			cout << "Type the selection number\n";
			cin >> proceed;

			if (proceed == 1) { //if continue
				moreCoinStatement(price); //ask more coin
				break;
			}
			if (proceed == 0) {//if back to menu
				cout << "back to menu\n";
				done = true;
				break;
			}
			if (proceed == 2) { //if cancel
				cancel(); //run cancel function
				break;
			}
			else
				cout << "choice not available\n\n";
		} while (proceed != 1 || 0 || 2);
	}

	void moreCoinStatement(int price) { //ask for more coin
		int p = price;
		do {
			cout << "\nyour balance is not enough..";
			cout << "\nplease insert more coin\n";
			addCoin();
		} while (getBalance() < p); //repeat until coin is sufficient to buy 
	}

	void buyItem() { //if user decide to buy
		cout << "\n\nPlease take your item\nThank you 6(~.~)9\n\n";
		cout << "Do you want to continue(1) or exit(0)?\n"; //ask want to continue or exit

		do {  
			cout << "Type the selection number\n";
			cin >> proceed;

			if (proceed == 1) { //if back to menu
				cout << "back to menu\n";
				done = true;
				break;
			}
			if (proceed == 0) { //if exit
				cout << "exit\n";
				dispenseCoin();//return coin if any
				break;
			}
			else
				cout << "choice not available\n\n";
		} while (proceed == 1 || 0); //repeat if user's input not available
	}

	void cancel() { //if user choose to cancel
		cout << "\nawh too bad (o.O) but okayy\n\n";
		cout << "back to menu(1) or exit(0)?\n";

		do {
			cout << "Type the selection number\n";
			cin >> proceed;

			if (proceed == 1) { //if back to menu
				cout << "back to menu\n\n";
				done = true;
				break;
			}
			if (proceed == 0) { //if choose to exit
				cout << "\nplease take your coin\n\n";
				dispenseCoin(); //return input coin if any
				break;
			}
			else
				cout << "choice not available\n\n";
		} while (proceed == true || false); //will repeat if user's input invalid
	}

	void iniDone() { //for back to menu
		done = false;
	}

	bool getDone() { //to get bool done
		return done;
	}

	void changeCoin(int bill) { //to minus the current balance with the bought item's price
		int coinValue = -(bill);
		updateBalance(coinValue); // update balance
	}

	void dispenseCoin() { //if return all coin
		int coinValue = -(getBalance());
		updateBalance(coinValue); //update balance to 0
	}

};

