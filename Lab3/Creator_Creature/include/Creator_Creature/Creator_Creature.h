#ifndef _Creator_Creature_H_
#define _Creator_Creature_H_

#include <Creature/Creature.h>

class Creator_Creature
{
private:
	Creature creature_;
public:
	void set_name(std::string&);
	void make_characteristic();
	void make_ability();
	Creature& make_creature();
};