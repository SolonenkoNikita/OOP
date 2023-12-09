#ifndef _Lava_H_
#define _Lava_H_

#include <Cell/Cell.h>
#include <DamageCaused/DamageCaused.h>

/**
* @brief class Lava  that is inherited from Obstacle
*/

class Lava : public Responsive
{

private:
	size_t damage_;

public:

	Lava(size_t damage) : damage_(damage)
	{
		set_id(3);
	}

	/**
	* @brief override function that checks whether a solid is solid or not
	* @return bool
	*/

	bool is_hard() const override;

	/**
	* @brief override function, that expressing some reaction
	* @param - reference on the class Cell from reaction
	*/

	void reaction(Cell& cell) override;
};

#endif