//
// Created by Oleh IVANYTSKYI on 2019-10-05.
//

#ifndef RUSH00_IOBJECT_H
#define RUSH00_IOBJECT_H

#include <stdint.h>  //win header for 1nt_8
#include "pairMy.h"

class BadGuys;

class Bullets;
class 	Players;
class AObject
{

public:
	virtual void changePos(pairMy coord) = 0;
	virtual void collision() = 0;
	virtual const pairMy &getPos_() const = 0;

protected:
	pairMy 	pos_;			//position x & y on map
	pairMy 	direction_;		//direction x on map
	int8_t				speed_;		//speed
	int8_t 				maxHp_;		//
	int8_t 				hp_;		//health power
	int8_t				ep_;		//energy power
	pairMy				winSize_;
	bool				active;


public:
	virtual void deactivate() = 0;
	virtual bool isActive() const = 0;
};

#endif //RUSH00_IOBJECT_H
