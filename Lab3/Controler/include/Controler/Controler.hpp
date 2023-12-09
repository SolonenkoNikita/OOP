#ifndef _Controler_HPP_
#define _Controler_HPP_

class Room;

class Player;

class Direction;

struct Coordinate;

class Controler
{
public:

	virtual void move(Direction&) = 0;

	virtual void using_ability(size_t, Coordinate&) = 0;

	virtual ~Controler() = default;
};

#endif