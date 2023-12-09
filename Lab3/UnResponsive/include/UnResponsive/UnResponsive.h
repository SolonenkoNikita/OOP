#ifndef _UnResponsive_H_
#define _UnResponsive_H_

#include <Obstacle/Obstacle.h>

/**
* @brief class Wall that is inherited from Obstacle
*/

class Wall : public Obstacle
{
public:

	Wall();

	/**
	* @brief override function that checks whether a solid is solid or not
	* @return bool
	*/

	bool is_hard() const override;
};

class Floor: public Obstacle
{
public:

	Floor();

	/**
	* @brief override function that checks whether a solid is solid or not
	* @return bool
	*/

	bool is_hard() const override;
};

#endif