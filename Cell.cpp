#include "Cell.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
	if (cell == Cell::EMPTY) {
		os << "EMPTY";
	}
	if (cell == Cell::RED) {
		os << "RED";
	}
	if (cell == Cell::YELLOW) {
		os << "YELLOW";
	}
	return os;
}