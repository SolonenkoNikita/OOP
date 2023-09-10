#include <iostream>
#include "prog.h"

int main()
{
	DailyForecast one(30, -5, -6, -7, "snow", 12);
	one.print();
	std::cout << std::endl;
	return 0;
}