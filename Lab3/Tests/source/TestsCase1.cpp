#include <gtest/gtest.h>
#include <MyVector/MyVector.hpp>

TEST(Construct_test_default_int, GetTest)
{
	MyVector<int> v;
	ASSERT_EQ(0, v.size());
	ASSERT_EQ(1, v.capacity()); 
}

TEST(Construct_test_count_int, GetTest)
{
	MyVector<int> v(5);
	ASSERT_EQ(5, v.size());
	ASSERT_EQ(10, v.capacity());
}

TEST(Construct_test_init_list_int, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	ASSERT_EQ(3, v.size());
	ASSERT_EQ(6, v.capacity());
	auto beg = v.begin();
	auto end = v.end();
	ASSERT_EQ(1, *beg);
	ASSERT_EQ(3, *(end - 1));
}

TEST(Construct_test_default_string, GetTest)
{
	MyVector<std::string> v;
	ASSERT_EQ(0, v.size());
	ASSERT_EQ(1, v.capacity());
}

TEST(Construct_test_init_list_string, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c"};
	ASSERT_EQ(3, v.size());
	ASSERT_EQ(6, v.capacity());
	auto beg = v.begin();
	auto end = v.end();
	ASSERT_EQ("a", *beg);
	ASSERT_EQ("c", *(end - 1));
}

TEST(Construct_test_copy_int, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	MyVector<int> v1(v);
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ(1, *beg);
	ASSERT_EQ(3, *(end - 1));
}

TEST(Construct_test_move_int, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	MyVector<int> v1(std::move(v));
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ(1, *beg);
	ASSERT_EQ(3, *(end - 1));
}

TEST(Construct_test_copy_string, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	MyVector<std::string> v1(v);
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ("a", *beg);
	ASSERT_EQ("c", *(end - 1));
}

TEST(Construct_test_move_string, GetTest)
{
	MyVector<std::string> v = {"a", "b", "c"};
	MyVector<std::string> v1(std::move(v));
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ("a", *beg);
	ASSERT_EQ("c", * (end - 1));
}

TEST(Operator_one, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	MyVector<int> v1;
	v1 = v;
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ(1, *beg);
	ASSERT_EQ(3, *(end - 1));
}

TEST(Operator_two, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	MyVector<int> v1;
	v1 = std::move(v);
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v1.begin();
	auto end = v1.end();
	ASSERT_EQ(1, *beg);
	ASSERT_EQ(3, *(end - 1));
}

TEST(Operator_three, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	for (int i = 0; i < v.size(); i++)
	{
		ASSERT_EQ(i + 1, v[i]);
	}
	const MyVector<int> v1 = { 1, 2, 3 };
	for (int i = 0; i < v1.size(); i++)
	{
		ASSERT_EQ(i + 1, v1[i]);
	}
}

TEST(AT, GetTest)
{
	MyVector<int> v = { 1, 2, 3 };
	for (int i = 0; i < v.size(); i++)
	{
		ASSERT_EQ(i + 1, v.at(i));
	}
	const MyVector<int> v1 = { 1, 2, 3 };
	for (int i = 0; i < v1.size(); i++)
	{
		ASSERT_EQ(i + 1, v1.at(i));
	}
	MyVector<int> v2; 
	ASSERT_THROW(v2.at(-1), std::out_of_range);
	const MyVector<int> v3;
	ASSERT_THROW(v3.at(2), std::out_of_range);
}

TEST(SWAP, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	MyVector<std::string> v1 = { "d", "f", "g" };
	ASSERT_EQ(3, v.size());
	ASSERT_EQ(6, v.capacity());
	ASSERT_EQ(3, v1.size());
	ASSERT_EQ(6, v1.capacity());
	auto beg = v.begin();
	auto end = v.end();
	auto beg1 = v1.begin();
	auto end1 = v1.end();
	ASSERT_EQ("a", *beg);
	ASSERT_EQ("c", *(end - 1));
	ASSERT_EQ("d", *beg1);
	ASSERT_EQ("g", *(end1 - 1));
	v1.swap(v);
	auto b = v.begin();
	auto en = v.end();
	auto be1 = v1.begin();
	auto en1 = v1.end();
	ASSERT_EQ("d", *b);
	ASSERT_EQ("g", *(en - 1));
	ASSERT_EQ("a", *be1);
	ASSERT_EQ("c", *(en1 - 1));
}

TEST(INSERT, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	v.insert(1, "g");
	ASSERT_EQ(4, v.size());
	ASSERT_EQ("g", v[1]);
	ASSERT_EQ("b", v[2]);
	v.insert(2, "f");
	ASSERT_EQ(5, v.size());
	ASSERT_EQ("f", v[2]);
	ASSERT_EQ("b", v[3]);
	ASSERT_THROW(v.insert(-1, "f"), std::runtime_error);

}

TEST(PUSH_BACK, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	v.push_back("g");
	ASSERT_EQ(4, v.size());
	ASSERT_EQ("g", v[v.size() - 1]);
	v.push_back("g");
	v.push_back("g");
	v.push_back("g");
	ASSERT_EQ(12, v.capacity());
}

TEST(RESERVE, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	v.reserve(10);
	ASSERT_EQ(10, v.capacity());
	ASSERT_EQ(3, v.size());
}

TEST(RESIZE, GetTest)
{
	MyVector<std::string> v = { "a", "b", "c" };
	v.resize(1);
	ASSERT_EQ(6, v.capacity());
	ASSERT_EQ(1, v.size());
}