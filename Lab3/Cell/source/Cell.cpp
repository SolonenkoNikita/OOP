#include "Cell/Cell.h"

void Cell::add_selection(std::shared_ptr<Base> obst)
{
	content_.push_back(std::move(obst));
}

void Cell::delete_selection(std::shared_ptr<Base> obst)
{
	for (auto it = content_.begin(); it != content_.end(); it++)
	{
		if (*it == obst)
		{
			content_.erase(it, content_.end());
			break;
		}
	}
}