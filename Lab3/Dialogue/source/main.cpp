#include <Characteristic/Characteristic.h>
//#include <Golem/Golem.h>
#include <Creator_Creature/Creator_Creature.h>
#include <Creature/Creature.h>
#include <Necromancer/Necromancer.h>
#include <Cell/Cell.h>
#include <Door/Door.h>
#include <Lava/Lava.h> 
#include <ALive/Alive.h>
#include <DirectorForFile/DirectorForFile.h>
#include <Orc/Orc.h>
#include <Skeleton/Skeleton.h>

int main()
{	
	Cell cell;
	Orc orc;
	Creator_Creature c;
	DirectorForFile d;
	Creature cr1 = orc.make_orc(d, c);
	Necromancer necr;
	Lava lava;
	Creature cr = necr.make_necromancer(d, c);
	//cr.print();
	Alive alive(cr);
	Alive al(cr1);
	std::string str = "Necromancy";
	cell.add_selection(al);
	alive.using_ability(cell, str);
	alive.print();
	//Alive alive(cr);
	//cell.add_selection(alive);
	//cell.add_selection(lava);
	//int i = 0;
	////alive.print();
	//while (i < 9)
	//{
	//	if (i == 7)
	//	{
	//		cell.delete_selection(alive);
	//		break;
	//	}
	//	i++;
	//	lava.reaction(cell);
	//}
	//alive.print();

	//Skeleton sk(cr);
	////sk.print();
	//sk.get_damage(1);
	//sk.print();
	return 0;
}

