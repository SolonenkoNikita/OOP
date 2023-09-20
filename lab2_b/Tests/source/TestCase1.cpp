#include <gtest/gtest.h>

#include <WeatherForecast/WeatherForecast.h>


TEST(MethodsTest, GetTest)
{
	Date d{ 1, 2 };
	DailyForecast one(d, 2, 0);
	ASSERT_EQ(1, one.GetDate().day);
}

TEST(MethodsTest, GetTest2)
{
	Date x{ 1, 1 };
	DailyForecast one(x, 2, 3, 4, weather_type::sunny, 0);
	ASSERT_EQ(weather_type::sunny, one.GetWeather());
}

TEST(MethodsTest, SetTest)
{
	Date x{ 1, 1 }, d{ 10, 1 };
	DailyForecast one(x, 2, 0);
	one.SetDate(d);
	ASSERT_EQ(10, one.GetDate().day);
}

TEST(sr, sr_test)
{
	Date xer{ 12, 1 };
	DailyForecast one(xer, 18, 19, 2, weather_type::sunny, 0);
	ASSERT_EQ(13, one.average_temperature());
}

TEST(ISKL, iskl_test1)
{
	Date o{ 1, 1 }, t{ 2, 1 };
	DailyForecast one(o, 2, 3, 4, weather_type::sunny, 0);
	DailyForecast two(t, 10, 0);
	ASSERT_THROW(two += one, std::invalid_argument);
}

TEST(ISKL, iskl_test2)
{
	Date d{ 46, 1 }, d1{ 45 , 5 }, d2{ 12, 5 };
	DailyForecast one(d, 2, 3, 4, weather_type::sunny, 0);
	ASSERT_THROW(one.SetDate(d1), std::invalid_argument);
	one.SetDate(d2);
	ASSERT_THROW(one.SetWeather(weather_type::snow);, std::invalid_argument);
}

TEST(ISKL, iskl_test3)
{
	Date d1{ 45 , 5 };
	DailyForecast one(d1, 25, 120);
	ASSERT_THROW(one.SetWeather(weather_type::cloudy);, std::invalid_argument);
}

TEST(OPER, oper_test)
{
	Date d{ 12, 1 }, d1{ 13, 1 };
	DailyForecast one(d, 25, 0);
	DailyForecast two(d1, 23, 0);
	ASSERT_EQ(std::strong_ordering::greater, two <=> one);
}  