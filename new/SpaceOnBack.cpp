//
// Created by olegi on 06.10.2019.
//

#include <cstdlib>
#include <ctime>
#include "SpaceOnBack.h"
#include <cstdlib>
#include <ctime>

SpaceOnBack::SpaceOnBack() {}

SpaceOnBack::SpaceOnBack(SpaceOnBack const &src) {
	*this = src;
}

SpaceOnBack &SpaceOnBack::operator=(SpaceOnBack const &rhs) {
	if (this != &rhs) // add coping inside if
	{
		return *this;
	}
	return *this;
}

SpaceOnBack::~SpaceOnBack() {
	delete (_space);
}


int SpaceOnBack::counter = 0;

SpaceOnBack::SpaceOnBack(int x, int y) : _xSize(x), _ySize(y)  {

	_space = new char[_ySize * _xSize];

	for (int i = 0; i < _ySize * _xSize; i++)
	{
		if (!(rand() % 30))
			_space[i] = ((rand() % 3) ? '.' : '*');
		else
			_space[i] = ' ';
	}
}



void SpaceOnBack::outputSpace()
{
	static clock_t t = clock();
	if ((float)(clock() - t)/CLOCKS_PER_SEC > .1)
	{
		SpaceOnBack::counter++;
		t = clock();
	}
	mvaddstr(0, 0, &_space[counter % _xSize]);
}