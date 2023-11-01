#include "Characteristic/Characteristic.h"
#include <iostream>

Characteristics::Characteristics(const std::initializer_list<std::pair<Atrributes_Names, size_t>>& l)
{
	for (auto i = l.begin(); i != l.end(); i++)
	{
		set_characteristic(i->first, i->second);
	}
}

std::string Characteristics::GetAttributeName(Atrributes_Names attribute)
{
	if (attribute == Atrributes_Names::max_mana_)
	{
		return "max_mana_";
	}
	else if (attribute == Atrributes_Names::current_mana_)
	{
		return "current_mana_";
	}
	else if (attribute == Atrributes_Names::max_health_)
	{
		return "max_health_";
	}
	else if (attribute == Atrributes_Names::current_health_)
	{
		return "current_health_";
	}
	else if (attribute == Atrributes_Names::level_)
	{
		return "level_";
	}
	else if (attribute == Atrributes_Names::experience_)
	{
		return "experience_";
	}
	else
	{
		return "damage_";
	}
}

Characteristics& Characteristics::set_characteristic(Atrributes_Names name, size_t  meaning)
{
	auto it = attributes.find(name);
	if (it == attributes.end())
	{
		attributes.insert(std::make_pair(name, meaning));
	}
	else
	{
		it->second = meaning;
	}
	return *this;
}

void Characteristics::print()
{
    std::cout << "All Elements : \n";
    for (auto itr = attributes.begin(); itr != attributes.end(); itr++)
    {
        std::cout << GetAttributeName(itr->first) << "  " <<
            itr->second << std::endl;
    }
}

size_t Characteristics::get_meaning(Atrributes_Names name) const
{
	auto it = attributes.find(name);
	return it->second;
}

