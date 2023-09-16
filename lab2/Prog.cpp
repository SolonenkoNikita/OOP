#include <iostream>
#include "prog.h"

DailyForecast::DailyForecast(int d, double mT, double dT, double eT,
	weather_type w, double p) : date(d), morningT(mT), dayT(dT), eveningT(eT),
								precipitation(p), weather(w)
{
}

DailyForecast::DailyForecast(int d, double temperature, double p) :date(d), 
				morningT(temperature), dayT(temperature), eveningT(temperature),
	precipitation(p)
{
	if (temperature > 0 && p == 0)
	{
		if (temperature > 20)
		{
			weather = weather_type::sunny;
		}
		else
		{
			weather = weather_type::cloudy;
		}
	}
	else if (temperature < 0)
	{
		weather = weather_type::snow;
	}
	else
	{
		weather = weather_type::rain;
	}
}

double DailyForecast::average_temperature()
{
	return (dayT + morningT + eveningT) / 3;
}

void DailyForecast::check_temperature_snow(double temperature)
{
	if (temperature > 0 && weather == weather_type::snow ||
		temperature < minTemperature || temperature > maxTemperature)
	{
		throw std::invalid_argument("Error\n");
	}
}

DailyForecast& DailyForecast::SetDayT(double a)
{
	DailyForecast::check_temperature_snow(a);
	dayT = a;
	return *this;
}

DailyForecast& DailyForecast::SetEveningT(double a)
{
	DailyForecast::check_temperature_snow(a);
	eveningT = a;
	return *this;
}

DailyForecast& DailyForecast::SetMorningT(double a)
{
	DailyForecast::check_temperature_snow(a);
	morningT = a;
	return *this;
}

void check_date(int date)
{
	if (date > 31 || date < 1)
	{
		throw std::invalid_argument("Error\n");
	}
}

DailyForecast& DailyForecast::SetDate(int date)
{
	check_date(date);
	this->date = date;
	return *this;
}
void DailyForecast::check_precipitation(double n)
{
	if (n > maxPrecipitation || n != 0 && 
		(weather == weather_type::sunny ||weather == weather_type::cloudy))
	{
		throw std::invalid_argument("Error\n");
	}
}

DailyForecast& DailyForecast::SetPrecipitation(double n)
{
	check_precipitation(n);
	precipitation = n;
	return *this;
}

DailyForecast& DailyForecast::SetWeather(weather_type weather)
{
	if (precipitation != 0 && (weather == weather_type::sunny || weather == weather_type::cloudy)
		|| weather_type::snow == weather && 
		(dayT > 0 || morningT > 0 || eveningT > 0))
	{
		throw std::invalid_argument("Error\n");
	}
	this->weather = weather;
	return *this;
}

int DailyForecast::GetDate() const
{
	return date;
}

weather_type DailyForecast::GetWeather() const
{
	return weather;
}

double DailyForecast::GetMorningT() const
{
	return morningT;
}

double DailyForecast::GetDayT() const
{
	return dayT;
}

double DailyForecast::GetEveningT() const
{
	return eveningT;
}

double DailyForecast::GetPr() const
{
	return precipitation;
}

weather_type help(int number)
{
	if (number == 1)
	{
		return weather_type::sunny;
	}
	else if (number == 2)
	{
		return weather_type::cloudy;
	}
	else if (number == 3)
	{
		return weather_type::rain;
	}
	else
	{
		return weather_type::snow;
	}
}

DailyForecast& DailyForecast::input()
{
	std::cout << "Input date :" << std::endl;
	date = getNum <int>(1, 31);
	std::cout << "Input temperature: " << std::endl;
	double T = getNum <double>(-100, 60);
	eveningT = dayT = morningT = T;
	std::cout << "Input precepition:" << std::endl;
	precipitation = getNum <double>(0, 1500);
	std::cout << "Input weather: " << std::endl <<
		"If you want sunny - 1, clody - 2, rain - 3, snow - 4" << std::endl;
	int number = getNum <int>(1, 4);
	weather = help(number);
	return *this;
}

DailyForecast& DailyForecast::operator+=(const DailyForecast& one)
{
	if (this->date != one.date)
	{
		throw std::invalid_argument("Another data\n");
	}
	this->date = one.date;
	this->morningT = (this->morningT + one.morningT) / 2;
	this->dayT = (this->dayT + one.dayT) / 2;
	this->eveningT = (this->eveningT + one.eveningT) / 2;
	this->precipitation = (this->precipitation + one.precipitation) / 2;
	if (this->weather < one.weather)
	{
		this->weather = one.weather;
	}
	check_precipitation(this->precipitation);
	return *this;
}

std::strong_ordering DailyForecast::operator<=>(const DailyForecast& one) const
{
	if (date < one.date)
	{
		return std::strong_ordering::less;
	}
	else if (date > one.date)
	{
		return std::strong_ordering::greater;
	}
	else
	{
		return std::strong_ordering::equal;
	}
}

void print_weather(weather_type a)
{
	if (a == weather_type::sunny)
	{
		std::cout << "sunny";
	}
	else if (a == weather_type::cloudy)
	{
		std::cout << "cloudy";
	}
	else if (a == weather_type::rain)
	{
		std::cout << "rain";
	}
	else
	{
		std::cout << "snow";
	}
}

void DailyForecast::print()
{
	std::cout << date << " " << morningT << " " << dayT << " " << eveningT << " "; 
	print_weather(weather);
	std::cout << " " << precipitation << std::endl;
}