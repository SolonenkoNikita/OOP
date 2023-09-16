#include <iostream>
#include "WeatherForecast/WeatherForecast.h"

WeatherForecast::WeatherForecast()
{
	data = nullptr;
	size = 0;
}

WeatherForecast::WeatherForecast(int count, DailyForecast* array)
{
	data = new[count]();
	size = count;
	for (int i = 0; i < size; i++)
	{
		data[i] = array[i];
	}
}

WeatherForecast::WeatherForecast(int count)
{
	data = new DailyForecast();
}

void WeatherForecast::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i].print() << std::endl;
	}
}