#ifndef _proh_h_
#define _prog_h_

#include <iostream>
#include <string>
#include <climits>
#include <compare>

/**
* @brief Класс ежедневного проггоза погоды
*/

class DailyForecast
{
private:
	//! Дата прогноза погоды
	int data;
	//! Температура утром
	double morningT;
	//! Температура днем
	double dayT;
	//! Температура  вечером 
	double eveningT;
	//! Погода 
	std::string weather;
	//! Осадки
	double precipitation;
public:
	/**
	* @brief Конструктор по умолчанию 
	*/
	DailyForecast();
	/**
	* @brief Конструктор первая вариация 
	*/
	DailyForecast(int, double, double, double, std::string, double);
	/**
	* @brief Конструктор вторая вариация
	*/
	DailyForecast(int, double, double);
	/**
	* @brief Сеттер, который меняет погоду днем
	*/
	DailyForecast& SetDayT(double);
	/**
	* @briefСеттер, который меняет погоду утром
	*/
	DailyForecast& SetMorningT(double);
	/**
	* @brief Сеттер, который меняет погоду вечером
	*/
	DailyForecast& SetEveningT(double);
	/**
	* @brief Сеттер, который меняет дату
	*/
	DailyForecast& SetData(int);
	/**
	* @brief Сеттер, который меняет осадки
	*/
	DailyForecast& SetPrecipitation(double);
	/**
	* @brief Сеттер, который меняет погоду
	*/
	DailyForecast& SetWeather(std::string);
	/**
	* @brief Геттер, который возвращает дату
	*/
	int GetData() const;
	/**
	* @brief Геттер, который возвращает погоду
	*/
	std::string GetWeather()const;
	/**
	* @brief Геттер, который возвращает погоду на выбор
	*/
	double GetT (int) const;
	/**
	* @brief Геттер, который возвращает осадки
	*/
	double GetPr() const;
	/**
	* @brief Метод, который возвращает среднюю температуру 
	*/
	double sr_zn();
	/**
	* @brief Метод ввода, в котором вызывается один из конструкторов на выбор
	*/
	static DailyForecast input();
	/**
	* @brief  Перегрузка оператора +=
	*/
	DailyForecast& operator += (const DailyForecast&);
	/**
	* @brief  Перегрузка оператора <=>
	*/
	std::strong_ordering operator <=>(const DailyForecast&) const;
	/**
	* @brief Метод вывода
	*/
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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong; repeat please!" << std::endl;
		}
		else return number;
	}
}

std::string push();

#endif