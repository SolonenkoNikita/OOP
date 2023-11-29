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
#include <Matrix/Matrix.hpp>
#include <Room/Room.h>

int main()
{	
	Door door;
	Cell cell(1, 1);
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
	alive.using_ability(cell, 5);

	Creature cr2 = necr.make_necromancer(d, c);
	Matrix <Cell> m(3, 4);
	Cell cell1(1, 1);
	cell1.add_selection(std::make_shared<Zombie>(std::move(cr2)));
	Room r(std::make_shared<Matrix<Cell>> (std::move(m)));
	r.add_cell(cell);
	Coordinate k(1, 1);
	r.add_cell(cell1);
	for (auto& c : r.get_cell(k).get_content())
	{
		std::cout << typeid(*c).name() << '\n';
	}
	/*for (auto it_row = m.cbegin(); it_row != m.cend(); ++it_row)
	{
		std::cout << *it_row << " ";
	}*/

	////al.print();
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

