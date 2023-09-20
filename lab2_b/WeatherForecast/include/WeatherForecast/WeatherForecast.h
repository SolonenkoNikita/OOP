#ifndef _WeatherForecast_h_
#define _WeatherForecast_h_

#include <iostream>
#include <cstdlib>
#include <DailyForecast/DailyForecast.h>
#include <algorithm>

class WeatherForecast
{
private:
	static constexpr size_t msize = 7;
	size_t csize{ 0 };
	DailyForecast data[msize];
public:
	WeatherForecast();
	WeatherForecast(const DailyForecast&);
	size_t GetCsize() const { return csize; };
	WeatherForecast(size_t, DailyForecast[]);
	WeatherForecast& input();
	WeatherForecast& operator += (const DailyForecast&);
	DailyForecast& operator[](int);
	void sortirovka();
	void delete_ind(int);
	void print() const;
	void SET(WeatherForecast&, int);
	void unification();
};

#endif