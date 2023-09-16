#include <gtest/gtest.h>

#include "prog.h"

TEST(MethodsTest, GetTest)
{
	DailyForecast one(1, 2, 0);
	ASSERT_EQ(1, one.GetDate());
	ASSERT_NE(10, one.GetDate());
	ASSERT_EQ(2, one.GetMorningT());
}

TEST(MethodsTest, GetTest2)
{
	DailyForecast one(1, 2, 3, 4, weather_type::sunny, 0);
	ASSERT_EQ(weather_type::sunny, one.GetWeather());
}

TEST(MethodsTest, SetTest)
{
	DailyForecast one(1, 2, 0);
	one.SetDate(10);
	ASSERT_EQ(10, one.GetDate());
}

TEST(sr, sr_test)
{
	DailyForecast one(12, 18, 19, 2, weather_type::sunny,  0);
	ASSERT_EQ(13, one.average_temperature());
}

TEST(ISKL, iskl_test1)
{
	DailyForecast one(1, 2, 3, 4, weather_type::sunny, 0);
	DailyForecast two(2, 10, 0);
	ASSERT_THROW(two += one, std::invalid_argument);
}

TEST(ISKL, iskl_test2)
{
	DailyForecast one(45, 2, 3, 4, weather_type::sunny, 0);
	ASSERT_THROW(one.SetDate(46), std::invalid_argument);
	one.SetDate(30);
	ASSERT_THROW(one.SetWeather(weather_type::snow); , std::invalid_argument);
}

TEST(ISKL, iskl_test3)
{
	DailyForecast one(45, 25, 120);
	ASSERT_THROW(one.SetWeather(weather_type::cloudy); , std::invalid_argument);
}

TEST(OPER, oper_test)
{
	DailyForecast one(12, 25, 0);
	DailyForecast two(13, 23, 0);
	ASSERT_EQ(std::strong_ordering::greater, two<=>one);
}