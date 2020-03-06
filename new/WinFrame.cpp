//
// Created by olegi on 05.10.2019.
//

#include <curses.h>
#include "WinFrame.h"

WinFrame::WinFrame() {
	init_win();
}

WinFrame::WinFrame(WinFrame const &src) {
	*this = src;
}

WinFrame::~WinFrame() {

}

WinFrame & WinFrame::operator=(WinFrame const &rhs) {
	if(this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return (*this);
}

void WinFrame::init_win() {

	initscr();
	noecho();
	refresh();
	raw();
	if (!has_colors()) {
		throw std::runtime_error("Window initialisation fail");
	}
	start_color();
	init_pair(1,COLOR_YELLOW,COLOR_WHITE);
	init_pair(2,COLOR_GREEN,COLOR_WHITE);
	init_pair(3,COLOR_CYAN,COLOR_CYAN);
	curs_set(0);
	keypad(stdscr, true);
	x = getmaxx(stdscr);
	y = getmaxy(stdscr);

	addstr("Pres any key to start");		// PLACE HERE START MENY
	char str[100];
	getstr(str);
}

pairMy WinFrame::getWindowSize() const {
	return pairMy(x,y);
}

int WinFrame::getY() const {
	return y;
}

//////////////////////////////////////////////////////////////////////

int const&	WinFrame::getXPos()
{ return x_pos_; }

int const&	WinFrame::getYPos()
{ return y_pos_; }

int const&	WinFrame::getKeyPressed()
{ return key_pressed_; }

int const&	WinFrame::getMarked()
{ return marked_; }

WINDOW const&	WinFrame::getWindow()
{ return *menuwin_; }

void		WinFrame::setXPos(int x_pos)
{
	this->x_pos_ = x_pos;
}

void		WinFrame::setYPos(int y_pos)
{
	this->y_pos_ = y_pos;
}

void		WinFrame::setKeyPressed(int key_pressed)
{
	this->key_pressed_ = key_pressed;
}

void		WinFrame::setMarked(int marked)
{
	this->marked_ = marked;
}

void		WinFrame::setWindow(WINDOW &menuwin)
{
	this->menuwin_ = &menuwin;
}

void		WinFrame::menu_decoration() {
	char name[] = {"- - - The game 2048 - - -"};
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, y_pos_, x_pos_);
	attron(COLOR_PAIR(4));
	mvprintw(13, 5, "Make your choise!!!");
	attroff(COLOR_PAIR(4));
	move(30, (x_pos_ - 12));
	attron(COLOR_PAIR(1));
	printw(name);
	attroff(COLOR_PAIR(1));
	refresh();
	menuwin_ = newwin(4, x_pos_ - 12, 15, 6);
	box(menuwin_, 0, 0);
	refresh();
	wrefresh(menuwin_);
	keypad(menuwin_, TRUE);
}

void		WinFrame::draw_menu() {
	char option1[] = {"Start the GAME"};
	char option2[] = {"EXIT"};
	while(1) {
		for(int i = 0; i < 2; i++) {
			if(i == marked_)
				wattron(menuwin_, A_REVERSE);
			mvwprintw(menuwin_, i+1,
					  (x_pos_ - 25) / 2, (i > 1 ? option2 : option1));
			if (i == marked_)
				wattroff(menuwin_, A_REVERSE);
		}
		key_pressed_ = wgetch(menuwin_);
		if(key_pressed_ == (int)'\n') {
			break;
		}
		else if(key_pressed_ == KEY_UP) {
			marked_ = --marked_ < 0 ? 0 : marked_;
		}
		else if(key_pressed_ == KEY_DOWN) {
			marked_ = ++marked_ > 1 ? 1 : marked_;
		}
	}
}

void		WinFrame::menu_maker()
{
	menu_decoration();
	marked_ = 0;
	draw_menu();
	if (marked_ == 1) {
		endwin();
		exit(0);
	}
}