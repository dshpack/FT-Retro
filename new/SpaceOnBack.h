//
// Created by olegi on 06.10.2019.
//

#ifndef NEWRUSH_SPACE_H
#define NEWRUSH_SPACE_H


#include <ncurses.h>

class SpaceOnBack {

public:

	SpaceOnBack(int x, int y);
	void outputSpace();

	~SpaceOnBack();

private:

	static int counter;
	int _xSize;
	int _ySize;
	char *_space;
	SpaceOnBack();

	SpaceOnBack(SpaceOnBack const &src);
	SpaceOnBack &operator=(SpaceOnBack const &rhs);

};



#endif //NEWRUSH_SPACE_H
