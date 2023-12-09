#include "TakeDamage/TakeDamage.h"

void TakeDamage::apply(Characteristics& caster_characteristic, Cell& cell)
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