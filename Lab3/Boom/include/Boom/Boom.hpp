#ifndef _Boom_HPP_
#define _Boom_HPP_

#include <Ability/Ability.h>

class Boom : public Ability
{
private:

	void operation(Cell& cell);
public:

	bool is_long() const override;

	void apply(Characteristics& caster_characteristic, Cell& cell, Matrix<Cell>& m) override;
};

#endif