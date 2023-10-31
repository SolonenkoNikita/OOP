#ifndef _General_Class_H_
#define _General_Class_H_

#include <Cell/Cell.h>

class General_Class
{
private:
	General_Class container_;
public:
	virtual void get_damage(size_t damag) = 0;
	virtual bool is_died() const = 0;
	virtual void die(Cell&) = 0;
	virtual void revival(Cell&) = 0;
};

#endif