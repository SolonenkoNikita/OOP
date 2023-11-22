#include "Necromancer/Necromancer.h"

Creature Necromancer::make_necromancer(DirectorForFile& d, Creator_Creature& cr)
{
	TableWithAbility table;
	Desiccation debil;
	OpenDoor open;
	Curse curse;
	Necromancy necromancy;
	std::string str = "OpenDoor";
	std::string str1 = "Deseccation";
	std::string str2 = "Curse";
	std::string str3 = "Necromancy";
	table.set_ability(std::make_shared<OpenDoor>(open), str).set_ability(std::make_shared<Desiccation>(debil), str1);
	table.set_ability(std::make_shared<Necromancy>(necromancy), str3).set_ability(std::make_shared<Curse>(curse), str2);
	cr.make_abiliti(table);
	Creature c = d.make(cr, "../../../../Files/Necromancer.txt");
	return c;
}
