#ifndef CELL_HPP
#define CELL_HPP

#include <iosfwd>

enum class Cell {
	EMPTY,
	RED,
	YELLOW
};

std::ostream& operator<<(std::ostream& os, const Cell& cell);

#endif //CELL_HPP