#ifndef _Unhead_H_
#define _Unhead_H_

#include <DamageCaused/DamageCaused.h>
#include <Creature/Creature.h>
#include <Obstacle/Obstacle.h>
   
/**
* @brief abstract class Unhead
* @param creature_ - class Creature
*/

class Unhead : public DamageCaused, public Obstacle
{
protected:
	Creature creature_;

public:

	void print()
	{
		creature_.print();
	}

	/**
	* @brief explicit constructor
	* @param - class Creature
	*/

	explicit Unhead(Creature);

	/**
	* @brief a function that checks whether a solid is solid or not
	* @return - bool
	*/

	bool is_hard() const override;

	/**
	* @brief this function - case of taking damage by creature
	* @param - damage
	*/

	void get_damage(size_t) override {};

	/**
	* @brief  a function that checks whether a character has died or not
	* @return - bool
	*/

	bool is_died() const override;

	/**
	* @brief  a function that invokes ability by name
	* @param - the cell to which will be called ability
	* @param - name
	*/

	void using_ability(Cell&, std::string&);

	void die(Cell&) override;

	void kill(Cell&) override;

	const Creature& get_creature() const;

	Creature& get_creature();

	void revival(Cell&) override;

	/**
	* @brief default virtual destructor 
	*/

	virtual ~Unhead() = default;
};

#endif