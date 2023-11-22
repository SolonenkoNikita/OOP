#endif _MATRIX_HPP_
#define _MATRIX_HPP

#include <vector>
#include <MyVector/MyVector.hpp>

template<typename T>
class Matrix
{
	MyVector<MyVector<T>> data_;
};

#endif