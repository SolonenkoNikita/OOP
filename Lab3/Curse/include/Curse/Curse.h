#ifndef _Curse_H_
#define _Curse_H_

#include <Ability/Ability.h>

class Curse : public Ability
{
	virtual apply(const Creature& caster, Cell& cell);
};