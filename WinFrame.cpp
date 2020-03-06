//
// Created by olegi on 05.10.2019.
//

#include <curses.h>
#include <cstdlib>
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

	//addstr("Pres any key to start");		// PLACE HERE START MENY
	menu_maker();
	char str[100];
	getstr(str);
}

pairMy WinFrame::getWindowSize() const {
	return pairMy(x,y);
}

int WinFrame::getY() const {
	return y;
}

int		WinFrame::getMarked()
{ return marked_; }

void		WinFrame::menu_decoration() {
	char name[] = {"- - - The game 2019 - - -"};
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, y_pos_, x_pos_);
	attron(COLOR_PAIR(4));
	mvprintw(13, 15, "Make your choise!!!");
	attroff(COLOR_PAIR(4));
	move(30, (x_pos_ - 118));
	attron(COLOR_PAIR(2));
	printw(name);
	attroff(COLOR_PAIR(1));
	refresh();
	menuwin_ = newwin(5, x_pos_ - 12, 15, 6);
	wborder(menuwin_, 0, 0, 0, 0, 10, 10, 10, 10);
	refresh();
	wrefresh(menuwin_);
	keypad(menuwin_, TRUE);
}

void		WinFrame::draw_menu() {
	char option1[] = {"Start the GAME with ONE player"};
	char option2[] = {"Start the GAME with TWO players"};
	char option3[] = {"EXIT"};
	while(1) {
		for(int i = 0; i < 3; i++) {
			if(i == marked_)
				wattron(menuwin_, A_REVERSE);

			switch (i)
			{
				case 0: mvwprintw(menuwin_, i+1, (x_pos_ - 38) / 2, option1); break;
				case 1: mvwprintw(menuwin_, i+1, (x_pos_ - 38) / 2, option2); break;
				case 2: mvwprintw(menuwin_, i+1, (x_pos_ - 38) / 2, option3); break;
				default:
					break ;
			}
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
			marked_ = ++marked_ > 2 ? 0 : marked_;
		}
	}
}

void		WinFrame::menu_maker()
{
	menu_decoration();
	marked_ = 0;
	draw_menu();
	if (marked_ == 2) {
		endwin();
		exit(0);
	}
}