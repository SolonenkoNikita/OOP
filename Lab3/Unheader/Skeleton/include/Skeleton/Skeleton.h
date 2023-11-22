#ifndef _Skeleton_H_
#define _Skeleton_H_

#include <Unhead/Unhead.h>

class Skeleton : public Unhead
{
public:

	Skeleton(Creature cr);

	void get_damage(size_t damag) override;

};

#endif