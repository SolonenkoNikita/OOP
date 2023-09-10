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
	if (data < 0 || data > 31 || morningT < -100 || morningT > 60 || dayT < -100 || dayT > 60 ||
		eveningT < -100 || eveningT > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("YES\n");
	}
	else if ((weather == "sunny" || weather == "cloudy") && precipitation != 0)
	{
		throw std::invalid_argument("YES\n");
	}
	else if (weather == "snow" && (morningT > 0 || dayT > 0 || eveningT > 0))
	{
		throw std::invalid_argument("YES\n");
	}
	this->data = data;
	this->dayT = dayT;
	this->morningT = morningT;
	this->eveningT = eveningT;
	this->weather = weather;
	this->precipitation = precipitation;
}

DailyForecast::DailyForecast(int data, double temperature, double precipitation)
{
	if (data < 0 || data > 31 || temperature < -100 || temperature > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("YES\n");
	}
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

int DailyForecast::sr_zn()
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

DailyForecast& DailyForecast::SetWeather(std::string weather)
{
	if (precipitation != 0.0 && (weather == "sunny" || weather == "cloudy" ) || 
		function(morningT, dayT, eveningT) == false && weather == "snow")
	{
		throw std::invalid_argument("Error\n");
	}
	this->weather = weather;
	return *this;
}

int DailyForecast::GetData()
{
	return data;
}

std::string DailyForecast::GetWeather()
{
	return weather;
}



void DailyForecast::print()
{
	std::cout << data << " " << dayT << " " << morningT << " " << eveningT << " " << weather << " "
		<< precipitation << std::endl;
}