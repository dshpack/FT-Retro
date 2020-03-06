//
// Created by olegi on 06.10.2019.
//

#include <curses.h>
#include "Bullets.h"


void Bullets::changePos(pairMy coord) {
	pos_ = pairMy((pos_.getFirst() + coord.getFirst()), (pos_.getSecond() + coord.getSecond()));
}

void Bullets::collision() {
	deactivate();
}

const pairMy &Bullets::getPos_() const {
	return pos_;
}

bool Bullets::getFriendly() const {
	return my_;
}
void Bullets::moveObj() {
	changePos(this->direction_);
}

Bullets::Bullets(bool friendly, pairMy position, pairMy dir) : my_(friendly),
alive(true){
	pos_ = position;
	direction_ = dir;
	active = true;
}

void Bullets::drawBull() {
	if (alive)
	{
		mvaddstr(pos_.getSecond(), pos_.getFirst(), "-");
	}
}

void Bullets::deactivate() {
	active = false;
	pos_ = pairMy(-1,-1);
}

bool Bullets::isActive() const {
	return active;
}

Bullets::~Bullets() {

}
