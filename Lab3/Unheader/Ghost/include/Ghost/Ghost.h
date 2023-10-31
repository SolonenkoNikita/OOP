#ifndef _Ghost_H_
#define _Ghost_H_

class Ghost : public Unhead
{
public:
	virtual void get_damage(size_t damag);
	virtual void die(Cell&);
	virtual void revival(Cell&);
};

#endif