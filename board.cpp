#include "board.h"


// Definition for static members 
const int Board::nRow;
const int Board::nCol;
const char Board::X;
const char Board::O;
const char Board::DEF;

//constructor
Board::Board() {

	// initialize each entry of board to '.'
    std::vector<char>rowV(nRow, DEF);
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

	// if element to insert is not '.' ie X or O is being inserted
	// find the first empty row (denoted by '.') and insert piece at this row.
	if(p != DEF) {
		// reverse iterator as you need to find the empty slot from the bottom.

	    std::vector<char>::reverse_iterator it = board[index].rbegin();
	
	    for(; it != board[index].rend(); it++) {
		    if (p != DEF && *it == DEF) {
                *it = p;
                break;
            }
	    }
	}else {

		// this is a request to reset a row of a column. 
		// start from top and look for the first non-empty piece and reset it with DEF

	    std::vector<char>::iterator it = board[index].begin();
	    for(; it != board[index].end(); it++) {
		    if (p == DEF && *it != DEF ){
		        *it = DEF;
		        break;
			}
		}
	}
	return true;
}

// Find if the column to which a piece is to be inserted has empty slot.
bool Board::validMove(const int index) {
 	
	// Is it a valid column ?
	if(index < 1 || index  > nCol) {
		return false;
	}

	// there is no empty slot in this column
	if(board[index - 1].front() != DEF) {
		return false;
	}

	// column is valid and there is an empty slot
	return true;
}

// Return piece at a give row and column
const char Board::getElem(int i, int j) {
	if(j < 0 || j >= nCol || i < 0 || i >= nRow) {
        return -1;
	}
	return board[j].at(i);
}
