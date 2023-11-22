#include "Unhead/Unhead.h"

bool Unhead::is_hard() const
{
	return true;
}

Unhead::Unhead(Creature cr) : creature_(std::move(cr))
{
}

bool Unhead::is_died() const
{
	return false;
}