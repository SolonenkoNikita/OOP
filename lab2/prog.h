#ifndef _proh_h_
#define _prog_h_

#include <iostream>
#include <string>
#include <climits>

class DailyForecast
{
private:
	int data;
	double morningT;
	double dayT;
	double eveningT;
	std::string weather;
	double precipitation;
public:
	DailyForecast();
	DailyForecast(int, double, double, double, std::string, double);
	DailyForecast(int, double, double);
	DailyForecast& SetDayT(double);
	DailyForecast& SetMorningT(double);
	DailyForecast& SetEveningT(double);
	DailyForecast& SetData(int);
	DailyForecast& SetPrecipitation(double);
	DailyForecast& SetWeather(std::string);
	int GetData();
	std::string GetWeather();
	double GetT(int);
	double GetPr();
	double sr_zn();
	static DailyForecast input();
	DailyForecast& operator += (const DailyForecast&);
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
			std::cin.clear(); // очищаем флаги состояния потока
			   // игнорируем все символы до конца строки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong; repeat please!" << std::endl;
		}
		else return number;
	}
}

std::string push();

#endif