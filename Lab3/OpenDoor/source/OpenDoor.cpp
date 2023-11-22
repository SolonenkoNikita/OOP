#include "OpenDoor/OpenDoor.h"

void OpenDoor::apply(Characteristics& caster_characteristic, Cell& cell)
{
    for (auto& content : cell.get_content())
    {
        if (auto door = dynamic_cast<Door*>(content))
        {
            door->open();
            break;
        }
    }
}