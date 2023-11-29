#include <Room/Room.h>

Room::Room(std::shared_ptr<Matrix<Cell>> r)
{
	room_ = std::move(r);
}

Room& Room::add_cell(Cell cell)
{
	(*room_)[cell.x()][cell.y()] = std::move(cell);
	return *this;
}

Cell& Room::get_cell(Coordinate& c)
{
	return (*room_)[c.x][c.y];
}

const Cell& Room::get_cell(Coordinate& c) const
{
	return (*room_)[c.x][c.y];
}
