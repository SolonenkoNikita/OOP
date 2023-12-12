#ifndef _Search_HPP_
#define _Search_HPP_

#include <Room/Room.h>

class Search
{
public:

	std::vector<Coordinate> search(const Matrix<Cell>&, const Coordinate&, const Coordinate&);
};

#endif