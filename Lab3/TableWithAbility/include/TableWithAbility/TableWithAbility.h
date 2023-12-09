#ifndef _TableWithAbility_H_
#define _TableWithAbility_H_

#include <unordered_map>
#include <vector>
#include <memory>

#include <Ability/Ability.h>

class TableWithAbility
{
private:
	std::vector<std::shared_ptr<Ability>> attributes_;

public:
	TableWithAbility() = default;

	const std::vector<std::shared_ptr<Ability>>& get_attribute() const;

	TableWithAbility& set_ability(std::shared_ptr<Ability>);

	std::shared_ptr<Ability> get_ability(size_t index);

};

#endif