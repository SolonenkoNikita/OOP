#ifndef _Cell_H_
#define _Cell_H_

#include <vector>
#include <memory>
#include <iostream>

#include <DamageCaused/DamageCaused.h>
#include <Obstacle/Obstacle.h>

/**
* @brief struct Coordinate
* @param - coorditane x
* @param - coordinate y
*/

struct Coordinate
{
	int x = 0;

	int y = 0;

	/**
	* @brief default constructor
	*/

	Coordinate() = default;

	/**
	* @brief expicit constructor 
	* @param c - const reference by Coordinate
	*/

	explicit Coordinate(const Coordinate& c) : x(c.x), y(c.y) {};
};

class Base;

/**
* @brief class Cell
* @param coorditane_ - sruct coordinate
* @param content_ - a vector from the std namespace consisting of a pointer to a class Base
*/

class Cell
{
private:
	Coordinate coordinate_;
	std::vector<Base*> content_;

public:

	/**
	* @brief default constructor
	*/

	Cell() = default;

	/**
	* @brief this function return const reference to vector
	* @return const std::vector<Base*>&
	*/

	const std::vector<Base*>& get_content() const
	{
		return content_;
	}

	/**
	* @brief this function adds a new value to the branch
	* @param obst - reference on the Base
	*/

	void add_selection(Base& obst);

	/**
	* @brief this function remote a value to the branch
	* @param obst - reference on the Base
	*/

	void delete_selection(Base& obst);


};

#endif