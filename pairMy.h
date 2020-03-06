//
// Created by olegi on 05.10.2019.
//

#ifndef RUSH00_PAIRMY_H
#define RUSH00_PAIRMY_H


#include <stdint.h>

class pairMy
{
public:
	pairMy();
	pairMy(int f, int s);
	pairMy(pairMy const &src);
	~pairMy();

	pairMy  &operator=( const pairMy &rhs);
	bool operator==(pairMy const &rhs) const;
	bool operator!=(pairMy const &riht) const;
	int getFirst() const;
	int getSecond() const;

	void setFirst(int first);

	void setSecond(int second);

private:
	int first;
	int second;
};




#endif //RUSH00_PAIRMY_H
