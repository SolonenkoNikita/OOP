#include "Ghost/Ghost.h"

void Ghost::get_damage(size_t damage)
{
	creature_.set_characteristics(Atrributes_Names::current_health_, damage / 3);
}

Ghost::Ghost(Creature cr) : Unhead(std::move(cr))
{
	set_id(9);
}

