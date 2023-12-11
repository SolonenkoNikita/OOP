#ifndef _Ability_H_
#define _Ability_H_

#include <Cell/Cell.h>
#include <Characteristic/Characteristic.h>

/**
* @brief Abstract Class Ability, that defines the ability call
*/

class Ability 
{
public:
	/**
	* @brief defaut virtual destructor
	*/

	virtual bool is_long() const = 0;

	virtual ~Ability() = default; 

	/**
	* @brief pure virtual funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/
	virtual void apply(Characteristics& caster_characteristic, Cell& cell) = 0;

};

#endif