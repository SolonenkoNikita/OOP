#include <iostream>
#include "matrix.h"

int main()
{
	Matrix matr;
	try
	{
		matr = input();
		std::cout << "The begin matrix:" << std::endl;
		output(matr);
		Matrix m = function(matr);
		std::cout << std::endl << "Result matrix " << std::endl;
		output(m);
		clearn(matr);
		clearn(m);
	}
	catch(const std::bad_alloc &ba)
       	{ 
        	std::cerr << "Not enough memory" << std::endl;
        	clearn(matr);
        	return 1;
    	}
    	catch(const std::exception &e)
       	{ 
        	std::cerr << e.what() << std::endl;
        	clearn(matr);
        	return 1;
    	}
	return 0;
}

