#ifndef _Necromancy_H_
#define _Necromancy_H_

#include <Ability/Ability.h>
#include <Alive/Alive.h>
#include <Unhead/Unhead.h>

#include <memory>

template<typename Unhead>
class Necromancy : public Ability
{
private:
    size_t mana_;
public:

    Necromancy(size_t mana) : mana_(mana) {};
    
    bool is_long() const override
    {
        return false;
    }

    void apply(Characteristics& caster_characteristic, Cell& cell) override
    {
        size_t cur = caster_characteristic.get_meaning(Atrributes_Names::current_mana_);
        auto x = static_cast<long long>(cur - mana_);
        if (x < 0)
            return;
        for (auto& content : cell.get_content())
        {
            if (auto alive = std::dynamic_pointer_cast<Alive>(content))
            {
                if (alive->is_died())
                {
                    cell.delete_selection(alive);
                    size_t max = alive->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
                    alive->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, max);
                    auto b = std::make_shared<Unhead>(std::move(alive->get_creature()));
                    cell.add_selection(std::move(b));
                    caster_characteristic.set_characteristic(Atrributes_Names::current_mana_, x);
                    break;
                }
            }
        }
    }
};

#endif