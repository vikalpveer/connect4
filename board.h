#include <iostream>
#include <vector>

class Board {
	std::vector<std::vector<char> > board;
	const int nRow;
	const int nCol;

	public:
	    Board(int r, int c):nRow(r),nCol(c) {
			std::vector<char>rowV(nRow, '.');
			board = std::vector<std::vector<char> >(nCol, rowV);
		}
		void display();
};
