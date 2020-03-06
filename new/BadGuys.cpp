//
// Created by olegi on 05.10.2019.
//


#include <cstdlib>
#include <curses.h>
#include "BadGuys.h"
#include "Players.h"

pairMy BadGuys::sizeWin = pairMy(0,0);

size_t	BadGuys::counter = 0;
BadGuys::BadGuys(int type) : type_(type){
	pos_ = pairMy(sizeWin.getFirst() - 3 , rand()% sizeWin.getSecond());
	direction_ = type_ ? pairMy(-type_, -1) : pairMy(-1, 0);
	active = true;
	nBull_ = 0;
	if (type_ == 1)
		sign = "WM";
	else if (type_ == 0)
		sign = "HO";
	else if (type_ == 2)
		sign = "<K";
}

void BadGuys::moveObj(Players *pPlayers[2], int8_t i) {
	changePos(direction_);

	if (type_ == 2 && rand()%4)
		oneShot();
	for (int j = 0; j < i; ++j) {
		if (pPlayers[j]->getPos_() == getPos_())
		{
			pPlayers[j]->deactivate();
			deactivate();
		}
	}
	for (int k = 0; k < nBull_; ++k) {
		for (int j = 0; j < i; ++j) {
			if (pPlayers[j]->getPos_() == shot[j]->getPos_())
			{
				pPlayers[j]->deactivate();
				shot[j]->deactivate();
			}
		}
	}
}

void BadGuys::changePos(pairMy coord) {

	if ((counter++%5) && type_)
		return ;
	pos_ = pairMy((pos_.getFirst() + coord.getFirst()), (pos_.getSecond() +
	coord.getSecond()));
	if (pos_.getSecond() == 0 || pos_.getSecond() == sizeWin.getSecond())
		direction_.setSecond(-direction_.getSecond());
}

void BadGuys::collision() {
	;
}

BadGuys::BadGuys(BadGuys const &src){
	*this = src;
}

BadGuys &BadGuys::operator=(BadGuys const &rhs) {
	if (this != &rhs)
	{
	}
	return (*this);
}

BadGuys::~BadGuys() {
}

const pairMy &BadGuys::getPos_() const {
	return pos_;
}

void BadGuys::setSizeWin(const pairMy &sizeWin) {
	BadGuys::sizeWin = sizeWin;
}

void BadGuys::drawObj() {
	if (active) {
		mvaddstr(pos_.getSecond(), pos_.getFirst(),
				 sign.c_str());
	}
		for (int i = 0; i < nBull_; ++i) {
			shot[i]->drawBull();
		}
}

void BadGuys::deactivate() {
	active = false;
	pos_ = pairMy(-1,-1);
}

bool BadGuys::isActive() const {
	return active;
}

void BadGuys::oneShot() {
	pairMy	bulletPos(pos_.getFirst() - 1, pos_.getSecond());
	if (nBull_ < 1000)
//		shot[nBull_++] = new Bullets(false, bulletPos, pairMy(-2,0));
}

int BadGuys::getType_() const {
	return type_;
}

