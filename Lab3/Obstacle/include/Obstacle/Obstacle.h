#ifndef _Obstacle_H_
#define _Obstacle_H_

#include <Base/Base.h>
#include <Cell/Cell.h>

/**
* @brief abstract class Obstacle a class that is inherited from class Base
*/

class Obstacle : virtual public Base
{
public:

	/**
	* @brief pure virtual function that checks whether a solid is solid or not
	* @return bool
	*/

	virtual bool is_hard() const = 0;

	/**
	* @brief default virtual destructor
	*/

	virtual ~Obstacle() = default;
};

class Responsive : public Obstacle
{
public:

	/**
	* @brief pure virtual fucntion, that expressing some reaction
	* @param - reference on the class Cell from reaction
	*/

	virtual void reaction(Cell&) = 0;

	/**
	* @brief virtual destructor
	*/

	virtual ~Responsive() = default;
};
#endif