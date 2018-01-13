#include <iostream>
#include <vector>

class Board {
	std::vector<std::vector<char> > board;
	const int nRow;
	const int nCol;

	public:
	    Board(int r, int c);
		void draw();
		int setCol(const int move, const char p);
};
