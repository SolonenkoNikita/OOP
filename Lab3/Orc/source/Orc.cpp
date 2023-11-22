#include "Orc/Orc.h"

Creature Orc::make_orc(DirectorForFile& d, Creator_Creature& cr)
{
	Creature c = d.make(cr, "../../../../Files/Orc.txt");
	return c;
}
