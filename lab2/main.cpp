#include <iostream>
#include "prog.h"
#include <gtest/gtest.h>

int main()
{
	::testing::InitGoogleTest();
	DailyForecast one, two;
	int number, x;
	try
	{
		while (true)
		{
			std::cout << "1. Input" << std::endl;
			std::cout << "2. Output" << std::endl;
			std::cout << "3. Unification" << std::endl;
			std::cout << "4. Sr_zn" <<std::endl;
			std::cout << "5. Setters" << std::endl;
			std::cout << "6. Test" << std::endl;
			std::cout << "7. Exit" << std::endl;
			number = getNum <int>(0);
			switch (number)
			{
			case 1:
				std::cout << "Input number of object:" << std::endl;
				x = getNum <int>(1, 2);
				if (x == 1) one = DailyForecast::input();
				else if (x == 2) two = DailyForecast::input();
				break;
			case 2:
				std::cout << "Input number of dailyForecast:" << std::endl;
				x = getNum <int>(1, 2);
				if (x == 1) one.print();
				else if (x == 2)  two.print();
				break;
			case 3:
				one += two;
				break;
			case 4:
				std::cout << "Input number of object" << std::endl;
				x = getNum <int>(1, 2);
				double num;
				if (x == 1) num = one.sr_zn();
				else if (x == 2)  num = two.sr_zn();
				std::cout << "sr_zn = " << num << std::endl;
				break;
			case 5:
				std::cout << "Input number of set:" << std::endl;
				x = getNum <int>(1, 6);
				if (x == 1)
				{
					std::cout << "Input new data:" << std::endl;
					x = getNum <int>(0);
					one.SetData(x);
					one.print();
				}
				else if (x == 2)
				{
					std::cout << "Input new weather:" << std::endl;
					std::string str = push();
					one.SetWeather(str);
					one.print();
				}
				break;
			case 6:
				RUN_ALL_TESTS();
				break;
			case 7:
				return 0;
			default:
				std::cout << "No such point\n";
			}
		}
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		return 1;
	}
	return 0;
}