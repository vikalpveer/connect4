#include "connect4.h"

//static def.

const int Connect4::INF;
const int Connect4::WINSEQ;
//constructor 
Connect4::Connect4() : 
    b(),
	p1(Board::X),
	p2(Board::O),
	init(false), 
	numMoves(0) , 
	SCORE(0), 
	COUNT(0){}

// function initialize player/piece/first turn option etc. via command line menu
void Connect4::initialize() {

	std::cout <<"            WELCOME            " << "\n";
	std::cout <<".............................. " << "\n";

	char resp;
	bool isComputer = false;

	// Confirm if you are playing against Computer
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

	// set who will play first
	while(1) {
	    std::cout <<"Do you want to take the fist turn y/n ?" << "\n";
		std::cin >> turn;
		if(turn == 'y' || turn == 'n') {
			if(turn == 'y') {
				if(isComputer) {
					p2.setIsComputer(true);
				}
			}else {
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

void Connect4::play() {

	 // Initialize the game logic before starting the play
	 if(!init) {
		 initialize();
	 }

	 // find if one of the player is a computer.

	 bool p1Computer = p1.getIsComputer();
	 bool p2Computer = p2.getIsComputer();

	 // it is always player 1's turn
	 int turn = 1;

	 // Get into a loop until game is a draw of there is a winner

	 while(1) {

		 char piece;
		 int move;

		 if(turn == 1) {
			 piece = p1.getPiece();
		 }else {
			 piece = p2.getPiece();
		 }

		 // if player 1 turn and he is not a computer or if turn of player 2 and he is not a computer
		 // Get column from command line prompt

		 if((turn == 1 && !p1Computer) || (turn == 2 && !p2Computer)) {

		     std::cout <<"Player "<< turn <<" : Your Turn \n";
		     std::cout <<"Select the column you would like to play : \n";

		     std::cin.clear();
		     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		     std::cin >> move;

			 //The input is invalid or column is full.
	         if(!b.validMove(move)) {
		         std::cout << "ERR: You cannot choose this column.\n";
		         std::cout << "-----------------------------------\n";
				 continue;
	         }

			 // Valid move. Increment count
			 numMoves++;
		 }else {
			 // Playing against computer
			 // It is Computer's Turn

			 // Some high number to init best Move.
			 int best = INF;

			 // Iterate through all the column one by one.
			 // Check if a move can be made and if move is possible, break from this
			 // loop as this is the best move.

			 for(int k = 1; k <= Board::nCol ;k++) {
				 if(b.validMove(k)) {
					 b.setCol(k, piece);
					 if(winner(piece)) {
					     // it's a winning move.
					     numMoves++;
						 // we reset board as we are only finding best move (col).
					     b.setCol(k, '.');
						 // best move .. break
						 move = k;
						 break;
					 }
					 // Computer cannot win in this column, lets get the best score for this column

					 // score.. if computer win, increment else decrement
					 SCORE = 0;

					 // Overall Win count
					 COUNT = 0;

					 // simulate moves .. using minimax algo
					 float temp = -(100*getBestColumn(piece, 1, false));

					 if(COUNT) {
						 // if a winner was found, take percentage of computer's score.
						 temp -= ((100*SCORE)/COUNT);
					 }

					 // if computer had a higher score in this column, save it.
					 if(best > temp) {
						 best = temp;
						 move = k;
					 }
					 // reset the board here
					 b.setCol(k, '.');
				 }
				 
			 }
			 // best move by computer has been found. increment move.
			 numMoves++;
		 }

		 // use the move computed above.. and determine if there is a winner
		 if(b.validMove(move) && b.setCol(move, piece)&& !winner(piece)) {
			 // There is no winner. Set turn for other player.
			 if(turn == 1) {
				 turn = 2;
			 }else {
				 turn = 1;
			 }
		 }

		 // redraw board after this move.
		 b.draw();
		 std::cout << "Number of Moves so far :"<< numMoves <<"\n";
		 if(winner(piece)) {

			 // There is a winner. Break.
			 if(turn ==1) {
				 std::cout << "Player 1 is a winner \n";
			 }else {
				 std::cout << "Player 2 is a winner \n";
			 }
			 break;
		 }

		 // Compute if a game is  a draw
		 if(numMoves == Board::nRow * Board::nCol) {
			  std::cout << "Game is a draw \n";
			  break;
		 }
	 }
}

// check if the board has a winner
bool Connect4::winner(const char p) {

	bool isWinner = false;

	for(int i = 0; i < Board::nRow && !isWinner; i++) {
		for(int j = 0; j < Board::nCol; j++) {
			isWinner = checkCondition(i, j, 0, 1, p) || // Horizontal
			           checkCondition(i, j, 1, 0, p) || // Vertical
			           checkCondition(i, j, 1, 1, p) || // Diagonal
			           checkCondition(i, j, 1,-1, p);   // Opposite Diag
			if(isWinner) {
				break;
			}
		}
	}
	return isWinner;
}


// find the winning combination
bool Connect4::checkCondition(int x, int y, int i, int j, char p) {

	int k;
	for(k = 0; k < WINSEQ; k++) {
	    if((x + i*k >= Board::nRow) || (x + i*k < 0) || (y + j*k>=Board::nCol) || (y + j*k < 0)) {
		    return false;
	    }

		if(b.getElem(x + i*k, y + j*k) == p) {
			continue;
		}else {
			break;
		}
	}

	if(k == WINSEQ) {
		return true;
	}else {
		return false;
	}
}

// Compute the best column
int Connect4::getBestColumn(char p, int depth, bool isMax) {
	int chance = 0;
	char p2;
	if(p == Board::X) {
		p2 = Board::O;
	}else {
		p2 = Board::X;
	}

	// Check if opposite player can win here.
	for(int i = 1; i <=Board::nCol; i++) {
		if(b.validMove(i)) {
			b.setCol(i, p2);
			if(winner(p2)) {
                // Yes ..
				if(isMax) {
					// If player is computer.. INC SCORE
					SCORE++;
				}else {
					// Human would win here .. DEC SCORE
					SCORE--;
				}
				// reset col
				b.setCol(i, '.');
				return -1;
			}
			// no winner.. reset column
			b.setCol(i, '.');
		}
	}

	// simulate move here taking turn .. human/computer.
	if(depth <= Board::nRow){
	    for(int i = 1; i <=Board::nCol; i++) {
			int temp = 0;
		    if(b.validMove(i)) {
		        b.setCol(i, p2);
				if(winner(p2)) {
					// Found a winner. Increment Count.
					COUNT++;
					if(isMax) {
						// if Winner is a computer .. increment score
						SCORE++;
					}else {
						// decrement score
						SCORE--;
					}
					// reset column
					b.setCol(i, '.');
					return -1;
				}
				// reverse the player and simulate moves for remaining columns
				temp = getBestColumn(p2,depth + 1, !isMax);
				if(i == 1) {
					chance = temp;
				}
				if(chance < temp)  {
					chance = temp;
				}
				b.setCol(i, '.');
			}
		}
	}
	return -chance;
}
