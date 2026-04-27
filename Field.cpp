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
	constexpr int DIR_NUMBER = 4;
	constexpr int WIN_LENGTH = 4;

	constexpr int di[] = {1, 0, 1, 1};
	constexpr int dj[] = {0, 1, -1, 1};

	for (int i = 0; i < FIELD_WIDTH; ++i) {
		for (int j = 0; j < FIELD_HEIGHT; ++j) {
			Cell cellStart = cells_[i][j];
			if (cellStart == Cell::EMPTY) {
				continue;
			}

			for (int dir = 0; dir < DIR_NUMBER; ++dir) {
				int length = 1;
				int iLine = i;
				int jLine = j;
				while (length < WIN_LENGTH) {
					length++;
					iLine += di[dir];
					jLine += dj[dir];
					if (iLine < 0 || iLine >= FIELD_WIDTH) {
						break;
					}
					if (jLine < 0 || jLine >= FIELD_HEIGHT) {
						break;
					}
					if (cells_[iLine][jLine] != cellStart) {
						break;
					}
				}
				if (length == WIN_LENGTH) {
					winner_ = cellStart;
					return;
				}
			}
		}
	}
}

bool Field::isOver() const {
	if (winner_ != Cell::EMPTY) {
		return true;
	}
	for (int i = 0; i < FIELD_WIDTH; ++i) {
		for (int j = 0; j < FIELD_HEIGHT; ++j) {
			if (cells_[i][j] == Cell::EMPTY) {
				return false;
			}
		}
	}
	return true;
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

