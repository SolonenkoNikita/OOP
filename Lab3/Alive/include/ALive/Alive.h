#ifndef _Alive_H_
#define _Alive_H_

#include <General_Class/General_Class.h>
#include <Creature/Creature.h>

class Alive : public General_Class
{
private:
	Creature creature_;
public:
	virtual void get_damage(size_t damag);
	virtual bool is_died() const;
	virtual void die(Cell&);
	virtual void revival(Cell&);
};

#endif