//
// Created by olegi on 05.10.2019.
//

#include "pairMy.h"


bool pairMy::operator==(pairMy const &rhs) const {
	return ((first == rhs.first || first == rhs.first + 1) &&
	second == rhs.second);
}

bool pairMy::operator!=(pairMy const &riht) const {
	return !(*this==riht);
}

pairMy &pairMy::operator=(const pairMy &rhs) {
	if (this != &rhs)
	{
		first = rhs.first;
		second = rhs.second;
	}
	return (*this);
}

pairMy::pairMy()  : first(0), second(0) {
}

pairMy::pairMy(pairMy const &src) {
	*this = src;
}

pairMy::~pairMy() {

}

pairMy::pairMy(int f, int s) : first(f), second(s){

}

int pairMy::getFirst() const {
	return first;
}

int pairMy::getSecond() const {
	return second;
}

void pairMy::setFirst(int first) {
	pairMy::first = first;
}

void pairMy::setSecond(int second) {
	pairMy::second = second;
}

