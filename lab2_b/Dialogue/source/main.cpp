#include <iostream>
#include <WeatherForecast/WeatherForecast.h>

int main()
{
	Date one(1, 1), two(2, 1);
	DailyForecast d1(one, 1, 1), l, d;
	DailyForecast d2(two, 2, 2);
	DailyForecast d_ar1[2];
	d_ar1[0] = d1;
	d_ar1[1] = d2;
	WeatherForecast w1(2, d_ar1), w2(d2), w3;
	int number, x;
	try
	{
		while (true)
		{
			std::cout << "1. Input" << std::endl;
			std::cout << "2. Output" << std::endl;
			std::cout << "3. Sort" << std::endl;
			std::cout << "4 Unification" << std::endl;
			std::cout << "5. Delete_index" << std::endl;
			std::cout << "6. += " << std::endl;
			std::cout << "7. []" << std::endl;
			std::cout << "8. Set" << std::endl;
			std::cout << "9. Exit" << std::endl;
			number = getNum <int>(0);
			switch (number)
			{
				case 1:
					w2.input();
					break;
				case 2:
					w1.print();
					break;
				case 3:
					w1.sortirovka();
					break;
				case 4:
					w2.unification();
					break;
				case 5:
					std::cout << "Input index elem:\n";
					x = getNum <int>(0);
					w2.delete_ind(x);
					break;
				case 6:
					std::cout << "Input new DailyForecast:\n";
					l.input();
					w1 += l;
					break;
				case 7:
					std::cout << "Input index:\n";
					x = getNum <int>(0);
					d = w2[x];
					break;
				case 8:
					std::cout << "Input mount:\n";
					x = getNum <int>(1, 12);
					w3.SET(w2, x);
					break;
				case 9:
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
	catch (const std::runtime_error& e)
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