#include "Cell.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
	if (cell == Cell::EMPTY) {
		os << "E";
	}
	if (cell == Cell::RED) {
		os << "R";
	}
	if (cell == Cell::YELLOW) {
		os << "Y";
	}
	return os;
}