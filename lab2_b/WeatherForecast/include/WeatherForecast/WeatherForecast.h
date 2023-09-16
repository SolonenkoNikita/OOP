#ifndef _WeatherForecast_h_
#define _WeatherForecast_h_

#include <iostream>
#include <cstdlib>
#include "DailyForecast/DailyForecast/DailyForecast.h

class WeatherForecast
{
private:
	DailyForecast* data;
	size_t size;
public:
	WeatherForecast();
	void print();
};

#endif