#ifndef _Creature_H_
#define _Creature_H_

#include <unordered_map>
#include <Ability/Ability.h>
#include <Characteristic/Characteristic.h>

#include <iostream>
#include <string>
#include <unordering_map>

enum class Fraction
{
	evil_,
	hero_,
};

class Creature
{
private:
	std::string name_;
	Characteristic characteristics_;
	std::unordered_map<std::string, Ability> abilites_;
	Fraction fraction_;
public:
	/*void add_fraction(Fraction& fraction);
	void change_franction(FRanction& fraction);
	get_fraction*/
};
 
#endif 
