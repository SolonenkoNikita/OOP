#ifndef _DailyForecast_h_
#define _DailyForecast_h_

#include <iostream>
#include <string>
#include <climits>
#include <compare>

struct Date
{
	int day;
	int mount;
};

enum class weather_type
{
	sunny,
	cloudy,
	rain,
	snow
};

class DailyForecast
{
private:
	static constexpr double maxPrecipitation = 1500;
	static constexpr double minTemperature = -100;
	static constexpr double maxTemperature = 60;
	Date date;
	double morningT;
	double dayT;
	double eveningT;
	weather_type weather;
	double precipitation;
public:
	DailyForecast();
	DailyForecast(Date, double, double, double, weather_type, double);
	DailyForecast(Date, double, double);
	void check_temperature_snow(double);
	void check_precipitation(double);
	DailyForecast& SetDayT(double);
	DailyForecast& SetMorningT(double);
	DailyForecast& SetEveningT(double);
	DailyForecast& SetDate(Date);
	DailyForecast& SetPrecipitation(double);
	DailyForecast& SetWeather(weather_type);
	Date GetDate() const;
	weather_type GetWeather()const;
	double GetEveningT() const;
	double GetDayT() const;
	double GetMorningT() const;
	double GetPr() const;
	double average_temperature();
	DailyForecast& input();
	DailyForecast& operator += (const DailyForecast&);
	DailyForecast& operator = (const DailyForecast&);
	std::strong_ordering operator <=>(const DailyForecast&) const;
	void print();
};

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
	T number;
	while (true)
	{
		std::cin >> number;
		if (std::cin.eof())
		{
			throw std::runtime_error("It is EOF, sorry\n");
		}
		else if (std::cin.bad())
		{
			throw std::runtime_error("WTF?!\n");
		}
		else if (std::cin.fail() || number < min || number > max)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong; repeat please!" << std::endl;
		}
		else return number;
	}
}

#endif 