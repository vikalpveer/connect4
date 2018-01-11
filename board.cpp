#include "board.h"

void Board::display() {
	std::cout <<"Num Row"<<nRow <<"Num Col:"<<nCol <<"\n";
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
