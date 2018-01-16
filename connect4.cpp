#include "connect4.h"

Connect4::Connect4() : b(),p1(),p2(),init(false), numMoves(0) , EVA(0), playout(0){
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
			 numMoves++;
		 }else {
			 // Playing against computer
			 // It is Computer's Turn
			 int best = 9999999;
			 for(int k = 1; k <= 7 ;k++) {
				 if(b.validMove(k)) {
					 b.setCol(k, piece);
					 if(winner(piece)) {
					     numMoves++;
					     b.setCol(k, '.');
						 move = k;
						 break;
					 }
					 EVA = 0;
					 playout = 0;
					 float temp = -(100*getColumn(piece, 1, false));
					 if(playout) {
						 temp -= ((100*EVA)/playout);
					 }
					 if(best > temp) {
						 best = temp;
						 move = k;
					 }
					 b.setCol(k, '.');
				 }
				 
			 }
			 numMoves++;
		 }

		 if(b.validMove(move) && b.setCol(move, piece)&& !winner(piece)) {
			 if(turn == 1) {
				 turn = 2;
			 }else {
				 turn = 1;
			 }
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
	    if((x + i*k >= 6) || (x + i*k < 0) || (y + j*k>=7) || (y + j*k < 0)) {
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

int Connect4::getColumn(char p, int depth, bool isMax) {
	int chance = 0;
	char p2;
	if(p == 'X') {
		p2 = 'O';
	}else {
		p2 = 'X';
	}

	for(int i = 1; i <=7; i++) {
		if(b.validMove(i)) {
			b.setCol(i, p2);
			if(winner(p2)) {
				if(isMax) {
					EVA++;
				}else {
					EVA--;
				}
				b.setCol(i, '.');
				return -1;
			}
			b.setCol(i, '.');
		}
	}

	if(depth <= 6){
	    for(int i = 1; i <=7; i++) {
			int temp = 0;
		    if(b.validMove(i)) {
		        b.setCol(i, p2);
				if(winner(p2)) {
					playout++;
					if(isMax) {
						EVA++;
					}else {
						EVA--;
					}
					b.setCol(i, '.');
					return -1;
				}
				temp = getColumn(p2,depth + 1, !isMax);
				if(i == 1) {
					chance = temp;
				}
				if(chance < temp) 
					chance = temp;
				b.setCol(i, '.');

			}
		}
	}
	return -chance;
}
