#include "Zombie/Zombie.h"

void Zombie::get_damage(size_t damage)
{
	creature_.set_characteristics(Atrributes_Names::current_health_, damage / 2);
}

Zombie::Zombie(Creature cr) : Unhead(std::move(cr))
{
	set_id(11);
}
