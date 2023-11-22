#include "Cell/Cell.h"

//void Cell::add_selection(Obstacle& obst)
//{
//	content_.push_back(&obst);
//}

void Cell::add_selection(Base& obst)
{
	content_.push_back(&obst);
}

void Cell::delete_selection(Base& obst)
{
	for (auto it = content_.begin(); it != content_.end(); it++)
	{
		if (*it == &obst)
		{
			content_.erase(it, content_.end());
			break;
		}
	}
}