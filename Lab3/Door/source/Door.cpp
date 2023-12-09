#include "Door/Door.h"

Door& Door::close()
{
	set_id(6);
	closed_ = true;
	return *this;
}

bool Door::is_hard() const
{
	return !is_open();
}

bool Door::is_open() const
{
	return !closed_;
}

Door& Door::open()
{
	set_id(7);
	closed_ = false;
	return *this;
}

bool Door::is_died() const
{
	return is_open();
}

void Door::die(Cell& cell)
{
	open();
}

void Door::get_damage(size_t damage)
{
	open();
}

void Door::revival(Cell& cell)
{
	close();
}

void Door::reaction(Cell& cell)
{
	open();
}

void Door::kill(Cell& cell)
{
	open();
}

