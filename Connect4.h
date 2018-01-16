#include <iostream>
#include <string>
#include <limits>
#include "board.h"
#include "player.h"

class Connect4 {

	Board b;
	Player p1;
	Player p2;
	int EVA;
	int playout;
	bool init;
	int numMoves;

	public:
	    // Default Game Configuration
		Connect4();
		void initialize();
		bool winner(const char p);
		void play();
	    bool checkCondition(int x, int y, int i, int j, char p);
		int getColumn(char p, int depth, bool isMax);
};
