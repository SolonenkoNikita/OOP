#ifndef _Desiccation_H_
#define _Desiccation_H_

#include <Ability/Ability.h>
#include <Alive/Alive.h>

/**
* @brief class Desisccation is the heir of the Ability, which that allows you to turn an enemy's corpse inti mana or health
* @param level_ - level
* @param count_ - the counter is needed to change the level
*/

template<Atrributes_Names meaning, Atrributes_Names meaning_two>
class Desiccation : public Ability
{
private:

	size_t level_;

	size_t count_;
	
	/**
	* @brief this function checks the counter and changes the level if necessary
	*/

	void check()
	{
		level_ += (count_ % 10 != 0) ? 0 : 1;
	}
public:

	/**
	* @brief default constructor
	*/

	bool is_long() const override
	{
		return false;
	}

	Desiccation() : level_(0ull), count_(0ull) {};

	/**
	* @brief override funstion, that performs habilitation
	* @param caster_characteristic  - characteristics of the one who uses the ability
	* @param cell - the cell in which the skill will be ability
	*/

	void apply(Characteristics& caster_characteristic, Cell& cell, Matrix<Cell>& m) override
	{
		check();
		count_++;
		for (auto& content : cell.get_content())
		{
			if (auto alive = std::dynamic_pointer_cast<Alive>(content))
			{
				if (alive->is_died())
				{
					auto attribute = level_ * alive->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
					caster_characteristic.set_characteristic(meaning, std::min(caster_characteristic.get_meaning(meaning_two), attribute));
					cell.delete_selection(alive);
					return;
				}
			}
		}
	}
};

#endif