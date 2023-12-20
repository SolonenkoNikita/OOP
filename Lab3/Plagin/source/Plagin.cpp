#include "Plagin/Plagin.hpp"

Creature Plagin::make_plagin(DirectorForFile& d, Creator_Creature& cr)
{
	TableWithAbility table;
	TakeDamage tk;
	Boom boom;
	Creature c = d.make(cr, "../../../../Files/Plagin.txt");
	table.set_ability(std::make_shared<TakeDamage>(std::move(tk)));
	table.set_ability(std::make_shared<Boom>(std::move(boom)));
	c.set_ability(std::move(table));
	return c;
}
