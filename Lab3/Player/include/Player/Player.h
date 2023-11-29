#ifndef _Player_H_
#define _Player_H_

#include <Base/Base.h>

class Cell;

class Player : virtual public Base
{
public:
	virtual void using_ability(Cell&, size_t) = 0;

	virtual ~Player() = default;
};

#endif