#include "Characteristic/Characteristic.h"
#include <iostream>

Characteristics::Characteristics(const std::initializer_list<std::pair<Atrributes_Names, size_t>>& l)
{
	for (auto i = l.begin(); i != l.end(); i++)
	{
		set_characteristic(i->first, i->second);
	}
}

std::string GetAttributeName(Atrributes_Names attribute)
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
	else if (attribute == Atrributes_Names::skipping_damage_)
	{
		return "skipping_damage_";
	}
	else if (attribute == Atrributes_Names::protection_)
	{
		return "protection_";
	}
	else if (attribute == Atrributes_Names::essence_)
	{
		return "essence";
	}
	else
	{
		return "damage_";
	}
}

Atrributes_Names GetStringName(std::string attribute)
{
	if (attribute == "max_mana")
	{
		return Atrributes_Names::max_mana_;
	}
	else if (attribute == "current_mana")
	{
		return Atrributes_Names::current_mana_;
	}
	else if (attribute == "max_health")
	{
		return Atrributes_Names::max_health_;
	}
	else if (attribute == "current_health")
	{
		return Atrributes_Names::current_health_;
	}
	else if (attribute == "level")
	{
		return Atrributes_Names::level_;
	}
	else if (attribute == "experience")
	{
		return Atrributes_Names::experience_;
	}
	else if (attribute == "skipping_damage")
	{
		return Atrributes_Names::skipping_damage_;
	}
	else if (attribute == "protection")
	{
		return Atrributes_Names::protection_;
	}
	else if (attribute == "essence")
	{
		return Atrributes_Names::essence_;
	}
	else
	{
		return Atrributes_Names::damage_;
	}
}

Characteristics& Characteristics::set_characteristic(Atrributes_Names name, size_t  meaning)
{

	attributes[name] = meaning;
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
	return it == attributes.end() ? 0 : it->second;
}

const std::unordered_map<Atrributes_Names, size_t>& Characteristics::get_attribute() const
{
	return attributes;
}

bool Characteristics::operator==(const Characteristics& ch) const
{
	return attributes == ch.attributes;
}