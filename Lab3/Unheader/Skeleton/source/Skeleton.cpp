#include "Skeleton/Skeleton.h"

void Skeleton::get_damage(size_t damage)
{
	creature_.set_characteristics(Atrributes_Names::current_health_, 0ull);
}

Skeleton::Skeleton(Creature cr) : Unhead(std::move(cr))
{
	set_id(7);
}

