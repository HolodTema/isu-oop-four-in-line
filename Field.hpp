#ifndef FIELD_HPP
#define FIELD_HPP

#include "Cell.hpp"
#include <iosfwd>

constexpr int FIELD_WIDTH = 7;

constexpr int FIELD_HEIGHT = 6;

class Field {
private:

	bool isRedTurn_;

	Cell winner_;

	Cell cells_[FIELD_WIDTH][FIELD_HEIGHT];



public:

	explicit Field(bool isRedFirst) {
		clear(isRedFirst);
	}

	void clear(bool isRedFirst);

	bool makeTurn(int column);

	void checkWinner();

	bool isOver() const;

	Cell getCell(int i, int j) const;

	bool isRedTurnNow() const;

	void print(std::ostream& os) const;

	void printResult(std::ostream& os) const;



};

#endif
