#include <iostream>
// This is a player class 
class Player {
	bool turn;
	bool isComputer;
	const char piece;
	public:
	    // Constructor. 
	    Player(char p):piece(p),turn(false),isComputer(false){}

		//Destructor
		~Player() {}

		// Sets if the player has his turn
		void setTurn(const bool turn);

		// returns if this player has his turn
		const bool getTurn() const;

		// sets to true if this player is a computer.
		void setIsComputer(const bool val);

		// Returns true if this player is a computer.
		const bool getIsComputer() const;

		// Set piece for this player
		void setPiece(const char p) ;

		// returns piece assigned to this player
	    char getPiece() ;
};

