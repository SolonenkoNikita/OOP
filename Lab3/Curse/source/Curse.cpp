#include "Curse/Curse.h"

#include <iostream>

void Curse::check()
{
    level_ += (count_ % 10 != 0) ? 0 : 1;
}

void Curse::apply(Characteristics& caster_characteristic, Cell& cell)
{
    check();
    count_++;
    for (auto& content : cell.get_content())
    {
        if (auto alive = dynamic_cast<DamageCaused*>(content))
        {
            size_t damage = level_ * caster_characteristic.get_meaning(Atrributes_Names::damage_);
            alive->get_damage(damage);
        }
    }
}