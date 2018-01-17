#include "player.h"

// set turn for this player
void Player::setTurn(const  bool t) {
	turn = t;
}
// get if this player's turn
const bool Player::getTurn() const {
	return turn;
}

// return piece for this player
char Player::getPiece() {
	return piece;
}

// set if this player is a computer
void Player::setIsComputer(bool val) {
	isComputer = true;
}

// return if this player is a computer
const bool Player::getIsComputer() const {
	return isComputer;
}
