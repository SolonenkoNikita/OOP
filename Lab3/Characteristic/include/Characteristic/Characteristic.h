#ifndef _Characteristic_H_
#define _Characteristic_H_

#include <unordered_map>
#include <memory>
#include <iostream>

/**
* @brief enum class Atrributes_Names
*/

enum class Atrributes_Names
{
	max_mana_,
	current_mana_,
	max_health_,
	current_health_,
	level_,
	experience_,
	damage_,
	attack_,
	protection_,
	skipping_damage_,
	essence_
};

std::string GetAttributeName(Atrributes_Names);
Atrributes_Names GetStringName(std::string);

/**
*@brief class Characteristic that stores a table of character characteristics and their values
* @param attributes - library hash table, where the key is enum class
*/

class Characteristics
{
private:
	std::unordered_map<Atrributes_Names, size_t> attributes;
public:
	void print();
public:
	/**
	* @brief default constructor
	*/

	Characteristics() = default;

	/**
	* @brief this function return const reference to hash table(std::unordered_map)
	* @return const std::vector<Base*>&
	*/

	const std::unordered_map<Atrributes_Names, size_t>& get_attribute() const ;

	/**
	* @brief constructor with initializet_list
	* @param l - the const reference by std::initializer_list with std::pair<Atrributes_Names, size_t>
	*/

	Characteristics(const std::initializer_list<std::pair<Atrributes_Names, size_t>> &l);
	
	/**
	* @brief this function adds a characteristic to the hash table
	* @param - name 
	* @param - meaning
	*/

	Characteristics& set_characteristic(Atrributes_Names, size_t);

	/**
	* @brief this function return meaning of characteristic by name
	* @param - name
	* @return - meaning
	*/

	size_t get_meaning(Atrributes_Names) const;

	/**
	* @brief operator ==
	* @param - const reference to class Charateristic
	* @return - bool 
	*/

	bool operator == (const Characteristics&) const;

};

#endif;