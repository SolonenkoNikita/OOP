#ifndef _Golem_H_
#define _Golem_H_

#include <Characteristic/Characteristic.h>
#include <DamageCaused/DamageCaused.h>
#include <Lava/Lava.h>
#include <UnResponsive/UnResponsive.h>
#include <Essence/Essence.h>
#include <Obstacle/Obstacle.h>

#include <iostream>
#include <ctime>
#include <random>

/**
* @brief class Golem 
* @param characteristics_ - class Characteristics
* @param rd_ - std::random_device
* @param dist_ - std::uniform_int_distribution<int>
*/

class Golem : public DamageCaused, public Obstacle
{
private:
	Characteristics characteristics_;

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
	* @param - class Characteristics
	*/

	explicit Golem(Characteristics);

	/**
	* @brief this function - case of taking damage by creature
	* @param - damage
	*/

	void get_damage(size_t damag) override;

	/**
	* @brief a function that checks whether a solid is solid or not
	* @return - bool
	*/

	bool is_hard() const override;

	/**
	* @brief  a function that checks whether a character has died or not
	* @return - bool
	*/

	bool is_died() const override;

	void die(Cell&) override;

	void revival(Cell&) override;

	void kill(Cell& cell) override;

	/**
	* @brief this function - changing creature characteristic
	* @return - reference to class Golem
	*/

	Golem& set_characteristics(Atrributes_Names, size_t);

	size_t get_meaning(Atrributes_Names) const;

	/**
	* @brief default constructor
	*/

	Golem() = default;

};

#endif