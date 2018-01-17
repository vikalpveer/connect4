#include <iostream>
#include <vector>

class Board {

	//Board is a 2D vector of char.
	std::vector<std::vector<char> > board;



	public:
		//number of row in a board
		static const int nRow = 6;

		//number of col in a board
		static const int nCol = 7;

		// const char for piece and default char for board
		static const char X = 'X';
		static const char O = 'O';
		static const char DEF = '.';

	    //Constructor
	    Board();

		//  Destructor
		~Board(){};

		// Display current Board
		void draw();

		// Set the given piece to the top of the given column.
		bool setCol(const int move, const char p);

		//returns if a piece can be inserted into a given column
		bool validMove(const int move);

		// returns element of a given row and column
		const char getElem(int row, int col);
};
