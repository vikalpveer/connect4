#include <iostream>

class Player {

	char piece;
	bool turn;
	bool isComputer;
	public:
	    Player():piece('.'),turn(false),isComputer(false){}
		void setPiece(const char p);
		char getPiece() const;
		void setTurn(const bool turn);
		bool getTurn() const;
		void setIsComputer(bool val);
		bool getIsComputer();

};

