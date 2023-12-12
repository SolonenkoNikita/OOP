#include "Goblin/Goblin.hpp"

Creature Goblin::make_goblin(DirectorForFile& d, Creator_Creature& cr)
{
	TableWithAbility table;
	TakeDamage tk;
	Creature c = d.make(cr, "../../../../Files/Goblin.txt");
	table.set_ability((std::make_shared<TakeDamage>(std::move(tk))));
	c.set_ability(std::move(table));
	return c;
}
