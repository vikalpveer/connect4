#include "board.h"


Board::Board(int r, int c):nRow(r),nCol(c) {
    std::vector<char>colV(nCol, '.');
	board = std::vector<std::vector<char> >(nRow, colV);
}

void Board::display() {
	for(int i = 1; i <= nCol; i++) {
		std::cout<< i <<" ";
	}
	std::cout<<"\n";

	for (int i = 0; i < nRow; i++) {
		for(int j = 0 ; j < nCol; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout <<"\n";
	}
}
