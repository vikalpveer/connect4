#include <iostream>
#include "board.h"
#include "player.h"

class Connect4 {

	Board b;
	Player p1;
	Player p2;
	bool init;

	public:
	    // Default Game Configuration
		Connect4(int r, int c);
		void initialize();
		void play();
};
