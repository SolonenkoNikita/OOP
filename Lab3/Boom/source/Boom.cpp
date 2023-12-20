#include "Boom/Boom.hpp"

bool Boom::is_long() const
{
	return false;
}

void Boom::operation(Cell& cell)
{
	for (auto& it : cell.get_content())
	{
		if (auto damage = std::dynamic_pointer_cast<DamageCaused>(it))
		{
			if (!damage->is_died())
			{
				damage->die(cell);
				break;
			}
		}
	}
}

void Boom::apply(Characteristics& caster_characteristic, Cell& cell, Matrix<Cell>& m)
{
	operation(cell);
	if (cell.x() + 1 < m.size_matrix())
	{
		operation(m.at(cell.x() + 1, cell.y()));
	}
	if (cell.x() - 1 >= 0)
	{
		operation(m.at(cell.x() - 1, cell.y()));
	} 
	if (cell.y() + 1 < m.size_line())
	{
		operation(m.at(cell.x(), cell.y() + 1));
	} 
	if(cell.y() - 1 >= 0)
	{
		operation(m.at(cell.x(), cell.y() - 1));
	}
}