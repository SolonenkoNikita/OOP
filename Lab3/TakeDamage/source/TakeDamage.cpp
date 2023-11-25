#include "TakeDamage/TakeDamage.h"

void TakeDamage::apply(Characteristics& caster_characteristic, Cell& cell)
{
	for (auto& it : cell.get_content())
	{
		if (auto damage = std::dynamic_pointer_cast<DamageCaused>(it))
		{
			if (!damage->is_died())
			{
				damage->get_damage(caster_characteristic.get_meaning(Atrributes_Names::damage_));
				break;
			}
		}
	}
}