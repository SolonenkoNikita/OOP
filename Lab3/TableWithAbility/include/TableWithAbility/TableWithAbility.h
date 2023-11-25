#ifndef _TableWithAbility_H_
#define _TableWithAbility_H_

#include <unordered_map>
#include <memory>

#include <Ability/Ability.h>

class TableWithAbility
{
private:
	std::unordered_map<std::string, std::shared_ptr<Ability>> attributes_;

public:
	TableWithAbility() = default;

	const std::unordered_map<std::string, std::shared_ptr<Ability>>& get_attribute() const;

	TableWithAbility& set_ability(std::shared_ptr<Ability>, std::string&);

	std::shared_ptr<Ability> get_ability(const std::string&) const;
};

#endif