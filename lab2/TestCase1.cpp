#include <gtest/gtest.h>

#include "prog.h"

TEST(MethodsTest, GetTest)
{
	DailyForecast one(1, 2, 0);
	ASSERT_EQ(1, one.GetData());
	ASSERT_NE(10, one.GetData());
	ASSERT_EQ(2, one.GetT(3));
}

TEST(MethodsTest, GetTest2)
{
	DailyForecast one(1, 2, 3, 4, "sunny", 0);
	ASSERT_EQ("sunny", one.GetWeather());
}

TEST(MethodsTest, SetTest)
{
	DailyForecast one;
	one.SetData(10);
	ASSERT_EQ(10, one.GetData());
}

TEST(ISKL, iskl_test1)
{
	DailyForecast one(1, 2, 3, 4, "sunny", 0);
	DailyForecast two(2, 10, 0);
	ASSERT_THROW(two += one, std::invalid_argument);
}

TEST(ISKL, iskl_test2)
{
	DailyForecast one(45, 2, 3, 4, "sunny", 0);
	ASSERT_THROW(one.GetData(), std::invalid_argument);
	ASSERT_THROW(one.SetData(46), std::invalid_argument);
	ASSERT_THROW(one.SetWeather("nub"), std::invalid_argument);
	one.SetData(30);
	ASSERT_THROW(one.SetWeather("snow"); , std::invalid_argument);
}

TEST(ISKL, iskl_test3)
{
	DailyForecast one(45, 25, 120);
	ASSERT_THROW(one.SetWeather("sunny"); , std::invalid_argument);
}