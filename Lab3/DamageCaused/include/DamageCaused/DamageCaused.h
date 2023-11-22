#ifndef _DamageCaused_H_
#define _DamageCaused_H_

#include <Base/Base.h>

class Cell;

/**
* @brief Abstract Class DamageCaused, that implements taking damage, death, revival
*/

class DamageCaused : virtual public Base
{
public:

	/**
	* @brief pure virtual function to take damage
	* @param damag - damage
	*/

	virtual void get_damage(size_t damag) = 0;

	//virtual void kill(Cell&) = 0;

	/**
	* @brief pure virtual function to checking dead or not
	* @return bool
	*/

	virtual bool is_died() const = 0; 

	/**
	* @brief pure virtual function to die
	* @param - reference on the cell
	*/

	virtual void die(Cell&) = 0;

	virtual void revival(Cell&) = 0;

	/**
	* @brief default virtual destructor
	*/

	virtual ~DamageCaused() = default;
};

#endif