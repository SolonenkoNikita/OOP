#ifndef _Characteristic_H_
#define _Characteristic_H_

#include <unordered_map>
#include <iostream>

enum class Atrributes_Names
{
	max_mana_,
	current_mana_,
	max_health_,
	current_health_,
	level_,
	experience_,
	damage_,
};

class Characteristics
{
private:
	Atrributes_Names names_;
	unordered_map<std::string, size_t> attributes;
public:
	Characteristics() = default;
	Characterictics& set_characteristic(std::string& str, size_t meaning);
	size_t get_meaning(std::string& str) const;
};

#endif