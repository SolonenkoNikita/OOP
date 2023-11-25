#include "Curse/Curse.h"

#include <iostream>

void Curse::check()
{
    level_ += (count_ % 10 != 0) ? 0 : 1;
}

void Curse::apply(Characteristics& caster_characteristic, Cell& cell)
{
    check();
    for (auto& content : cell.get_content())
    {
        if (auto alive = std::dynamic_pointer_cast<DamageCaused>(content))
        {
            size_t damage = level_ * caster_characteristic.get_meaning(Atrributes_Names::damage_);
            alive->get_damage(damage);
            count_++;
        }
    }
}