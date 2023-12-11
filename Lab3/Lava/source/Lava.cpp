#include "Lava/Lava.h"
#include <iostream>

bool Lava::is_hard() const
{
	return false;
}

void Lava::reaction(Cell& cell)
{
    for (auto& content : cell.get_content())
    {
        if (auto reaction = std::dynamic_pointer_cast<DamageCaused>(content))
        {
            reaction->get_damage(damage_);
        }
    }
}