#include "board.h"


Board::Board(int r, int c):nRow(r),nCol(c) {
    std::vector<char>rowV(nRow, '.');
	board = std::vector<std::vector<char> >(nCol, rowV);
}

void Board::draw() {
    std::cout << "-----------------------------------\n";
	for(int i = 1; i <= nCol; i++) {
		std::cout<< i <<" ";
	}
	std::cout<<"\n";

	for (int i = 0; i < nRow; i++) {
		for(int j = 0; j < nCol; j++) {
			std::cout << board[j].at(i) << " ";
		}

		std::cout <<"\n";
	}
}

int Board::setCol(const int move, const char p) {

	int index = move - 1;

	if(board[index].front() != '.') {
		std::cout << "ERR: You cannot choose this column \n";
		std::cout << "-----------------------------------\n";
		return 0;
	}

	std::vector<char>::iterator it = board[index].end();
	for(; it >= board[index].begin(); it--) {
		if (*it == '.') {
			*it = p;
			return 1;
		}
	}
	return 0;
}
