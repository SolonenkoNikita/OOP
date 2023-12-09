#include "UnResponsive/Unresponsive.h"

Wall::Wall()
{
	set_id(4);
}

bool Wall::is_hard() const
{
	return true;
}

bool Floor::is_hard() const
{
	return false;
}

Floor::Floor()
{
	set_id(0);
}