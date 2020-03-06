//
// Created by olegi on 05.10.2019.
//

#ifndef RUSH00_BADGUYS_H
#define RUSH00_BADGUYS_H


#include <iosfwd>
#include <string>
#include "AObject.h"
#include "Players.h"

class BadGuys : public AObject
{

public:
	BadGuys(int type);
	virtual const pairMy &getPos_() const;
	void moveObj(Players *pPlayers[2], int8_t i);
	static void setSizeWin(const pairMy &sizeWin);
	void drawObj();
	virtual void deactivate();
	virtual bool isActive() const;

	void	oneShot();

	int getType_() const;

private:
	BadGuys(BadGuys const &src);

	BadGuys &operator=(BadGuys const &rhs);
	~BadGuys();


	void changePos(pairMy coord);
	void collision();

	static pairMy 	sizeWin;
	static size_t	counter;
	int 		type_;
	std::string sign;
	Bullets		*shot[1000];
	int			nBull_;
};


#endif //RUSH00_BADGUYS_H
