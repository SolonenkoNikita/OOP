#include "PushEssence/PushEssence.h"

bool PushEssence::is_long() const
{
    false;
}

void PushEssence::apply(Characteristics& caster_characteristic, Cell& cell)
{
    for (auto& content : cell.get_content())
    {
        if (auto door = std::dynamic_pointer_cast<Essence>(content))
        {
            cell.delete_selection(door);
            auto size = caster_characteristic.get_meaning(Atrributes_Names::essence_);
            caster_characteristic.set_characteristic(Atrributes_Names::essence_, (size + 1));
            break;
        }
    }
}