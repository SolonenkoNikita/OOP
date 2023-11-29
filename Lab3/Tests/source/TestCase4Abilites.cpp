#include <gtest/gtest.h>

#include <TableWithAbility/TableWithAbility.h>
#include <OpenDoor/OpenDoor.h>
#include <Creature/Creature.h>
#include <ALive/Alive.h>
#include <Necromancy/Necromancy.h>
#include <Orc/Orc.h>
#include <Necromancer/Necromancer.h>
#include <Lava/Lava.h>
#include <Essence/Essence.h>

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
	table.set_ability(std::make_shared<OpenDoor>(std::move(open)));
	Orc orc;
	DirectorForFile d;
	cr.make_abiliti(table);
	Creature c = orc.make_orc(d, cr);
	Alive alive(c);
	alive.using_ability(cell, 0);
	for (auto& it : cell.get_content())
	{
		if (auto i = std::dynamic_pointer_cast<Door>(it))
		{
			ASSERT_EQ(true, i->is_open());
			break;
		}
	}
}

TEST(Necromancy_, GetTest)
{
	Coordinate cor;
	cor.x = 1, cor.y = 2;
	Coordinate cor1(cor);
	Cell cell(cor1);
	Orc orc;
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	size_t health = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	al->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, 0ull);
	cell.add_selection(al);
	a->using_ability(cell, 4);
	for (auto& it : cell.get_content())
	{
		if (auto i = std::dynamic_pointer_cast<Skeleton>(it))
		{
			ASSERT_EQ(health, i->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
			break;
		}
	}
}

TEST(Morphism_, GetTest)
{
	Cell cell;
	Orc orc;
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Skeleton> al = std::make_shared<Skeleton>(std::move(c));
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	size_t health = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_);
	al->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, 0ull);
	cell.add_selection(al);
	a->using_ability(cell, 5);
	for (auto& it : cell.get_content())
	{
		if (auto i = std::dynamic_pointer_cast<Zombie>(it))
		{
			ASSERT_EQ(health, i->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
			break;
		}
	}
}

TEST(TakeDamage_, GetTest)
{
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	Orc orc;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
	Cell cell;
	cell.add_selection(a);
	al->using_ability(cell, 0);
	ASSERT_EQ(6, a->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
}

TEST(Desiccation_, GetTest)
{
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	Orc orc;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
	al->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, 0ull);
	Cell cell;
	cell.add_selection(al);
	auto mana = a->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_mana_);
	a->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_mana_, 5ull);
	ASSERT_NE(mana, a->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_mana_));
	auto hp = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	a->using_ability(cell, 1);
	ASSERT_EQ(mana, a->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
}

TEST(Curse_, GetTest)
{
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	Orc orc;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
	Cell cell;
	auto health = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	al->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, health);
	cell.add_selection(al);
	ASSERT_EQ(health, al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
	a->using_ability(cell, 2);
	auto take = health - a->get_creature().get_characteristic().get_meaning(Atrributes_Names::damage_);
	bool meaning = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_) == take ||
		al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_) ==
		al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	ASSERT_TRUE(meaning);
}

TEST(PushEssence_, GetTest)
{
	Necromancer n;
	DirectorForFile d;
	Creator_Creature cr;
	Creature c1 = n.make_necromancer(d, cr);
	std::shared_ptr<Alive> a = std::make_shared<Alive>(std::move(c1));
	std::shared_ptr<Essence> es = std::make_shared<Essence>();
	Cell cell;
	cell.add_selection(std::move(es));
	ASSERT_EQ(0, a->get_creature().get_characteristic().get_meaning(Atrributes_Names::essence_));
	a->using_ability(cell, 6);
	ASSERT_EQ(1, a->get_creature().get_characteristic().get_meaning(Atrributes_Names::essence_));
}
