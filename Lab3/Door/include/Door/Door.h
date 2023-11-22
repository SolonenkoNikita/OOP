#ifndef _Door_H_
#define _Door_H_

#include <Obstacle/Obstacle.h>
#include <DamageCaused/DamageCaused.h>
#include <Cell/Cell.h>

#include <iostream>

/**
* @brief class Door is responsive obstacle
* @param closed_ - a boolean value that displays whether the door is closed or not 
*/

class Door : public Responsive, public DamageCaused
{
private:
	bool closed_;
public:
	void print()
	{
		std::cout.setf(std::cout.boolalpha);
		std::cout << closed_ << '\n';
	}
public:
	/**
	* @brief constructor
	*/
	Door() : closed_(true) {}

	/**
	* @brief the function that closes the door
	* @return reference on the class Door
	*/

	Door& close();

	/**
	* @brief override function to take damage
	* @param damag - damage
	*/

	void get_damage(size_t damag) override;

	/**
	* @brief override function to checking dead or not
	* @return bool
	*/

	bool is_died() const override;

	/**
	* @brief override function to die
	* @param - reference on the cell
	*/

	void die(Cell&) override;
	
	void revival(Cell&) override;

	/**
	* @brief override function that checks whether a solid is solid or not
	* @return bool
	*/

	bool is_hard() const override;

	/**
	* @brief the method checks whether the door is open or not
	* @return reference on the class Door
	*/

	bool is_open() const;

	/**
	* @brief the function that openes the door
	* @return reference on the class Door
	*/

	Door& open();

	/**
	* @brief this method using open
	*/

	void reaction(Cell&) override;
};

#endif