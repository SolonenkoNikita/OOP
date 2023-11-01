#include "Golem/Golem.h"
#include <iostream>
#include <ctime>

bool Golem::is_died() const 
{
	return characteristics_.get_meaning(Atrributes_Names::current_health_) < 0 ? true : false;
}

int Golem::random() const
{
	return rand() % 3 + 1;
}

void Golem::die(Cell& cell)
{

}

void Golem::get_damage(size_t damag)
{

}

void Golem::revival(Cell& cell)
{

}