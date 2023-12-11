#ifndef _Essence_H_
#define _Essence_H_

#include <Obstacle/Obstacle.h>
#include <Cell/Cell.h>

/**
* @brief class Essence - a class inherited from an obstacle
*/

class Essence : public Obstacle
{
public:

	Essence()
	{
		set_id(10);
	}

	/**
	* @brief override function that checks whether a solid is solid or not
	* @return bool
	*/

	bool is_hard() const override;

};

#endif