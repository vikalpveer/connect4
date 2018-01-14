#include "connect4.h"

Connect4::Connect4(int r, int c) : b(r,c),p1(),p2(),init(false) {
}
void Connect4::play() {
	 if(!init) {
		 initialize();
	 }
	 while(1) {
		 int turn;
		 char piece;
		 int move;

		 if(p1.getTurn()) {
			 turn = 1;
			 piece = 'X';
		 }else if(p2.getTurn()){
			 turn = 2;
			 piece = 'O';
		 }
		  
		 std::cout <<"Player "<< turn <<" : Your Turn \n";
		 std::cout <<"Select the column you would like to play : \n";

		 std::cin.clear();
		 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		 std::cin >> move;

		 if(move < 1 || move > 7) {
			 std::cout <<"ERR: Invalid Input. Try Again ! \n";
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
		 if(winner(piece)) {
			 if(turn ==1) {
				 std::cout << "Player 1 is a winner \n";
			 }else {
				 std::cout << "Player 2 is a winner \n";
			 }

			 break;
		 }
	 }
	 
}

bool Connect4::winner(const char p) {

	bool isWinner = false;

	for(int i = 0; i < 6 && !isWinner; i++) {
		for(int j = 0; j < 7; j++) {
			isWinner = checkCondition(i, j, 1, 0, p) ||
			           checkCondition(i, j, 1, 1, p) ||
			           checkCondition(i, j, 1,-1, p);
			if(isWinner) {
				break;
			}
		}
	}

	return isWinner;
}


bool Connect4::checkCondition(int x, int y, int i, int j, char p) {

	int k;
	for(k = 0; k < 4; k++) {
	    if(x + i*k >= 6 || (x + i*k < 0) || y + j*k>=7 || y + j*k < 0) {
		    return false;
	    }

		if(b.getElem(x + i*k, y + j*k) == p) {
			continue;
		}else {
			break;
		}
	}

	if(k == 4) {
		return true;
	}else {
		return false;
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
