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
		newGame.addPlayer();
//		newGame.addPlayer();
		newGame.generalLoop();
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}