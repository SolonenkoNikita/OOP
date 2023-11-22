#ifndef _OpenDoor_H_
#define _OpenDoor_H_

#include <Ability/Ability.h>
#include <Door/Door.h>

/**
* @brief class Curse is the heir of the Ability, which implements the logic for opened door
*/


class OpenDoor : public Ability
{
public:

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif 