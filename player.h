#include <iostream>

class Player {

	char piece;
	bool turn;
	public:
	    Player():piece('.'),turn(false){}
		void setPiece(const char p);
		char getPiece() const;
		void setTurn(const bool turn);
		bool getTurn() const;
	    //char move(); 

};

