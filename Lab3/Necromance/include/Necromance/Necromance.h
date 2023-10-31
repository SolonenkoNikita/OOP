#ifndef _Necromance_H_
#define _Necromance_H_

#include <Ability/Ability.h>

class Necromance : public Ability
{
	virtual apply(const Creature& caster, Cell& cell);
};