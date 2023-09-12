#include "prog.h"
#include <iostream>

DailyForecast::DailyForecast()
{
	data = 0;
	dayT = 0;
	morningT = 0;
	eveningT = 0;
	weather = "Musor";
	precipitation = 0;
}

DailyForecast::DailyForecast(int data, double morningT, double dayT, double eveningT,
	std::string weather, double precipitation)
{
	this->data = data;
	this->dayT = dayT;
	this->morningT = morningT;
	this->eveningT = eveningT;
	this->weather = weather;
	this->precipitation = precipitation;
}

DailyForecast::DailyForecast(int data, double temperature, double precipitation)
{
	if (temperature > 0 && precipitation == 0)
	{
		if(temperature > 20)
		{
			weather = "sunny";
		}
		else
		{
			weather = "cloudy";
		}
	}
	else if (temperature < 0)
	{
		weather = "snow";
	}
	else
	{
		weather = "rain";
	}
	this->data = data;
	this->dayT = temperature;
	this->morningT = temperature;
	this->eveningT = temperature;
	this->precipitation = precipitation;
}

double DailyForecast::sr_zn()
{
	return (dayT + morningT + eveningT) / 3;
}

DailyForecast &DailyForecast::SetDayT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	dayT = a;
	return *this;
}

DailyForecast& DailyForecast::SetEveningT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	eveningT = a;
	return *this;
}

DailyForecast& DailyForecast::SetMorningT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	morningT = a;
	return *this;
}

DailyForecast& DailyForecast::SetData(int data)
{
	if (data > 31 || data < 1)
	{
		throw std::invalid_argument("Error\n");
	}
	this->data = data;
	return *this;
}

DailyForecast& DailyForecast::SetPrecipitation(double n)
{
	if (n > 1500 || n != 0 && (weather == "sunny" || weather == "cloudy"))
	{
		throw std::invalid_argument("Error\n");
	}
	precipitation = n;
	return *this;
}

bool function(double x, double y, double z)
{
	if (x > 0 || y > 0 || z > 0)
	{
		return false;
	}
	return true;
}

bool correct(std::string str)
{
	if (str == "sunny" || str == "rain" || str == "snow" || str == "cloudy")
	{
		return true;
	}
	return false;
}

DailyForecast& DailyForecast::SetWeather(std::string weather)
{
	if (precipitation != 0.0 && (weather == "sunny" || weather == "cloudy" ) || 
		function(morningT, dayT, eveningT) == false && weather == "snow" || correct(weather) == false)
	{
		throw std::invalid_argument("Error\n");
	}
	this->weather = weather;
	return *this;
}

int DailyForecast::GetData()
{
	if (data > 31 || data < 1)
	{
		throw std::invalid_argument("");
	}
	return data;
}

std::string DailyForecast::GetWeather()
{
	if (correct(weather) == false)
	{
		throw std::invalid_argument("");
	}
	return weather;
}

double DailyForecast::GetT(int number)
{
	if (number == 1)
	{
		return morningT;
	}
	if (number == 2)
	{
		return dayT;
	}
	return eveningT;
}

double DailyForecast::GetPr()
{
	return precipitation;
}

int help(std::string str)
{
	if (str == "snow")
	{
		return 4;
	}
	if (str == "sunny")
	{
		return 1;
	}
	if (str == "rain")
	{
		return 3;
	}
	if (str == "cloudy")
	{
		return 2;
	}
}

void proverka(int data, std::string weather, double T1, double T2, double T3, double precipitation)
{
	if (data < 0 || data > 31 || T1 < -100 || T1 > 60 || T2 < -100 || T2 > 60 ||
		T3 < -100 || T3 > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("YES\n");
	}
	else if ((weather == "sunny" || weather == "cloudy") && precipitation != 0)
	{
		throw std::invalid_argument("YES\n");
	}
	else if (weather == "snow" && (T1 > 0 || T2 > 0 || T3 > 0))
	{
		throw std::invalid_argument("YES\n");
	}
}

void proverka_two(int data, double temperature, double precipitation)
{
	if (data < 0 || data > 31 || temperature < -100 || temperature > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("YES\n");
	}
}

std::string push()
{
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (std::cin.eof())
		{
			throw std::runtime_error("EOF\n");
		}
		else if (std::cin.bad())
		{
			throw std::runtime_error("Impossible bad\n");
		}
		else if (correct(str) == false)
		{
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong; repeat please!" << std::endl;
		}
		else if (correct(str) == true)
		{
			return str;
		}
	}
}

DailyForecast DailyForecast::input()
{
	std::cout << "Input number of kont" << std::endl;
	int x = getNum <int>(1, 2);
	try
	{
		std::cout << "Input data:" << std::endl;
		int d = getNum <int>(0);
		std::cout << "Input precipitation" << std::endl;
		double pr = getNum <double>(0);
		if (x == 1)
		{
			std::cout << "Input three temperature: " << std::endl;
			double T1 = getNum <double>(), T2 = getNum <double>(0), T3 = getNum<double>(0);
			std::cout << "Input weather" << std::endl;
			std::string str = push();
			proverka(d, str, T1, T2, T3, pr);
			DailyForecast a(d, T1, T2, T3, str, pr);
			return a;
		}
		if (x == 2)
		{
			std::cout << "Input temperature: " << std::endl;
			double T = getNum <double>(0);
			proverka_two(d, T, pr);
			DailyForecast a(d, T, pr);
			return a;
		}
	}
	catch (const std::invalid_argument& e)
	{
		throw;
	}
	catch (const std::runtime_error& e)
	{
		throw std::runtime_error("UPSS\n");
	}
}

DailyForecast& DailyForecast::operator+=(const DailyForecast& one)
{
	if (this->data != one.data)
	{
		throw std::invalid_argument("Another data\n");
	}
	this->data = one.data;
	this->morningT = (this->morningT + one.morningT) / 2;
	this->dayT = (this->dayT + one.dayT) / 2;
	this->eveningT = (this->eveningT + one.eveningT) / 2;
	this->precipitation = (this->precipitation + one.precipitation) / 2;
	int s1 = help(this->weather), s2 = help(one.weather);
	if(s1 < s2)
	{
		if (function(dayT, morningT, eveningT) == false && one.weather == "snow")
		{
			throw std::invalid_argument("Incorrect\n");
		}
		this->weather = one.weather;
	}
	return *this;
}

void DailyForecast::print()
{
	std::cout << data << " " << morningT << " " << dayT << " " << eveningT << " " << weather << " "
		<< precipitation << std::endl;
}