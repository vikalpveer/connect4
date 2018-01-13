#include "player.h"

void Player::setPiece(const char p) {
	piece = p;
}
char Player::getPiece() const {
	return piece;
}

void Player::setTurn(const  bool t) {
	turn = t;
}
bool Player::getTurn() const {
	return turn;
}
