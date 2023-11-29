#include "Unhead/Unhead.h"

bool Unhead::is_hard() const
{
	return true;
}

Unhead::Unhead(Creature cr) : creature_(std::move(cr))
{
}

bool Unhead::is_died() const
{
	return false;
}

Creature& Unhead::get_creature()
{
	return creature_;
}

const Creature& Unhead::get_creature() const
{
	return creature_;
}

void Unhead::revival(Cell& cell)
{

}

void Unhead::die(Cell& cell)
{
	for (auto& cnt : cell.get_content())
	{
		if (auto unhead = std::dynamic_pointer_cast<Unhead>(cnt))
		{
			cell.delete_selection(unhead);
			return;
		}
	}
}

//void Unhead::using_ability(Cell& cell, std::string& str)
//{
//	std::shared_ptr<Ability> ab = creature_.get_abilites().get_ability(str);
//	ab->apply(creature_.get_characteristic(), cell);
//}

void Unhead::using_ability(Cell& cell, size_t index)
{
	std::shared_ptr<Ability> ab = creature_.get_abilites().get_ability(index);
	ab->apply(creature_.get_characteristic(), cell);
}


void Unhead::kill(Cell& cell)
{
	die(cell);
}