//
// Created by olegi on 06.10.2019.
//

#ifndef NEWRUSH_BULLETS_H
#define NEWRUSH_BULLETS_H


#include "BadGuys.h"

class Bullets : public AObject{
public:
	virtual ~Bullets();
	Bullets(bool friendly,pairMy position, pairMy dir);
	void moveObj();
	void changePos(pairMy coord);
	void collision();
	const pairMy &getPos_() const;
	bool getFriendly() const;
	void drawBull();

	virtual bool isActive() const;
	virtual void deactivate();

private:
	bool const my_;
	bool alive;
};


#endif //NEWRUSH_BULLETS_H
