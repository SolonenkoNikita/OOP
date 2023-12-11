#include "OpenDoor/OpenDoor.h"

bool OpenDoor::is_long() const 
{
    return false;
}

void OpenDoor::apply(Characteristics& caster_characteristic, Cell& cell)
{
    for (auto& content : cell.get_content())
    {
        if (auto door = std::dynamic_pointer_cast<Door>(content))
        {
            door->open();
            break;
        }
    }
}