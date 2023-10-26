#ifndef _Ability_H_
#define _Ability_H_

#include <Cell/Cell.h>
#include <Creature/Creature.h>

class Ability
{
public:
	void apply(const Creature& caster, Cell& cell) = 0; //caster - кто использует
};

#endif