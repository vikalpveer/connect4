#include "connect4.h"

Connect4::Connect4(int r, int c) : b(r,c),p1(),p2(),init(false), numMoves(0) {
}
void Connect4::play() {
	 if(!init) {
		 initialize();
	 }

	 bool p1Computer = p1.getIsComputer();
	 bool p2Computer = p2.getIsComputer();
	 int turn = 1;

	 while(1) {
		 char piece;
		 int move;

		 if(turn == 1) {
			 piece = 'X';
		 }else {
			 piece = 'O';
		 }

		 if((turn ==1 && !p1Computer) || (turn == 2 && !p2Computer)) {

		     std::cout <<"Player "<< turn <<" : Your Turn \n";
		     std::cout <<"Select the column you would like to play : \n";

		     std::cin.clear();
		     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		     std::cin >> move;

		     if(move < 1 || move > 7) {
			     std::cout <<"ERR: Invalid Input. Try Again ! \n";
			     continue;
		     }

	         if(!b.validMove(move)) {
		         std::cout << "ERR: You cannot choose this column \n";
		         std::cout << "-----------------------------------\n";
				 continue;
	         }
		 }else {
			 // Playing against computer
			 // It is Computer's Turn
			 getColumn(piece, move,1);
		 }

		 if(b.validMove(move) && b.setCol(move, piece)&& !winner(piece)) {
			 if(turn == 1) {
				 turn = 2;
			 }else {
				 turn = 1;
			 }
			 numMoves++;
		 }
		 b.draw();
		 std::cout << "Number of Moves so far :"<< numMoves <<"\n";
		 if(winner(piece)) {
			 if(turn ==1) {
				 std::cout << "Player 1 is a winner \n";
			 }else {
				 std::cout << "Player 2 is a winner \n";
			 }

			 break;
		 }

		 if(numMoves == 6*7) {
			  std::cout << "Game is a draw \n";
			  break;
		 }
	 }
}

bool Connect4::winner(const char p) {

	bool isWinner = false;

	for(int i = 0; i < 6 && !isWinner; i++) {
		for(int j = 0; j < 7; j++) {
			isWinner = checkCondition(i, j, 0, 1, p) ||
			           checkCondition(i, j, 1, 0, p) ||
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

	char resp;
	bool isComputer = false;
	while(1) {
	    std::cout <<"Do you want to play against Computer (y/n) ?" << "\n";
		std::cin >> resp;
		if(resp == 'y' || resp == 'n') {
			if(resp == 'y') {
				isComputer = true;
			}
			break;
		}else {
			std::cout << "Invalid Input \n";
		}
	}

	char turn;
	while(1) {
	    std::cout <<"Do you want to take the fist turn y/n ?" << "\n";
		std::cin >> turn;
		if(turn == 'y' || turn == 'n') {
			if(turn == 'y') {
			    p1.setPiece('X');
			    p2.setPiece('O');
				if(isComputer) {
					p2.setIsComputer(true);
				}
			}else {
			    p1.setPiece('O');
			    p2.setPiece('X');
				if(isComputer) {
					p1.setIsComputer(true);
				}
			}
			init = true;
			break;
		}else {
			std::cout << "Invalid Input \n";
		}
	}
}

int Connect4::getColumn(char p, int &col, int depth) {
	char p2;
	if(p == 'X') {
		p2 = 'O';
	}else {
		p2 = 'X';
	}

	/* The game is a draw */
	if(numMoves == 6*7) {
		return 0;
	}

	/*
	if(depth >=3) {
		return 0;
	} */

	if(winner(p)) {
		return (6*7 + 1  - numMoves) / 2;
	}

	int max  = -6*7;

	if(depth <= 6) {
	for(int i =1; i <= 7; i++) {
		if(b.validMove(i)) {
		    b.setCol(i, p);
			numMoves++;
			int score = -getColumn(p2, col, depth + 1);
		    b.setCol(i, '.');
			numMoves--;

			if(score > max) { 
				max = score;
				col = i;
			}
		}
	} 
	}
	return max; 
}
