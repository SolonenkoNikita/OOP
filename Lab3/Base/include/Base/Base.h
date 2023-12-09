#ifndef _Base_H_
#define _Base_H_

/**
* @brief Abstract Class Base, that the class from which are inherited DamageCaused and Obstacle
*/

class Base
{
private:
	size_t id_;
public:

	size_t get_id()
	{
		return id_;
	}

	Base& set_id(size_t id) 
	{
		id_ = id;
		return *this;
	}

	/**
	* @brief defaut virtual destructor
	*/

	virtual ~Base() = default;

};

#endif