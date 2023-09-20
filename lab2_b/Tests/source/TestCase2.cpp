#include <gtest/gtest.h>

#include <WeatherForecast/WeatherForecast.h>

TEST(MethodsTest, GetTestW)
{
	Date d{ 1, 2 };
	DailyForecast one(d, 2, 0);
	WeatherForecast w(one);
	ASSERT_EQ(1, w.GetCsize());
}

TEST(MethodsTest, GetTestW1)
{
	Date d{ 1, 2 }, d1{ 2, 3 };
	DailyForecast array[2], one(d, 1, 1), two(d1, 2, 2);
	array[0] = one;
	array[1] = two;
	WeatherForecast w(2, array);
	ASSERT_EQ(2, w.GetCsize());
	DailyForecast x = w[1];
	ASSERT_EQ(2, x.GetDate().day);
}

TEST(MethodsTest, GetTestW2)
{
	Date d{ 1, 2 }, d1{ 2, 3 };
	DailyForecast array[2], one(d, 1, 1), two(d1, 2, 2);
	array[0] = one;
	array[1] = two;
	WeatherForecast w(2, array);
	ASSERT_EQ(1, w[0].GetDate().day);
	ASSERT_EQ(2, w[0].GetDate().mount);
}

TEST(MethodsTest, SortirovkaW2)
{
	Date d{ 1, 2 }, d1{ 2, 3 };
	DailyForecast array[2], one(d, 1, 1), two(d1, 2, 2);
	array[0] = two;
	array[1] = one;
	WeatherForecast w(2, array);
	w.sortirovka();
	ASSERT_EQ(1, w[0].GetDate().day);
	ASSERT_EQ(2, w[0].GetDate().mount);
}

TEST(MethodsTest, DeleteW)
{
	Date d{ 1, 2 }, d1{ 2, 3 };
	DailyForecast array[2], one(d, 1, 1), two(d1, 2, 2);
	array[0] = one;
	array[1] = two;
	WeatherForecast w(2, array);
	w.delete_ind(0);
	ASSERT_EQ(2, w[0].GetDate().day);
	ASSERT_EQ(3, w[0].GetDate().mount);
	ASSERT_EQ(1, w.GetCsize());
}

TEST(MethodsTest, addElem)
{
	Date d{ 1, 2 }, d1{ 2, 3 }, d2{ 3, 4 };
	DailyForecast array[2], one(d, 1, 1), two(d1, 2, 2), three(d2, 3, 3);
	array[0] = one;
	array[1] = two;
	WeatherForecast w(2, array);
	w += three;
	ASSERT_EQ(3, w[2].GetDate().day);
	ASSERT_EQ(4, w[2].GetDate().mount);
	ASSERT_EQ(3, w.GetCsize());
}

TEST(ISKL, iskl_test_W)
{
	Date d1{ 45 , 5 };
	DailyForecast one(d1, 25, 120);
	WeatherForecast w(one);
	ASSERT_THROW(w[-1]; , std::invalid_argument);
}

TEST(ISKL, iskl_test1_W)
{
	Date d1{ 45 , 5 };
	DailyForecast one(d1, 25, 120);
	WeatherForecast w(one), r;
	ASSERT_THROW(w.SET(r, 1);, std::invalid_argument);
}

TEST(ISKL, iskl_test2_W)
{
	Date d1{ 12, 5 };
	DailyForecast one(d1, 10 , 120);
	WeatherForecast w(one), r;
	ASSERT_THROW(w.unification(); , std::invalid_argument);
}