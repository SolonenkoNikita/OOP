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

/**
* @brief Конструктор первая вариация
* @param data Дата прогноза
* @param morningT Утрення температура
* @param dayT Дневная температура
* @param eveningT Вечерняя температура
* @param weather Погода
* @param precepitation Осадки
*/
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

/**
* @brief Конструктор вторая вариация
* @param data Дата прогноза
* @param temperature Температура
* @param precepitation Осадки
*/

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

/**
* @brief Метод, который возвращает среднее значение температуры
* @return Среднее значение
*/

double DailyForecast::sr_zn()
{
	return (dayT + morningT + eveningT) / 3;
}

/**
* @brief Сеттер, который меняет дневную температуру 
* @param a Новое значение темпы
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

DailyForecast &DailyForecast::SetDayT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	dayT = a;
	return *this;
}

/**
* @brief Сеттер, который меняет вечернуюю температуру
* @param a Новое значение темпы
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

DailyForecast& DailyForecast::SetEveningT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	eveningT = a;
	return *this;
}

/**
* @brief Сеттер, который меняет утреннюю температуру
* @param a Новое значение темпы
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

DailyForecast& DailyForecast::SetMorningT(double a)
{
	if (a > 0 && weather == "snow" || a < -100 || a > 60)
	{
		throw std::invalid_argument("Error\n");
	}
	morningT = a;
	return *this;
}

/**
* @brief Сеттер, который меняет дату
* @param data Новое значение темпы
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

DailyForecast& DailyForecast::SetData(int data)
{
	if (data > 31 || data < 1)
	{
		throw std::invalid_argument("Error\n");
	}
	this->data = data;
	return *this;
}

/**
* @brief Сеттер, который меняет осадки
* @param n Новое значение осадков
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

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

/**
* @brief Сеттер, который меняет погоду
* @param weather Новое значение осадков
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Ссылку на объект класса
*/

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

/**
* @brief Геттер, который возвращает дату
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Дата
*/

int DailyForecast::GetData() const
{
	if (data > 31 || data < 1)
	{
		throw std::invalid_argument("");
	}
	return data;
}

/**
* @brief Геттер, который возвращает погоду
* @throw Не корректное значение, выбросит исключение invalid_argument
* @return Погода
*/

std::string DailyForecast::GetWeather() const
{
	if (correct(weather) == false)
	{
		throw std::invalid_argument("");
	}
	return weather;
}

/**
* @brief Геттер, который возвращает температуру на выбор
* @param number номер погоды на выбор(утро, день или вечер)  
* @return Температура
*/

double DailyForecast::GetT(int number) const
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

/**
* @brief Геттер, который возвращает осадки
* @return Осадки
*/

double DailyForecast::GetPr() const
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

/**
* @brief Функция проверки данных для первого конструктора, чтобы не выбрасывать исключение внутри него
* @param data дата
* @param weather погода
* @param T1 утренняя температра 
* @param T2 дневная температура
* @param T3 вечерняя температура
* @precipication осадки
* @throw Некорректное значение
*/

void proverka(int data, std::string weather, double T1, double T2, double T3, double precipitation)
{
	if (data < 0 || data > 31 || T1 < -100 || T1 > 60 || T2 < -100 || T2 > 60 ||
		T3 < -100 || T3 > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("Invalid argument\n");
	}
	else if ((weather == "sunny" || weather == "cloudy") && precipitation != 0)
	{
		throw std::invalid_argument("Invalid argument\n");
	}
	else if (weather == "snow" && (T1 > 0 || T2 > 0 || T3 > 0))
	{
		throw std::invalid_argument("Invalid argument\n");
	}
}

void proverka_two(int data, double temperature, double precipitation)
{
	if (data < 1 || data > 31 || temperature < -100 || temperature > 60 || precipitation > 1500)
	{
		throw std::invalid_argument("Error\n");
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

/**
* @brief Метод ввода, в котором вызывается один из конструкторов на выбор
* @throw Некорректное значение
* @throw Ошибка времени выполнения
* @return Экзмепляр класса
*/

DailyForecast DailyForecast::input()
{
	std::cout << "Input number of kont" << std::endl;
	int x = getNum <int>(1, 2);
	try
	{
		std::cout << "Input data:" << std::endl;
		int d = getNum <int>(1, 31);
		std::cout << "Input precipitation" << std::endl;
		double pr = getNum <double>(0);
		if (x == 1)
		{
			std::cout << "Input three temperature: " << std::endl;
			double T1 = getNum <double>(-100, 60), T2 = getNum <double>(-100, 60), T3 = getNum<double>(-100, 60);
			std::cout << "Input weather" << std::endl;
			std::string str = push();
			proverka(d, str, T1, T2, T3, pr);
			DailyForecast a(d, T1, T2, T3, str, pr);
			return a;
		}
		if (x == 2)
		{
			std::cout << "Input temperature: " << std::endl;
			double T = getNum <double>(-100, 60);
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

/**
* @brief Перегрузка оператора +=
* @param one Константная ссылка
* @throw Некорректное значение
* @throw Некорректное значение 
* @return Ссылку на экзмепляр класса
*/


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

/**
* @brief Перегрузка оператора <=>
* @param one Константная ссылка
* @return Значение типа std::strong_ordering 
*/

std::strong_ordering DailyForecast::operator<=>(const DailyForecast& one) const
{
	if (data < one.data)
	{
		return std::strong_ordering::less;
	}
	else if(data > one.data)
	{
		return std::strong_ordering::greater;
	}
	else
	{
		return std::strong_ordering::equal;
	}
}

/**
* @brief Метод вывода
*/

void DailyForecast::print()
{
	std::cout << data << " " << morningT << " " << dayT << " " << eveningT << " " << weather << " "
		<< precipitation << std::endl;
}