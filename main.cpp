#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <cstdlib>
#include "Game.h"
#include "AObject.h"
#include "Players.h"

#define MAX_PLAYERS 2

int		main()
{
	Game	newGame;
	try
	{
		if (newGame.getMarked() == 0)
			newGame.addPlayer();
		else
		{
			newGame.addPlayer();
			newGame.addPlayer();
		}

		clear();
		endwin();
		newGame.generalLoop();
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}