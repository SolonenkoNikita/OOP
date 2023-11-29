#ifndef _Creature_H_
#define _Creature_H_

#include <TableWithAbility/TableWithAbility.h>
#include <Characteristic/Characteristic.h>

#include <iostream>
#include <string>
#include <unordered_map>

/**
* @brief enum class Fraction
*/

enum class Fraction
{
	evil_,
	hero_,
};

std::string GetSringFraction(Fraction);

Fraction GetFraction(std::string);


/**
* @brief class Creature
* @param name_ - name by creature
* @param characteristics_ - characteristics by creature - class Characterisics
* @param abilites_ - abilites by creature - class TableWithAbility
* @param fraction_ - fraction by creature - enum class Fraction
*/

class Creature
{
private:
	std::string name_;

	Characteristics characteristics_;

	TableWithAbility abilites_;

	Fraction fraction_;
public:

	/**
	* @brief default constructor
	*/

	Creature() = default;

	/**
	* @brief this function creates the name
	* @param - const reference to std::string
	* @return - the reference to class Creature
	*/

	Creature& set_name_creature(const std::string&);

	/**
	* @brief this function returns const reference by the name of the creature
	* @return - const reference to std::string
	*/

	const std::string& get_name_creature() const;

	/**
	* @brief this function returns smart pointer to the characteristics
	* @return - smart pointer by class Characteristics
	*/

	Characteristics& get_characteristic();

	const Characteristics& get_characteristic() const;

	TableWithAbility& get_abilites();

	const TableWithAbility& get_abilites() const;

	/**
	* @brief this function creates characteristics
	* @param - const reference to class Characteristics
	* @return - the reference to class Creature
	*/

	Creature& set_characteristics(const Characteristics&);

	/**
	* @brief this function creates characteristics
	* @param - name by characteristic - enum class 
	* @param - meaning
	* @return - the reference to class Creature
	*/

	Creature& set_characteristics(Atrributes_Names, size_t);

	/**
	* @brief this function creates abilites
	* @param - const reference to TableWithAbility
	* @return - the reference to class Creature
	*/

	Creature& set_ability(const TableWithAbility&);

	/**
	* @brief this function returns fraction by the creature
	* @return - enum class Fraction
	*/

	Fraction get_fraction() const;

	/**
	* @brief this function creates the fraction
	* @param - fraction - enum class
	* @return - the reference to class Creature
	*/

	Creature& set_fraction(Fraction);

};
 
#endif 
