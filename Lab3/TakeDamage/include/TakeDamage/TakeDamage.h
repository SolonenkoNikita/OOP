#ifndef _TakeDamage_H_
#define _TakeDamage_H_

#include <Ability/Ability.h>

class TakeDamage : public Ability
{
public:

	bool is_long() const override;

	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif