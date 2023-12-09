#include "TableWithAbility/TableWithAbility.h"

TableWithAbility& TableWithAbility::set_ability(std::shared_ptr<Ability> Abi)
{

	attributes_.push_back(std::move(Abi));
	return *this;
}

std::shared_ptr<Ability> TableWithAbility::get_ability(size_t index)
{
	if (index > attributes_.size())
	{
		throw std::out_of_range("Segmentation Fault\n");
	}
	return attributes_[index];
}

const std::vector<std::shared_ptr<Ability>>& TableWithAbility::get_attribute() const
{
	return attributes_;
}