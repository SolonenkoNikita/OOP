#ifndef _PushEssence_H_
#define _PushEssence_H_

#include <Ability/Ability.h>
#include <Essence/Essence.h>

/**
* @brief class Curse is the heir of the Ability, which implements the logic for pushing class Essence
*/

class PushEssence : public Ability
{
public:

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	bool is_long() const override;

	void apply(Characteristics& caster_characteristic, Cell& cell, Matrix<Cell>& m) override;
};

#endif