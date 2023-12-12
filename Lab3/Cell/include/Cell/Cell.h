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
	int x;

	int y;

	/**
	* @brief default constructor
	*/

	Coordinate() = default;

	/**
	* @brief expicit constructor 
	* @param c - const reference by Coordinate
	*/

	Coordinate(const Coordinate& c) : x(c.x), y(c.y) {};

	Coordinate(int x, int y) : x(x), y(y) {};


	Coordinate& operator = (const Coordinate& c)
	{
		x = c.x;
		y = c.y;
		return *this;
	}

	bool operator == (const Coordinate& other) const
	{
		return x == other.x && y == other.y;
	}

	/*bool operator<(const Coordinate& other) const 
	{
		return x < other.x;
	}

	bool operator>(const Coordinate& other) const 
	{
		return x > other.x;
	}*/
};

class Direction
{
private:
	Coordinate point_;

public:

	Direction() = default;

	Direction(int x, int y) { point_ = { x, y }; }

	Direction(const Coordinate& c) : point_(c) {};

	int x() const { return point_.x; }

	int y() const { return point_.y; }

	int x() { return point_.x; }

	int y()  { return point_.y; }

	Coordinate& get_coordinate()
	{
		return point_;
	}

	const Coordinate& get_coordinate() const
	{
		return point_;
	}

	Direction operator -() const
	{
		Direction d = { -point_.x, -point_.y };
		return d;
	}

	bool operator == (const Direction& other) const
	{
		return(point_.x == other.x() && point_.y == other.y());
	}
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
	std::vector<std::shared_ptr<Base>> content_;

public:

	/**
	* @brief default constructor
	*/

	int x()
	{
		return coordinate_.x;
	}

	int y()
	{
		return coordinate_.y;
	}

	int x() const 
	{
		return coordinate_.x;
	}

	int y() const
	{
		return coordinate_.y;
	}

	Cell() = default;

	Cell(Coordinate& cr) : coordinate_(cr) {};

	Cell(int x, int y) : coordinate_(x, y) {};

	/**
	* @brief this function return const reference to vector
	* @return const std::vector<Base*>&
	*/

	const std::vector<std::shared_ptr<Base>>& get_content() const
	{
		return content_;
	}

	std::vector<std::shared_ptr<Base>>& get_content()
	{
		return content_;
	}

	/**
	* @brief this function adds a new value to the branch
	* @param obst - reference on the Base
	*/

	void add_selection(std::shared_ptr<Base> obst);

	/**
	* @brief this function remote a value to the branch
	* @param obst - reference on the Base
	*/

	void delete_selection(std::shared_ptr<Base> obst);


};

#endif