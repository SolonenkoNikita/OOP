#ifndef _Golem_H_
#define _Golem_H_

#include <Characteristic/Characteristic.h>
#include <General_Class/General_Class.h>

class Golem : public General_Class
{
private:
	Characteristics characteristics_;
public:
	virtual void get_damage(size_t damag) override;
	virtual bool is_died()const override;
	virtual void die(Cell&) override;
	virtual void revival(Cell&) override;
	int random() const;
	Golem() = default;
	~Golem() = default;
};

#endif