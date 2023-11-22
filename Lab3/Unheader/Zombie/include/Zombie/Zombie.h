#ifndef _Zombie_H_
#define _Zombie_H_

#include <Unhead/Unhead.h>

class Zombie : public Unhead
{
public:
	Zombie(Creature cr);

	void get_damage(size_t damag) override;
};

#endif