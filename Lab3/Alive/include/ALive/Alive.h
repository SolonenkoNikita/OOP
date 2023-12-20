#ifndef _Alive_H_
#define _Alive_H_

#include <DamageCaused/DamageCaused.h>
#include <Creature/Creature.h>
#include <Player/Player.h>

#include <random>
#include <time.h>

/**
* @brief  this class that inherits from DamageCaused and Obstacle
* @param creature_ - class Creature
* @param rd_ - std::random_device
* @param dist_ - std::uniform_int_distribution<int> 
*/

class Alive : public DamageCaused, public Obstacle, public Player
{
private:

	size_t old_id;

	Creature creature_;

	std::random_device rd_;

	typedef std::mt19937 MyRng;

	MyRng rng_;

	std::uniform_int_distribution<int> dist_;

	/**
	* @brief this function - the general case of taking damage
	* @param - damage
	*/

	void get_damagble(size_t);
	
	/**
	* @brief this function doing random 
	* @return random value
	*/ 

	int roll(); 

public:

	/**
	* @brief explicit constructor
	* @param - class Creature
	*/

	Alive(Creature, size_t id);

	/**
	* @brief a function that checks whether a solid is solid or not
	* @return - bool 
	*/

	bool is_hard() const override;

	/**
	* @brief this function - case of taking damage by creature
	* @param - damage
	*/

	void get_damage(size_t) override;

	Creature& get_creature();

	const Creature& get_creature() const;

	/**
	* @brief this function - changing creature characteristic
	* @return - reference to class Alive
	*/

	Alive& set_creature(const Characteristics&);

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

	void using_ability(Cell&, size_t, Matrix<Cell>&) override;

	void die(Cell&) override;

	void revival(Cell&) override;

	void kill(Cell&) override;
};

#endif