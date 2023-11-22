#ifndef _Director_H_
#define _Director_H_

#include <Creator_Creature/Creator_Creature.h>
#include <Creature/Creature.h>

/**
* @brief abstact class Director, that implements the logic of getting information about creature 
*/

class Director
{
public:

	/**
	* @brief pure virtual function that creates a creature
	* @param - reference to the class Creator_Creature
	* @param - const reference to the std::string 
	*/

	virtual Creature make(Creator_Creature&, const std::string&) = 0;

	/**
	* @brief default virtual destructor 
	*/

	virtual ~Director() = default;
};

#endif