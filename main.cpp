#include <iostream>
#include "Field.hpp"

int main() {
	Field field(true);

	while (!field.isOver()) {
		field.print(std::cout);
		if (field.isRedTurnNow()) {
			std::cout << "It is red turn now.\n";
		}
		else {
			std::cout << "It is yellow turn now.\n";
		}
		std::cout << "Enter a number of column (1-7):\n";
		int column = 0;
		std::cin >> column;
		if (column < 1 || column > 7) {
			std::cout << "Error: you need to enter number from 1 to 7\n";
			continue;;
		}
		field.makeTurn(column);
	}
	field.printResult(std::cout);

	return 0;
}
