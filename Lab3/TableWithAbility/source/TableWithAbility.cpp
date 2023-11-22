#include "TableWithAbility/TableWithAbility.h"

TableWithAbility& TableWithAbility::set_ability(std::shared_ptr<Ability> Abi, std::string& number)
{

	attributes_[number] = Abi;
	return *this;
}

std::shared_ptr<Ability> TableWithAbility::get_ability(const std::string& name) const
{
	auto it = attributes_.find(name);
	return it == attributes_.end() ? nullptr : it->second;
}

const std::unordered_map<std::string, std::shared_ptr<Ability>>& TableWithAbility::get_attribute() const
{
	return attributes_;
}