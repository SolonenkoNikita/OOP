#ifndef _Plagin_HPP_
#define _Plagin_HPP_

#include <DirectorForFile/DirectorForFile.h>
#include <TableWithAbility/TableWithAbility.h>
#include <TakeDamage/TakeDamage.h>
#include <Boom/Boom.hpp>

class Plagin 
{
public:
	Creature make_plagin(DirectorForFile& d, Creator_Creature& cr);
};

#endif