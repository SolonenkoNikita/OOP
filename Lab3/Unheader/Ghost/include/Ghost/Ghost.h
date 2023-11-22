#ifndef _Ghost_H_
#define _Ghost_H_

#include <Unhead/Unhead.h>

class Ghost : public Unhead
{
public:
	Ghost(Creature cr);

	void get_damage(size_t damag) override;
};

#endif