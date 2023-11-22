#ifndef _Necromancy_H_
#define _Necromancy_H_

#include <Ability/Ability.h>
#include <Alive/Alive.h>
#include <Unhead/Unhead.h>
#include <Skeleton/Skeleton.h>
#include <Zombie/Zombie.h>
#include <Ghost/Ghost.h>
#include <Utilits/Utilits.hpp>

#include <unordered_set>
#include <memory>

/**
* @brief class Curse is the heir of the Ability, which implements the logic for restoring undead from the corpse of an enemy
* @param level_ - level
* @param count_ - the counter is needed to change the level
* @param table_ - unoredered_set with smart pointer to Unhead
*/

class Necromancy : public Ability
{
private:
	size_t level_;
	
	size_t count_;

	std::unordered_set<std::shared_ptr<Unhead>> table_;
	
	/**
	* @brief this function checks the counter and changes the level if necessary
	*/

	void check();

	/**
	* @brief add new unhead
	*/

	void add_new_unhead(std::shared_ptr<Unhead>);

	void add_known_unheads();
public:

	/**
	* @brief default constructor
	*/

	Necromancy() : level_(0ull), count_(0ull) {};

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	void apply(Characteristics& caster_characteristic, Cell& cell) override;
};

#endif