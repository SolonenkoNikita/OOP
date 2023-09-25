#ifndef _WeatherForecast_h_
#define _WeatherForecast_h_

#include <iostream>
#include <cstdlib>
#include <DailyForecast/DailyForecast.h>
#include <algorithm>


/**
* @brief Class WeatherForecast
* @param msize - max size by data
* @param csize - current size
* @param data - array with DailyForecast
*/
class WeatherForecast
{
private:
	static constexpr size_t msize = 7;
	size_t csize{ 0 };
	DailyForecast data[msize];
public:
	/**
	* @brief costructor default
	*/
	WeatherForecast() = default;
	/**
	* @brief costructor with one DailyForecast
	* @param  - const &
	*/
	WeatherForecast(const DailyForecast&);
	/**
	*@brief It is function Getter with one DailyForecast
	*@return csize - current size
	*/
	size_t GetCsize() const { return csize; };
	/**
	* @brief costructor with one DailyForecast
	* @param - size by type size_t
	* @param  - const array []
	*/
	WeatherForecast(size_t, DailyForecast[]);
	//WeatherForecast& input();
	/**
	* @brief friend operator >> 
	* @param - std::istream& - input
	* @param  -  & on my type
	*/
	friend std::istream& operator>>(std::istream&, WeatherForecast&);
	/**
	* @brief WeatherForecast& operator += add new param in data
	* @param - new param
	* @return *this
	*/
	WeatherForecast& operator += (const DailyForecast&);
	/**
	* @brief function - return elem by this index
	* @param - index
	* @return param about this index
	*/
	DailyForecast& operator[](int);
	/**
	* @brief function sort
	*/
	void sortirovka();
	/**
	* @brief function - delete element by this index 
	* @param - index
	*/
	void delete_ind(int);
	/**
	* @brief friend operator <<
	* @param - std::istream& - otput
	* @param  -  const & on my type
	*/
	friend std::ostream& operator<<(std::ostream&, const WeatherForecast&);
	/**
	* @brief set - setting
	* @param - mount
	*/
	void SET(WeatherForecast&, int);
	void unification();
};

#endif