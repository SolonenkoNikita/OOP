#include "TakeDamage/TakeDamage.h"

bool TakeDamage::is_long() const 
{
	return false;
}

void TakeDamage::apply(Characteristics& caster_characteristic, Cell& cell, Matrix<Cell>& m)
{
	for (auto& it : cell.get_content())
	{
		if (auto damage = std::dynamic_pointer_cast<DamageCaused>(it))
		{
			if (!damage->is_died())
			{
				size_t damag = caster_characteristic.get_meaning(Atrributes_Names::damage_);
				damage->get_damage(damag);
				break;
			}
		}
	}
}