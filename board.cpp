#include "board.h"


// Definition for num row and num col
const int Board::nRow;
const int Board::nCol;

//constructor
Board::Board() {

	// initialize each entry of board to '.'
    std::vector<char>rowV(nRow, '.');
	board = std::vector<std::vector<char> >(nCol, rowV);
}


// Display current board

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

bool Board::setCol(const int move, const char p) {

	int index = move - 1;

	if(p != '.') {
	    std::vector<char>::reverse_iterator it = board[index].rbegin();
	
	    for(; it != board[index].rend(); it++) {
		    if (p != '.' && *it == '.') {
                *it = p;
                break;
            }
	    }
	}else {
	    std::vector<char>::iterator it = board[index].begin();
	    for(; it != board[index].end(); it++) {
		    if (p == '.' && *it != '.') {
		        *it = '.';
		        break;
			}
		}
	}
	return true;
}

bool Board::validMove(const int index) {

	if(index < 1 || index  > nCol) {
		return false;
	}

	if(board[index - 1].front() != '.') {
		return false;
	}
	return true;
}

const char Board::getElem(int i, int j) {
	if(j < 0 || j >= nCol || i < 0 || i >= nRow) {
        return -1;
	}
	return board[j].at(i);
}


