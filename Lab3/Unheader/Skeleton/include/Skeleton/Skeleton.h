#ifndef _Skeleton_H_
#define _Skeleton_H_

class Skeleton : public Unhead
{
public:
	virtual void get_damage(size_t damag);
	virtual void die(Cell&);
	virtual void revival(Cell&);
};

#endif