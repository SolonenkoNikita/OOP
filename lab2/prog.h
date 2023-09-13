#ifndef _proh_h_
#define _prog_h_

#include <iostream>
#include <string>
#include <climits>
#include <compare>

/**
* @brief ����� ����������� �������� ������
*/

class DailyForecast
{
private:
	//! ���� �������� ������
	int data;
	//! ����������� �����
	double morningT;
	//! ����������� ����
	double dayT;
	//! �����������  ������� 
	double eveningT;
	//! ������ 
	std::string weather;
	//! ������
	double precipitation;
public:
	/**
	* @brief ����������� �� ��������� 
	*/
	DailyForecast();
	/**
	* @brief ����������� ������ �������� 
	*/
	DailyForecast(int, double, double, double, std::string, double);
	/**
	* @brief ����������� ������ ��������
	*/
	DailyForecast(int, double, double);
	/**
	* @brief ������, ������� ������ ������ ����
	*/
	DailyForecast& SetDayT(double);
	/**
	* @brief������, ������� ������ ������ �����
	*/
	DailyForecast& SetMorningT(double);
	/**
	* @brief ������, ������� ������ ������ �������
	*/
	DailyForecast& SetEveningT(double);
	/**
	* @brief ������, ������� ������ ����
	*/
	DailyForecast& SetData(int);
	/**
	* @brief ������, ������� ������ ������
	*/
	DailyForecast& SetPrecipitation(double);
	/**
	* @brief ������, ������� ������ ������
	*/
	DailyForecast& SetWeather(std::string);
	/**
	* @brief ������, ������� ���������� ����
	*/
	int GetData() const;
	/**
	* @brief ������, ������� ���������� ������
	*/
	std::string GetWeather()const;
	/**
	* @brief ������, ������� ���������� ������ �� �����
	*/
	double GetT (int) const;
	/**
	* @brief ������, ������� ���������� ������
	*/
	double GetPr() const;
	/**
	* @brief �����, ������� ���������� ������� ����������� 
	*/
	double sr_zn();
	/**
	* @brief ����� �����, � ������� ���������� ���� �� ������������� �� �����
	*/
	static DailyForecast input();
	/**
	* @brief  ���������� ��������� +=
	*/
	DailyForecast& operator += (const DailyForecast&);
	/**
	* @brief  ���������� ��������� <=>
	*/
	std::strong_ordering operator <=>(const DailyForecast&) const;
	/**
	* @brief ����� ������
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