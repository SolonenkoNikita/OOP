#include <cmath>

#include "Alive/Alive.h"

Alive::Alive(Creature cr, size_t id) : creature_(std::move(cr)), rng_(rd_()), dist_(std::uniform_int_distribution<>(1, 100))
{
	set_id(id);
	rng_.seed(::time(NULL));
}

int Alive::roll()
{
	return dist_(rng_);
}

bool Alive::is_hard() const
{
	return creature_.get_characteristic().get_meaning(Atrributes_Names::current_health_) >= 0;
}

Creature& Alive::get_creature()
{
	return creature_;
}

const Creature& Alive::get_creature() const
{
	return creature_;
}

Alive& Alive::set_creature(const Characteristics& ch)
{
	creature_.set_characteristics(ch);
	return *this;
}

bool Alive::is_died() const
{
	return creature_.get_characteristic().get_meaning(Atrributes_Names::current_health_) <= 0;
}

void Alive::using_ability(Cell& cell, size_t index, Matrix<Cell>& m)
{
	std::shared_ptr<Ability> ab = creature_.get_abilites().get_ability(index);
	ab->apply(creature_.get_characteristic(), cell, m);
}


void Alive::get_damagble(size_t damage)
{
	auto stat = creature_.get_characteristic().get_meaning(Atrributes_Names::current_health_);
	creature_.set_characteristics(Atrributes_Names::current_health_, std::max(0ull, stat - damage));	
}

void Alive::get_damage(size_t damage)
{
	if (!is_died())
	{
		auto en = creature_.get_characteristic().get_meaning(Atrributes_Names::skipping_damage_);
		float an = static_cast<float>(100 - creature_.get_characteristic().get_meaning(Atrributes_Names::protection_)) / 100;
		float d = round(damage * an);
		damage = d;
		damage *= (en <= roll());
		get_damagble(damage);
		return;
	}
	set_id(8);
}

void Alive::die(Cell& cell)
{
	old_id = get_id();
	creature_.get_characteristic().set_characteristic(Atrributes_Names::current_health_, 0ull);
	set_id(8);
}

void Alive::revival(Cell& cell)
{
	auto health = creature_.get_characteristic().get_meaning(Atrributes_Names::max_health_);
	creature_.get_characteristic().set_characteristic(Atrributes_Names::current_health_, health);
}

void Alive::kill(Cell& cell)
{
	creature_.get_characteristic().set_characteristic(Atrributes_Names::current_health_, 0ull);
}