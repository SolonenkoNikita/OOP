#include "TableWithAbility/TableWithAbility.h"

//TableWithAbility& TableWithAbility::set_ability(std::shared_ptr<Ability> Abi, std::string& number)
//{
//
//	attributes_[number] = Abi;
//	return *this;
//}
//
//std::shared_ptr<Ability> TableWithAbility::get_ability(const std::string& name) const
//{
//	auto it = attributes_.find(name);
//	return it == attributes_.end() ? nullptr : it->second;
//}
//
//const std::unordered_map<std::string, std::shared_ptr<Ability>>& TableWithAbility::get_attribute() const
//{
//	return attributes_;
//}

TableWithAbility& TableWithAbility::set_ability(std::shared_ptr<Ability> Abi)
{

	attributes_.push_back(std::move(Abi));
	return *this;
}

std::shared_ptr<Ability> TableWithAbility::get_ability(size_t index)
{
	if (index > attributes_.size())
	{
		throw std::runtime_error("Segmentation Fault\n");
	}
	return attributes_[index];
}

const std::vector<std::shared_ptr<Ability>>& TableWithAbility::get_attribute() const
{
	return attributes_;
}