#include <iostream>

class Connect4 {

	int row;
	int col;

	public:
	    // Default Game Configuration
		Connect4():row(6),col(7){};
		void drawBoard();
};
