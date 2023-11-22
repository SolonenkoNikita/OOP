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
        auto r = dynamic_cast<Obstacle*>(content);
        if (r->is_hard())
        {
            if (auto reaction = dynamic_cast<DamageCaused*>(content))
            {
                reaction->get_damage(1);
            }
        }
    }
}