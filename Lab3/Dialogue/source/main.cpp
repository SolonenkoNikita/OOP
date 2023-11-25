#include <Characteristic/Characteristic.h>
#include <Golem/Golem.h>
#include <Creator_Creature/Creator_Creature.h>
#include <Creature/Creature.h>
#include <Necromancer/Necromancer.h>
#include <Cell/Cell.h>
#include <Door/Door.h>
#include <Lava/Lava.h> 
#include <ALive/Alive.h>
#include <DirectorForFile/DirectorForFile.h>
#include <Orc/Orc.h>
#include <Unhead/Unhead.h>
#include <Skeleton/Skeleton.h>

int main()
{	
	Door door;
	Cell cell;
	Orc orc;
	Creator_Creature c;
	DirectorForFile d;
	Creature cr1 = orc.make_orc(d, c);
	Necromancer necr;
	Lava lava(1);
	Creature cr = necr.make_necromancer(d, c);
	Alive alive(cr);
	std::string str = "Morphism";
	//auto f = std::make_shared<Alive>(std::move(cr));
	Characteristics ch = cr1.get_characteristic();
	auto a = std::make_shared<Golem>(std::move(ch));
	//auto al = ;
	cell.add_selection(std::make_shared<Door>(door));
	cell.add_selection(std::make_shared<Lava>(lava));
	cell.add_selection(std::make_shared<Skeleton>(std::move(cr)));
	alive.using_ability(cell, str);
	for (auto& content : cell.get_content())
	{
		std::cout << typeid(*content).name() << '\n';
		/*if (auto alive = dynamic_pointer_cast<Skeleton>(content))
		{
			std::cout << "!";
		}*/
	}
	//al.print();
	//alive.print();
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

