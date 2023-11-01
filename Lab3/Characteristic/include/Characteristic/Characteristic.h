#ifndef _Characteristic_H_
#define _Characteristic_H_
//#define ATTRIBUTE_NAME(name) case Atrributes_Names::name: return #name

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

//std::string GetAttributeName(Atrributes_Names attribute)
//{
//	switch (attribute)
//	{
//		ATTRIBUTE_NAME(max_mana_);
//		ATTRIBUTE_NAME(current_mana_);
//		ATTRIBUTE_NAME(max_health_);
//		ATTRIBUTE_NAME(current_health_);
//		ATTRIBUTE_NAME(level_);
//		ATTRIBUTE_NAME(experience_);
//		ATTRIBUTE_NAME(damage_);
//	default: return "Unknown Attribute";
//	}
//}

class Characteristics
{
private:
	std::unordered_map<Atrributes_Names, size_t> attributes;
public:
	Characteristics() = default;
	~Characteristics() = default;
	Characteristics(const std::initializer_list<std::pair<Atrributes_Names, size_t>> & l);
	Characteristics& set_characteristic(Atrributes_Names, size_t);
	void print();
	std::string GetAttributeName(Atrributes_Names);
	size_t get_meaning(Atrributes_Names) const;
};

//#undef ATTRIBUTE_NAME

#endif;