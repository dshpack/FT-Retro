//
// Created by olegi on 05.10.2019.
//

#ifndef PLAYGROUND_H
#define PLAYGROUND_H

 // win
#include <ncurses.h>
#include <stdexcept>
#include <string>
#include "pairMy.h"

class WinFrame {
public:

	WinFrame();
	WinFrame( WinFrame const &src);
	~WinFrame();

	WinFrame &operator=(WinFrame const &rhs);

	pairMy getWindowSize() const;
	int getY() const;
	void		menu_decoration();
	void		draw_menu();
	void		menu_maker();
	int			getMarked();

private:
	int		x;
	int		y;
	int				x_pos_;
	int				y_pos_;
	int				key_pressed_;
	int				marked_;
	WINDOW			*menuwin_;
	void			init_win();
};

#endif //RUSH00_PLAYGROUND_H
