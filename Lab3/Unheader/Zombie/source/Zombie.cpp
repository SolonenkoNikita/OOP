#include "Zombie/Zombie.h"

void Zombie::get_damage(size_t damage)
{
	damage = damage / 2;
	if (!is_died())
	{
		auto stat = creature_.get_characteristic().get_meaning(Atrributes_Names::current_health_);
		if ((stat - damage) >= INT_MAX)
		{
			creature_.set_characteristics(Atrributes_Names::current_health_, 0ull);
			return;
		}
		creature_.set_characteristics(Atrributes_Names::current_health_, std::max(0ull, stat - damage));
	}
}


Zombie::Zombie(Creature cr) : Unhead(std::move(cr))
{
	set_id(11);
}
