#ifndef _Necromancer_H_
#define _Necromancer_H_

#include <DirectorForFile/DirectorForFile.h>
#include <OpenDoor/OpenDoor.h>
#include <Desiccation/Desiccation.h>
#include <Curse/Curse.h>
#include <Necromancy/Necromancy.h>

/**
* @brief class Necromancer - a creature instance
*/

class Necromancer
{
public:

	/**
	* @brief the method that creates the creature
	* @param d - reference on the class DirectorForFile
	* @param cr - reference on the class Creator_Creature
	* @return class Creature 
	*/

	Creature make_necromancer(DirectorForFile& d, Creator_Creature& cr);

};

#endif