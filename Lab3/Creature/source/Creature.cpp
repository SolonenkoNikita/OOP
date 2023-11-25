#include "Creature/Creature.h"

std::string GetSringFraction(Fraction fr)
{
	if (fr == Fraction::evil_)
	{
		return "evil";
	}
	return "hero";
}

Fraction GetFraction(std::string fr)
{
	if (fr == "evil")
	{
		return  Fraction::evil_;
	}
	return Fraction::hero_;
}

Fraction Creature::get_fraction() const
{
	return fraction_;
}

Creature& Creature::set_fraction(Fraction fr)
{
	fraction_ = fr;
	return *this;
}

Characteristics& Creature::get_characteristic()
{
	return characteristics_;
}

const Characteristics& Creature::get_characteristic() const
{
	return characteristics_;
}

TableWithAbility& Creature::get_abilites()
{
	return abilites_;
}

const TableWithAbility& Creature::get_abilites() const
{
	return abilites_;
}

Creature& Creature::set_name_creature(const std::string& name)
{
	name_ = name;
	return *this;
}

const std::string& Creature::get_name_creature() const
{
	return name_;
}

Creature& Creature::set_characteristics(const Characteristics& ch)
{
	characteristics_ = ch;
	return *this;
}

Creature& Creature::set_ability(const TableWithAbility& ab)
{
	abilites_ = ab;
	return *this;
}

Creature& Creature::set_characteristics(Atrributes_Names name, size_t value)
{
	characteristics_.set_characteristic(name, value);
	return *this;
}