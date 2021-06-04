#include "vendingMachine.h" 
#include <iostream>
using namespace std;

int main() {
	vendingMachine vm;
	if (vm.getSystemStatus() == false) { //check the system broken or not
		cout << "Sorry. The system is under maintenance right now."; //send error if broken
	}
	else {
		vm.startList(); //initialist item list
		vm.welcome(); //print welcome
		do {
			vm.iniDone(); 
			vm.menuList(); //print menu list
			vm.takingSelection(); // start taking user choice and operate
		} while (vm.getDone() == true); //repeat if user want to repeat
	}
}