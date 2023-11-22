#ifndef _DirectorForFile_H_
#define _DirectorForFile_H_

#include <Director/Director.h>

/**
* @brief the inheritor of the director class, which takes information about the creature from a text file
*/

class DirectorForFile : public Director
{
public:

	/**
	* @brief override function that creates a creature
	* @param - reference to the class Creator_Creature
	* @param - const reference to the std::string
	*/

	Creature make(Creator_Creature&, const std::string&) override;

};

#endif