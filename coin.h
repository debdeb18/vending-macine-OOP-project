#pragma once
#include <string>
#include <iostream>
using namespace std;

class coin
{
	int coinValue;
public:
	coin() {
		coinValue = 0;
	}

	int coinRead(int in) {  //to check if the coin is allowed or not
		coinValue = in;

		if (coinValue == 10) { //if 10won
			return coinValue;
		}
		else if (coinValue == 50) { //if 50won
			return coinValue;
		}
		else if (coinValue == 100) { //if 100 won
			return coinValue;
		}
		else if (coinValue == 500) { //if 500 won
			return coinValue;
		}
		else {
			cout << "coin not supported\n**Only coin 10, 50, 100, 500 is supported\n";
			return coinValue = 0;
		}

	}
};

