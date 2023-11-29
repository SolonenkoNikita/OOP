#ifndef _Necromancer_H_
#define _Necromancer_H_

#include <DirectorForFile/DirectorForFile.h>
#include <OpenDoor/OpenDoor.h>
#include <Desiccation/Desiccation.h>
#include <Curse/Curse.h>
#include <Necromancy/Necromancy.h>
#include <Skeleton/Skeleton.h>
#include <Ghost/Ghost.h>
#include <Zombie/Zombie.h>
#include <Morphism/Morphism.h>
#include <TakeDamage/TakeDamage.h>
#include <PushEssence/PushEssence.h>

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