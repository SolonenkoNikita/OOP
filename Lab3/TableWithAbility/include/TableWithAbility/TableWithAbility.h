#ifndef _TableWithAbility_H_
#define _TableWithAbility_H_

#include <unordered_map>
#include <vector>
#include <memory>

#include <Ability/Ability.h>

class TableWithAbility
{
private:
	//std::unordered_map<std::string, std::shared_ptr<Ability>> attributes_;
	std::vector<std::shared_ptr<Ability>> attributes_;

public:
	TableWithAbility() = default;

	/*const std::unordered_map<std::string, std::shared_ptr<Ability>>& get_attribute() const;

	TableWithAbility& set_ability(std::shared_ptr<Ability>, std::string&);

	std::shared_ptr<Ability> get_ability(const std::string&) const;*/

	const std::vector<std::shared_ptr<Ability>>& get_attribute() const;

	TableWithAbility& set_ability(std::shared_ptr<Ability>);

	std::shared_ptr<Ability> get_ability(size_t index);

};

#endif