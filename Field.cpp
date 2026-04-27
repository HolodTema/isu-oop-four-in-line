#include "Field.hpp"
#include <iostream>

void Field::clear(bool isRedFirst) {
	isRedTurn_ = isRedFirst;
	winner_ = Cell::EMPTY;
	for (int i = 0; i < FIELD_WIDTH; ++i) {
		for (int j = 0; j < FIELD_HEIGHT; ++j) {
			cells_[i][j] = Cell::EMPTY;
		}
	}
}

bool Field::makeTurn(int column) {
	if (winner_ != Cell::EMPTY || column < 1 || column > FIELD_WIDTH) {
		return false;
	}

	int i = column - 1;
	for (int j = 0; j < FIELD_HEIGHT; ++j) {
		if (cells_[i][j] == Cell::EMPTY) {
			cells_[i][j] = isRedTurn_ ? Cell::RED : Cell::YELLOW;

			checkWinner();

			isRedTurn_ = !isRedTurn_;
			return true;
		}
	}
	return false;
}


void Field::checkWinner() {

}

Cell Field::getCell(int i, int j) const {
	return cells_[i][j];
}

bool Field::isRedTurnNow() const {
	return isRedTurn_;
}

void Field::print(std::ostream& os) const {
	for (int i = 1; i <= FIELD_WIDTH; ++i) {
		os << i << "\t";
	}
	os << "\n";

	for (int i = 0; i < FIELD_HEIGHT; ++i) {
		for (int j = 0; j < FIELD_WIDTH; ++j) {
			os << cells_[j][i] << "\t";
		}
		os << "\n";
	}
}

void Field::printResult(std::ostream& os) const {
	os << "Winner: " << winner_ << "\n";
}

