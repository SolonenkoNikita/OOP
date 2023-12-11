#ifndef _Morphism_H_
#define _Morphism_H_

#include <Ability/Ability.h>
#include <Unhead/Unhead.h>

#include <memory>

template<typename T>
class Morphism : public Ability
{
private:
    size_t mana_;
public:

    Morphism(size_t mana) : mana_(mana) {};

    bool is_long() const override
    {
        return false;
    }

    void apply(Characteristics& caster_characteristic, Cell& cell) override
    {
        size_t cur = caster_characteristic.get_meaning(Atrributes_Names::current_mana_);
        auto x = static_cast<long long>(cur - mana_);
        if (x < 0)
        {
            return;
        }
        for (auto& content : cell.get_content())
        {
            if (auto alive = std::dynamic_pointer_cast<Unhead>(content))
            {
                cell.delete_selection(alive);
                auto b = std::make_shared<T>(std::move(alive->get_creature()));
                cell.add_selection(b);
                caster_characteristic.set_characteristic(Atrributes_Names::current_mana_, x);
                break;
            }
        }
    }
};

#endif