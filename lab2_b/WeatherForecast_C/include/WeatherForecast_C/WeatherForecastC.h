#ifndef _WeatherForecastC_h_
#define _WeatherForecastC_h_

#include <iostream>
#include <cstdlib>
#include <DailyForecast/DailyForecast.h>
#include <algorithm>

class WeatherForecast
{
private:
	static constexpr size_t msize = 7;
	size_t csize{ 0 };
	DailyForecast* data;
public:
	WeatherForecast() : data(new DailyForecast[msize]()) {};
	WeatherForecast(const DailyForecast&);
};

#endif