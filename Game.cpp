//
// Created by olegi on 06.10.2019.
//

#include <cstring>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include "Game.h"

Game::Game() : numPlayers(0), numEnemyes(0){
	BadGuys::setSizeWin(win.getWindowSize());

}

Game::~Game() {

}

int		Game::getMarked()
{
	return this->win.getMarked();
}


void Game::generalLoop() {
	SpaceOnBack	backGround(win.getWindowSize().getFirst(),win.getWindowSize()
	.getSecond());
	clock_t t, gametime;
	t = clock();
	int 	spawn = 10;
	gametime = t;
	srand(time(0));
	try {
		while (true) {
			if ((float)(clock() - t)/CLOCKS_PER_SEC > .06) {
				if (moveAll() || numEnemyes == 900)
					break;
				if ((float) (clock() - t) / CLOCKS_PER_SEC > .01 &&
					spawn-- > 0 && spawn < 3) {
					randomEnemy();
				}
				if (spawn == 0)
					spawn = 20;
				t = clock();
			}
			nodelay(stdscr, TRUE);
			keyPress(getch());
			werase(stdscr);
			backGround.outputSpace();
			drawObj();       //drawing
			mvaddstr(1, 2, "SCORE");
			printw( " Player 1 : ");
			printw(std::to_string(humans[0]->getScore_()).c_str());
			if (numPlayers > 1)
			{
				printw( "\t\t Player 2 : ");
				printw(std::to_string(humans[1]->getScore_()).c_str());
			}
			printw("\tTIME: ");
			printw(std::to_string((clock() - gametime)/CLOCKS_PER_SEC).c_str());
			refresh();
		}
	}
	catch (...)
	{
		;
	}
	endwin();
}

bool Game::addPlayer() {
	if (numPlayers < MAX_PLAYERS)
		humans[numPlayers++] = new Players(win.getWindowSize());
	return false;
}

Game::Game(Game const &src) {
	*this = src;
}

Game &Game::operator=(Game const &rhs) {
	if (this != &rhs)
	{

	}
	return (*this);
}

bool Game::keyPress(int i) {
		switch (i)
		{
			case KEY_UP:
			{
				if (humans[0]->getPos_().getSecond() > 0)
					humans[0]->changePos(pairMy(0,-1));
				break;
			}
			case KEY_DOWN:
			{
				if (humans[0]->getPos_().getSecond() + 1 < win.getWindowSize()
				.getSecond())
					humans[0]->changePos(pairMy(0,1));
				break ;
			}
			case KEY_RIGHT:
			{
				if (humans[0]->getPos_().getFirst() + 2 < win.getWindowSize()
						.getFirst())
					humans[0]->changePos(pairMy(2,0));
				break ;
			}
			case KEY_LEFT:
			{
				if (humans[0]->getPos_().getFirst() > 1)
					humans[0]->changePos(pairMy(-2,0));
				break ;
			}
			case 'w':
			{
				if (numPlayers> 1 && humans[1]->getPos_().getSecond() > 0)
					humans[1]->changePos(pairMy(0,-1));
				break;
			}
			case 's':
			{
				if (numPlayers> 1 && humans[1]->getPos_().getSecond() + 1 < win
				.getWindowSize()
						.getSecond())
					humans[1]->changePos(pairMy(0,1));
				break ;
			}
			case 'd':
			{
				if (numPlayers> 1 && humans[1]->getPos_().getFirst() + 2 <
					win.getWindowSize()
						.getFirst())
					humans[1]->changePos(pairMy(2,0));
				break ;
			}
			case 'a':
			{
				if (numPlayers> 1 && humans[1]->getPos_().getFirst() > 1)
					humans[1]->changePos(pairMy(-2,0));
				break ;
			}
			case KEY_EXIT:
				break ;
			case 10 :
			{
				humans[0]->oneShot();
				break ;
			}
			case ' ':
			{
				if (numPlayers> 1)
					humans[1]->oneShot();
				break ;
			}
		}
		return 0;
}

void Game::drawObj() {

	for (int i = 0; i < numPlayers ; i++) {
		humans[i]->drawAllBull();
	}
	attroff(COLOR_PAIR(2));
	for (int j = 0; j < numEnemyes; j++) {
		alians[j]->drawObj();
	}
}

bool Game::moveAll() {
	for (int j = 0; j < numEnemyes; j++) {
		if (alians[j]->isActive())
			alians[j]->moveObj(humans, numPlayers);
	}
	for (int i = 0; i <numPlayers ; i++) {
		humans[i]->moveBullets(alians, numEnemyes);
		if (!humans[i]->isActive())
			return (1);
	}
	return (0);
}

void Game::randomEnemy() {
	if (numEnemyes < 1000)
	{
		if (numEnemyes <= 20 )
			alians[numEnemyes++] = new BadGuys(0);
		else if(numEnemyes <= 100 && numEnemyes > 10)
			alians[numEnemyes++] = new BadGuys(1);
		else if (numEnemyes <= 100&& numEnemyes > 20)
			alians[numEnemyes++] = new BadGuys(2);
	}
}
