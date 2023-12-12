#ifndef _Goblin_HPP_
#define _Goblin_HPP_

#include <DirectorForFile/DirectorForFile.h>
#include <TableWithAbility/TableWithAbility.h>
#include <TakeDamage/TakeDamage.h>
/**
* @brief class Orc - a creature instance
*/

class Goblin
{
public:

	/**
	* @brief the method that creates the creature
	* @param d - reference on the class DirectorForFile
	* @param cr - reference on the class Creator_Creature
	* @return class Creature
	*/

	Creature make_goblin(DirectorForFile& d, Creator_Creature& cr);

};

#endif