#include <gtest/gtest.h>

#include <Matrix/Matrix.hpp>
#include <Cell/Cell.h>
#include <Door/Door.h>

TEST(Matrix_int, GetTest)
{
	Matrix<int> a(3, 3);
	a[0][0] = 1;
	a[2][3] = 3;
	ASSERT_EQ(1, a.at(0, 0));
	ASSERT_EQ(3, a.at(2, 3));
}

TEST(Matrix_string, GetTest)
{
	Matrix<std::string> a(3, 3);
	a[0][0] = "abc";
	a[2][3] = "afrgr";
	ASSERT_EQ("abc", a.at(0, 0));
	ASSERT_EQ("afrgr", a.at(2, 3));
}

TEST(Matrix_Cell, GetTest)
{
	Matrix<Cell> a(3, 3);
	Cell cell;
	Door door;
	cell.add_selection(std::make_shared<Door>(std::move(door)));
	bool meaning = false;
	ASSERT_EQ(false, meaning);
	a[1][2] = cell;
	for (auto& c : a.at(1, 2).get_content())
	{
		if (auto d = std::dynamic_pointer_cast<Door>(c))
		{
			meaning = true;
		}
	}
	ASSERT_EQ(true, meaning);
}