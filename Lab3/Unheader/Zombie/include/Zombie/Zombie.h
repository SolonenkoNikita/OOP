#ifndef _Zombie_H_
#define _Zombie_H_

class Zombie : public Unhead
{
public:
	virtual void get_damage(size_t damag);
	virtual void die(Cell&);
	virtual void revival(Cell&);
};

#endif