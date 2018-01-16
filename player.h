#include <iostream>
// This is a player class 
class Player {

	const char piece;
	bool turn;
	const bool isComputer;
	public:
	    // Constructor. 
	    Player():piece('.'),turn(false),isComputer(false){}

		// sets peice 'X' or 'O' for a player.
		void setPiece(const char p);

		// returns piece for a player
		const char getPiece() const;

		// Sets if the player has his turn
		void setTurn(const bool turn);

		// returns if this player has his turn
		const bool getTurn() const;

		// sets to true if this player is a computer.
		void setIsComputer(const bool val);

		// Returns true if this player is a computer.
		const bool getIsComputer();

};

