#include <cmath>

#include "Alive/Alive.h"

Alive::Alive(Creature cr) : creature_(std::move(cr)), rng_(rd_()), dist_(std::uniform_int_distribution<>(1, 100))
{
	rng_.seed(::time(NULL));
}

int Alive::roll()
{
	return dist_(rng_);
}

bool Alive::is_hard() const
{
	return creature_.get_characteristic()->get_meaning(Atrributes_Names::current_health_) >= 0;
}

std::shared_ptr<Creature> Alive::get_creature() const
{
	return std::make_shared<Creature>(creature_);
}

Alive& Alive::set_creature(const Characteristics& ch)
{
	creature_.set_characteristics(ch);
	return *this;
}

bool Alive::is_died() const
{
	return creature_.get_characteristic()->get_meaning(Atrributes_Names::current_health_) <= 0;
}

void Alive::using_ability(Cell& cell, std::string& str)
{
	std::shared_ptr<Ability> ab = creature_.get_abilites()->get_ability(str);
	Characteristics ch = *creature_.get_characteristic();
	ab->apply(ch, cell);
	creature_.set_characteristics(std::move(ch));
}


void Alive::get_damagble(size_t damage)
{
	auto stat = creature_.get_characteristic()->get_meaning(Atrributes_Names::current_health_);
	creature_.set_characteristics(Atrributes_Names::current_health_, std::max(0ull, stat - damage));	
}

void Alive::get_damage(size_t damage)
{
	if (!is_died())
	{
		auto en = creature_.get_characteristic()->get_meaning(Atrributes_Names::skipping_damage_);
		float an = static_cast<float>(100 - creature_.get_characteristic()->get_meaning(Atrributes_Names::protection_)) / 100;
		float d = round(damage * an);
		damage = d;
		damage *= (en <= roll());
		get_damagble(damage);
	}
}

void Alive::die(Cell& cell)
{
	//что-то с телом сделать при визаулизации
}

//void ALive::revival();