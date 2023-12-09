#include "Golem/Golem.h"

Golem::Golem(Characteristics cr) : characteristics_(std::move(cr)), rng_(rd_()), dist_(std::uniform_int_distribution<>(1, 3))
{
	TakeDamage tk;
	abilites_.set_ability(std::make_shared<TakeDamage>(std::move(tk)));
	set_id(5);
	rng_.seed(::time(NULL));
}

int Golem::roll()
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

void Golem::die(Cell& cell)
{
	auto i = roll();
	if (i == 1)
	{
		Lava lava(i);
		set_id(lava.get_id());
		cell.add_selection(std::move(std::make_shared<Lava>(std::move(lava))));
	}
	else if (i == 2)
	{
		Wall wall;
		set_id(wall.get_id());
		cell.add_selection(std::move(std::make_shared<Wall>(std::move(wall))));
	}
	else if (i == 3)
	{
		Essence essence;
		set_id(essence.get_id());
		cell.add_selection(std::move(std::make_shared<Essence>(std::move(essence))));
	}
	for(auto& cnt : cell.get_content())
	{ 
		if (auto golem = std::dynamic_pointer_cast<Golem>(cnt))
		{
			cell.delete_selection(golem);
			return;
		}
	}
}

void Golem::using_ability(Cell& cell, size_t index)
{
	std::shared_ptr<Ability> ab = abilites_.get_ability(index);
	ab->apply(characteristics_, cell);
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
	characteristics_.set_characteristic(Atrributes_Names::current_health_, std::max(0ull, stat - damag));
}

void Golem::get_damage(size_t damag)
{
	if (!is_died())
	{
		float an = static_cast<float>(100 - characteristics_.get_meaning(Atrributes_Names::protection_)) / 100;
		float d = round(damag * an);
		damag = d;
		get_damagble(damag);
	}
}

void Golem::kill(Cell& cell)
{
	die(cell);
}

void Golem::revival(Cell& cell)
{

}