#include "Necromancy/Necromancy.h"

#include <iostream>

void Necromancy::check()
{
    level_ += (count_ % 10 != 0) ? 0 : 1;
}

void Necromancy::add_new_unhead(std::shared_ptr<Unhead> un)
{
    for (auto& content : table_)
    {
        if (typeid(*content).name() == typeid(*un).name())
        {
            return;
        }
    }
    table_.insert(un);
}

void Necromancy::add_known_unheads()
{
    Creature cr;
    if (level_ == 1)
    {
        add_new_unhead(std::make_shared<Skeleton>(cr));
    }
    else if (level_ == 2)
    {
        add_new_unhead(std::make_shared<Zombie>(cr));
    }
    else if (level_ == 3)
    {
        add_new_unhead(std::make_shared<Ghost>(cr));
    }
}

void Necromancy::apply(Characteristics& caster_characteristic, Cell& cell)
{
    check();
    add_known_unheads();
    count_++;
    int number, i = 0;
    for (auto& content : cell.get_content())
    {
        if (auto alive = dynamic_cast<Alive*>(content))
        {
            if (alive->get_creature()->get_characteristic()->get_meaning(Atrributes_Names::current_health_) == 0ull)
            {
                std::cout << "This is your table with unhead:\n";
                for (auto& it : table_)
                {
                    std::cout << "This is your type by unhead : " << i + 1 << ' ' << typeid(*it).name() << '\n';
                    i++;
                }
                std::cout << "Input number:\n";
                number = getNum<int>(1, table_.size());
                Skeleton skeleton(*alive->get_creature());
                Zombie zombie(*alive->get_creature());
                Ghost ghost(*alive->get_creature());
                size_t mana = caster_characteristic.get_meaning(Atrributes_Names::current_mana_);
                int result = static_cast<int>(mana - number * 10 / level_);
                if (result < 0)
                {
                    return;
                }
                caster_characteristic.set_characteristic(Atrributes_Names::current_mana_, result);
                switch (number)
                {
                case 1:
                    cell.add_selection(skeleton);
                    return;
                case 2:
                    cell.add_selection(zombie);
                    return;
                case 3:
                    cell.add_selection(ghost);
                    return;
                }
            }
        }
    }
}