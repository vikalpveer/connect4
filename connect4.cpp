#include "connect4.h"

Connect4::Connect4(int r, int c) : b(r,c) {
	std::cout <<"Welcome " << "\n";

	char turn;

	while(1) {
	    std::cout <<"Do you want to take the fist turn Y/N ?" << "\n";
		std::cin >> turn;
		if(turn == 'Y' || turn == 'N') {
			break;
		}else {
			std::cout << "Invalid Input \n";
		}
	}

}

