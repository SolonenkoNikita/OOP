#include "Golem/Golem.h"

Golem::Golem(Characteristics cr) : characteristics_(std::move(cr)), rng_(rd_()), dist_(std::uniform_int_distribution<>(1, 3))
{
	rng_.seed(::time(NULL));
}

int Alive::roll()
{
	return dist_(rng_);
}

bool Golem::is_died() const 
{
	return characteristics_.get_meaning(Atrributes_Names::current_health_) <= 0;
}

bool Golem::is_hard() const
{
	return true;
}

int Golem::random() const
{
	return roll() + 1;
}

void Golem::die(Cell& cell)
{
	int i = random();
	if (i == 1)
	{
		Lava lava;
		cell.add_selection(lava);
	}
	else if (i == 2)
	{
		
		Wall wall;
		cell.add_selection(wall);
	}
	else if (i == 3)
	{
		Essence essence;
		cell.add_selection(essence);
	}
	cell.delete_selection(*this);
}

Golem& Golem::set_characteristics(Atrributes_Names name, size_t meaning)
{
	characteristics_.set_characteristic(name, meaning);
	return *this;
}

size_t Golem::get_meaning(Atrributes_Names name) const
{
	return characteristics_.get_meaning(name);
}

void Golem::get_damagble(size_t damag)
{
	auto stat = characteristics_.get_meaning(Atrributes_Names::current_health_);
	characteristics_.set_characteristics(Atrributes_Names::current_health_, std::max(0ull, stat - damage));
}

void Golem::get_damage(size_t damag)
{
	if (!is_died())
	{
		float an = static_cast<float>(100 - characteristics_.get_meaning(Atrributes_Names::protection_)) / 100;
		float d = round(damage * an);
		damage = d;
		get_damagble(damage);
	}
}

void Golem::revival(Cell& cell)
{

}