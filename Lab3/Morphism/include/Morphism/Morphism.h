#ifndef _Morphism_H_
#define _Morphism_H_

#include <Ability/Ability.h>

class Morphism : public Ability
{
	virtual apply(const Creature& caster, Cell& cell);
};