#ifndef _Controler_H_
#define _Controler_H_

#include <memory>

#include <Matrix/Matrix.hpp>
#include <Base/Base.h>
#include <Cell/Cell.h>

class Controler
{
private:

	std::shared_ptr<Matrix<Cell>> matrix_;

	std::shared_ptr<Base> player_;

	Direction direction_;
public:

	Controler(std::shared_ptr<Base> player);

	void move(const Direction direction);
};

#endif