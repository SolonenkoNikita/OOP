#include <iostream>
#include "WeatherForecast/WeatherForecast.h"
#include <algorithm>
#include <compare>
#include <stack>

WeatherForecast::WeatherForecast(const DailyForecast& one)
{
	data[csize] = one;
	csize++;
}

WeatherForecast::WeatherForecast(size_t count, DailyForecast one[])
{
	if (count > msize)
	{
		throw std::runtime_error("Error\n");
	}
	std::copy(one, one + count, data);
	csize += count;
}

/*WeatherForecast& WeatherForecast::input()
{
	std::cout << "How many number do you want to input?" << std::endl;
	int x = getNum <int>(0);
	if (x > msize)
	{
		throw std::runtime_error("Overflow\n");
	}
	for (int i = 0; i < x; i++)
	{
		data[i].input();
	}
	csize += x;
	return *this;
}*/

std::istream& operator>>(std::istream& s, WeatherForecast& w)
{
	int x;
	s >> x;
	if (s.good())
	{
		if (x < w.msize)
		{
			for (int i = 0; i < x; i++)
			{
				s >> w.data[i];
			}
			w.csize += x;
		}
		else
		{
			s.setstate(std::ios::failbit);
		}
	}
	return s;
}

std::ostream& operator<<(std::ostream& s, const WeatherForecast& w)
{
	for (int i = 0; i < w.csize; i++)
	{
		for (int i = 0; i < w.csize; i++)
		{
			s << w.data[i];
			s << std::endl;
		}
		return s;
	}
}

WeatherForecast& WeatherForecast::operator+=(const DailyForecast& one)
{
	if (csize >= msize)
	{
		throw std::runtime_error("Error\n");
	}
	data[csize] = one;
	csize++;
	return *this;
}

DailyForecast& WeatherForecast::operator[](int index)
{ 
	if (index < 0 || index >= msize || index >= csize)
	{
		throw std::invalid_argument("Invalid\n");
	}
	return data[index];
}

bool comp(const DailyForecast& a, const DailyForecast& b)
{
	return a.GetDate().day < b.GetDate().day;
}

void WeatherForecast::sortirovka()
{
	std::sort(data, data + csize, comp);
}

void WeatherForecast::delete_ind(int index)
{
	for (int i = index; i < csize -  1; i++)
	{
		data[i] = data[i + 1];
	}
	csize--;
}

void WeatherForecast::SET(WeatherForecast& w, int mount)
{
	if (this->csize != 0)
	{
		throw std::invalid_argument("This WeatherForecast is not emty\n");
	}
	for (int i = 0; i < w.csize; i++)
	{
		if (w.data[i].GetDate().mount == mount)
		{
			this->data[csize] = w.data[i];
			this->csize++;
		}
	}
	if (this->csize != 0)
	{
		sortirovka();
	}
}

void WeatherForecast::unification()
{
	if (csize <= 1)
	{
		throw std::invalid_argument("Error\n");
	}
	std::stack <int> st;
	for (int i = 0; i < csize - 1; i++)
	{
		for (int j = i + 1; j < csize; j++)
		{
			if ((data[i] <=> data[j]) == std::strong_ordering::equal)
			{
				st.push(j);
			}
		}
	}
	while (!st.empty())
	{
		delete_ind(st.top());
		st.pop();
	}
}