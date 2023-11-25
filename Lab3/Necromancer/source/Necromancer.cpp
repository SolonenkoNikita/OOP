#include "Necromancer/Necromancer.h"

Creature Necromancer::make_necromancer(DirectorForFile& d, Creator_Creature& cr)
{
	TableWithAbility table;
	Desiccation<Atrributes_Names::current_mana_, Atrributes_Names::max_mana_> debil;
	OpenDoor open;
	Curse curse;
	TakeDamage tk;
	std::string str = "OpenDoor";
	std::string str1 = "Deseccation";
	std::string str2 = "Curse";
	std::string str3 = "Necromancy";
	std::string str4 = "Morphism";
	std::string str5 = "TakeDamage";
	Necromancy<Skeleton> t(4ull);
	Morphism<Zombie> m(3ull);
	table.set_ability(std::make_shared<OpenDoor>(open), str).set_ability(std::make_shared<Desiccation<Atrributes_Names::current_mana_, Atrributes_Names::max_mana_>>(debil), str1);
	table.set_ability(std::make_shared<Curse>(curse), str2).set_ability(std::make_shared<TakeDamage>(tk), str5);
	table.set_ability(std::make_shared<Necromancy<Skeleton>>(t), str3).set_ability(std::make_shared<Morphism<Zombie>>(m), str4);
	cr.make_abiliti(table);
	Creature c = d.make(cr, "../../../../Files/Necromancer.txt");
	return c;
}
