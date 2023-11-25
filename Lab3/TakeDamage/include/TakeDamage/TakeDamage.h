#ifndef _TakeDamage_H_
#define _TakeDamage_H_

#include <Ability/Ability.h>

class TakeDamage : public Ability
{
public:
	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif