#ifndef _Unhead_H_
#define _Unhead_H_

#include <../General_Class/General_Class.h>
#include <../Creature/Creature.h>

class Unhead : public General_Class
{
private:
	Creature creature_;
protected:
	size_t power_;
public:
	size_t get_power() const;
	virtual bool is_died();
};

#endif