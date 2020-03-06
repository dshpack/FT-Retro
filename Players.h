//
// Created by olegi on 06.10.2019.
//

#ifndef NEWRUSH_PLAYERS_H
#define NEWRUSH_PLAYERS_H


#include "AObject.h"
#include "Bullets.h"

class Players : public AObject {

public:
	Players(pairMy winSize);
	~Players();
	Players(Players const &src);

	virtual void moveObj();
	virtual void changePos(pairMy coord);
	virtual void collision();
	virtual const pairMy &getPos_() const;
	Players &operator=(Players const &rhs);
	void	oneShot();
	void	drawAllBull();
	void moveBullets(BadGuys **pGuys, int16_t num);
	virtual void deactivate();

	virtual bool isActive() const;

	int getScore_() const;

private:
	Players();
	int 		score_;
	int 		nBull;
	Bullets		*shot[1000];
};


#endif //NEWRUSH_PLAYERS_H
