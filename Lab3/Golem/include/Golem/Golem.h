#ifndef _Golem_H_
#define _Golem_H_

#include <Characteristic/Characteristic.h>
#include <General_Methods/General_Methods.h>
#include <Cell/Cell.h>

class Golem : public General_CLass
{
private:
	Characteristics characteristics_;
public:
	virtual void get_damage(size_t damag);
	virtual bool is_died() const;
	virtual void die(Cell&);
	virtual void vozrodit(Cell&);
	int random();
};

#endif