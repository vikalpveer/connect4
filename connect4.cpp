#include "connect4.h"

Connect4::Connect4(int r, int c) : b(r,c),p1(),p2(),init(false) {
}
void Connect4::play() {
	 if(!init) {
		 initialize();
	 }
	 while(1) {
		 int move;
		 int turn;
		 char piece;

		 if(p1.getTurn()) {
			 turn = 1;
			 piece = 'X';
		 }else {
			 turn = 2;
			 piece = 'O';
		 }
		  
		 std::cout <<"Player "<< turn <<" : Your Turn \n";
		 std::cout <<"Select the column you would like to play \n";
		 std::cin >> move;

		 if(move < 1 || move > 7) {
			 std::cout <<"Invalid Input. Try Again ! \n";
			 continue;
		 }

		 if(b.setCol(move, piece)) {
			 if(turn == 1) {
				 p1.setTurn(false);
				 p2.setTurn(true);
			 }else {
				 p1.setTurn(true);
				 p2.setTurn(false);
			 }
			 b.draw();
		 }
	 }
}

void Connect4::initialize() {
	std::cout <<"            WELCOME            " << "\n";
	std::cout <<".............................. " << "\n";

	char turn;

	while(1) {
	    std::cout <<"Do you want to take the fist turn y/n ?" << "\n";
		std::cin >> turn;
		if(turn == 'y' || turn == 'n') {
			if(turn == 'y') {
			    p1.setPiece('X');
			    p2.setPiece('O');
				p1.setTurn(true);
			}else {
			    p1.setPiece('O');
			    p2.setPiece('X');
				p2.setTurn(true);
			}
			init = true;
			break;
		}else {
			std::cout << "Invalid Input \n";
		}
	}
}
