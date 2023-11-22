#include "Creator_Creature/Creator_Creature.h"

Creator_Creature::Creator_Creature()
{
	creature_ = std::make_shared<Creature>();
}

Creator_Creature& Creator_Creature::set_fraction(Fraction fr)
{
	creature_->set_fraction(fr);
	return *this;
}

Creator_Creature& Creator_Creature::make_characteristic(const Characteristics& characteristic)
{
	creature_->set_characteristics(characteristic);
	return *this;
}

Creator_Creature& Creator_Creature::make_abiliti(const TableWithAbility& table)
{
	creature_->set_ability(table);
	return *this;
}

Creator_Creature& Creator_Creature::set_name(const std::string& str)
{
	creature_->set_name_creature(str);
	return *this;
}

const std::string& Creator_Creature::get_name() const
{
	return creature_->get_name_creature();
}

std::shared_ptr<Creature> Creator_Creature::get_creature() const
{
	return creature_;
}
