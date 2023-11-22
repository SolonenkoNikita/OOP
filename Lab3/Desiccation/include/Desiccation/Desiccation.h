#ifndef _Desiccation_H_
#define _Desiccation_H_

#include <Ability/Ability.h>
#include <Alive/Alive.h>

/**
* @brief class Desisccation is the heir of the Ability, which that allows you to turn an enemy's corpse inti mana or health
* @param level_ - level
* @param count_ - the counter is needed to change the level
*/

class Desiccation : public Ability
{
private:
	size_t level_;

	size_t count_;
	
	/**
	* @brief this function checks the counter and changes the level if necessary
	*/

	void check();
public:

	/**
	* @brief default constructor
	*/

	Desiccation() : level_(0ull), count_(0ull) {};

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif