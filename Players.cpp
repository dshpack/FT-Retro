//
// Created by olegi on 06.10.2019.
//

#include <curses.h>
#include "Players.h"
static int numberPl = 1;

Players::Players(pairMy winSize) : nBull(0){
	winSize_ = winSize;
	direction_ = pairMy(1, 0);
	pos_ = pairMy(10,winSize.getSecond()/3 + numberPl);
	active = true;
	score_ = 0;
	numberPl += 10;
}

Players::~Players() {

}

Players::Players(Players const &src) {
	*this = src;
}

Players &Players::operator=(Players const &rhs) {
	if (this != &rhs)
	{

	}
	return (*this);
}

void Players::moveObj() {

}

void Players::changePos(pairMy coord) {

	pos_ = pairMy((pos_.getFirst() + coord.getFirst()), (pos_.getSecond() + coord.getSecond()));
}

void Players::collision() {

}

const pairMy &Players::getPos_() const {
	return pos_;
}

Players::Players() {

}

void Players::oneShot() {
	pairMy	bulletPos(pos_.getFirst()+2, pos_.getSecond());
	if (nBull < 1000)
		shot[nBull++] = new Bullets(true, bulletPos, direction_);
}

void Players::drawAllBull() {
	mvaddstr(pos_.getSecond(), pos_.getFirst(),
			 "XD");
	for (int i = 0; i < nBull; i++) {
		shot[i]->drawBull();
	}
}

void Players::moveBullets(BadGuys *pGuys[1000], int16_t num) {
	for (int i = 0; i < nBull; ++i) {
		if (!shot[i]->isActive())
			continue;
		shot[i]->changePos(pairMy(1,0));
		for (int j = 0; j < num; ++j) {
			if (shot[i]->getPos_() == pGuys[j]->getPos_())
			{
				shot[i]->collision();
				pGuys[j]->deactivate();
				score_ += (pGuys[j]->getType_() + 1) * 100;
			}
		}
	}

}

void Players::deactivate(){
	active = false;
	pos_ = pairMy(-1,-1);
}

bool Players::isActive() const {
	return active;
}

int Players::getScore_() const {
	return score_;
}
