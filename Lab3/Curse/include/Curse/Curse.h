#ifndef _Curse_H_
#define _Curse_H_

#include <Ability/Ability.h>
#include <DamageCaused/DamageCaused.h>

/**
* @brief class Curse is the heir of the Ability, which implements the logic for applying remote magic damage
* @param level_ - level
* @param count_ - the counter is needed to change the level
*/

class Curse : public Ability
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

	bool is_long() const override;

	Curse() : level_(0ull), count_(1ull) {};

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif