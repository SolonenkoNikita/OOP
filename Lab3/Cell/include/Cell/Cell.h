#ifndef _Cell_H_
#define _Cell_H_

#include <General_Class/General_Class.h>

struct Cor
{
	int x = 0;
	int y = 0;
};

class Cell
{
private:
	Cor coordinate_;
	//General_Class* type_;
public:
	Cell() = default;
};

#endif