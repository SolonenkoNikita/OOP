#include <gtest/gtest.h>

#include <TableWithAbility/TableWithAbility.h>
#include <OpenDoor/OpenDoor.h>
#include <Creature/Creature.h>
#include <ALive/Alive.h>
#include <Necromancy/Necromancy.h>
#include <Orc/Orc.h>
#include <Necromancer/Necromancer.h>
#include <Lava/Lava.h>

TEST(Opened, GetTest)
{
	TableWithAbility table;
	OpenDoor open;
	std::shared_ptr<Door> door;
	Cell cell;
	cell.add_selection(door);
	for (auto& it : cell.get_content())
	{
		if (auto i = std::dynamic_pointer_cast<Door>(it))
		{
			ASSERT_EQ(false, i->is_open());
			break;
		}
	}
	Creator_Creature cr;
	std::string str = "OpenDoor";
	table.set_ability(std::make_shared<OpenDoor>(open), str);
	Orc orc;
	DirectorForFile d;
	cr.make_abiliti(table);
	Creature c = orc.make_orc(d, cr);
	Alive alive(c);
	alive.using_ability(cell, str);
	for (auto& it : cell.get_content())
	{
		if (auto i = std::dynamic_pointer_cast<Door>(it))
		{
			ASSERT_EQ(true, i->is_open());
			break;
		}
	}
}

TEST(Necromanc, GetTest)
{
	Coordinate cor;
	cor.x = 1, cor.y = 2;
	Coordinate cor1(cor);
	Cell cell(cor1);
	Orc orc;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
}