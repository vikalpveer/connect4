#include <iostream>
#include <string>
#include <limits>
#include "board.h"
#include "player.h"

class Connect4 {

	Board b;
	Player p1;
	Player p2;
	bool init;
	int numMoves;
	int SCORE;
	int COUNT;
	static const int INF = 9999999;
	static const int WINSEQ = 4;

	public:
		//Constructor
		Connect4();

		//Destructor
		~Connect4(){}

		// initialize game logic
		void initialize();

		// determine if there is a winner
		bool winner(const char p);

		// check condition for winning combination
	    bool checkCondition(int x, int y, int i, int j, char p);

		// make a move
		void play();
		
		// getBestColumn for the piece .. when it is computer's move
		int getBestColumn(char p, int depth, bool isMax);
};
