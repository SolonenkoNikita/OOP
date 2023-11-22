#include "Desiccation/Desiccation.h"

#include <iostream>

void Desiccation::check()
{
	level_ += (count_ % 10 != 0) ? 0 : 1;
}

void Desiccation::apply(Characteristics& caster_characteristic, Cell& cell)
{
	check();
	count_++;
    for (auto& content : cell.get_content())
    {
        if (auto alive = dynamic_cast<Alive*>(content))
        {
            if (alive->get_creature()->get_characteristic()->get_meaning(Atrributes_Names::current_health_) == 0ull)
            {
                std::cout << "U need doing change, input 1 - health or 2 - mana\n";
                size_t attribute = 1ull;
                int number;
                std::cin >>  number;
                switch (number)
                {
                case 1:
                    attribute = level_ * alive->get_creature()->get_characteristic()->get_meaning(Atrributes_Names::max_health_);
                    caster_characteristic.set_characteristic(Atrributes_Names::current_health_,
                        std::min(caster_characteristic.get_meaning(Atrributes_Names::max_health_), attribute));
                    cell.delete_selection(*alive);
                    return;
                case 2:
                    attribute = level_ * alive->get_creature()->get_characteristic()->get_meaning(Atrributes_Names::max_health_);
                    caster_characteristic.set_characteristic(Atrributes_Names::current_mana_,
                        std::min(caster_characteristic.get_meaning(Atrributes_Names::max_mana_), attribute));
                    cell.delete_selection(*alive);
                    return;
                }
            }
        }
    }
}