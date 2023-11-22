#ifndef _Creator_Creature_H_
#define _Creator_Creature_H_

#include <Creature/Creature.h>

#include <iostream>
#include <memory>

/**
* @brief class Creatore_Creature - the class that creates the creature
* @param creature_ - smart pointer to class Creature
*/

class Creator_Creature
{
private:
	std::shared_ptr<Creature> creature_;

public:

	/**
	* @brief constructor without parametrs
	*/

	Creator_Creature();

	/**
	* @brief this function creates the characteristics
	* @param - const reference to class Characteristics
	* @return - the reference to class Creator_Creature
	*/

	Creator_Creature& make_characteristic(const Characteristics&);

	/**
	* @brief this function creates the table with abilites
	* @param - const reference to class TableWithAbility
	* @return - the reference to class Creator_Creature
	*/

	Creator_Creature& make_abiliti(const TableWithAbility&);

	/**
	* @brief this function creates the name
	* @param - const reference to std::string
	* @return - the reference to class Creator_Creature
	*/

	Creator_Creature& set_name(const std::string&);

	/**
	* @brief this function creates the fraction
	* @param - const reference to enum class Fraction
	* @return - the reference to class Creator_Creature
	*/

	Creator_Creature& set_fraction(Fraction);

	/**
	* @brief this function returns const reference by the name of the creature
	* @return - const reference to std::string
	*/

	const std::string& get_name() const;

	/**
	* @brief this function returns smart pointer to the creature
	* @return - returns smart pointer
	*/

	std::shared_ptr<Creature> get_creature() const;
};

#endif