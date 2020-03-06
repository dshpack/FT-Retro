//
// Created by olegi on 05.10.2019.
//

#ifndef NEWRUSH_GAME_H
#define NEWRUSH_GAME_H

#include "AObject.h"
#include "WinFrame.h"
#include "Players.h"
#include "SpaceOnBack.h"
#include <ncurses.h>
#include <curses.h>
#define MAX_PLAYERS 2

class	Game
{
public:
	Game();
	~Game();
	void	generalLoop();
	bool	addPlayer();
	int		getMarked();
private:
	Game(Game const &src);
	Game &operator=(Game const &rhs);
	WinFrame	win;
	Players		*humans[2];
	BadGuys		*alians[1000];
	int8_t 		numPlayers;
	int8_t 		numEnemyes;
	bool		keyPress(int i);

	void drawObj();
	bool moveAll();
	void randomEnemy();
};




#endif //NEWRUSH_GAME_H
