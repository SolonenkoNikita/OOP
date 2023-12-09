#ifndef _Room_H_
#define _Room_H_

#include <Matrix/Matrix.hpp>
#include <Cell/Cell.h>

class Room
{
private:
	std::shared_ptr<Matrix<Cell>> room_;
public:

	std::shared_ptr<Matrix<Cell>> get_matrix()
	{
		return room_;
	}

	Room(std::shared_ptr<Matrix<Cell>> r);

	Room& add_cell(Cell cell);

	Cell& get_cell(Coordinate& c);

	const Cell& get_cell(Coordinate& c) const;
};

#endif