#include <iostream>


#include "JoeExotic.h"

int main() {
	JoeExotic tigerKing;
	while (tigerKing.RunningTheZoo())
		std::cout << tigerKing << std::endl;

	std::cout << "The tiger king is in jail" << std::endl;
	return 0;
}