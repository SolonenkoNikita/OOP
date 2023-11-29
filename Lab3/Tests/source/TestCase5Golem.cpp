#include <gtest/gtest.h>

#include <Golem/Golem.h>
#include<Orc/Orc.h>
#include <Alive/Alive.h>
#include <Creator_Creature/Creator_Creature.h>
#include <MakeCharacteristicForGolem/MakeCharacteristicForGolem.h>

TEST(Characteristics_, GetTest)
{
	ForGolem f;
	Characteristics ch = f.make_characteristics("../../../../Files/Golem.txt");
	Golem g(ch);

	//information from file Golem.txt
	
	ASSERT_EQ(25, g.get_characteristics().get_meaning(Atrributes_Names::current_health_));
	ASSERT_EQ(25, g.get_characteristics().get_meaning(Atrributes_Names::max_health_));
	ASSERT_EQ(50, g.get_characteristics().get_meaning(Atrributes_Names::protection_));
	ASSERT_EQ(1,  g.get_characteristics().get_meaning(Atrributes_Names::level_));
	ASSERT_EQ(5,  g.get_characteristics().get_meaning(Atrributes_Names::damage_));
}

TEST(Die_, GetTest)
{
	ForGolem f;
	Characteristics ch = f.make_characteristics("../../../../Files/Golem.txt");
	Golem g(ch);
	Cell cell;
	g.die(cell);
	char symbol = 'a';
	ASSERT_EQ('a', symbol);
	for (auto& f : cell.get_content())
	{
		if (auto s = std::dynamic_pointer_cast<Wall>(f))
		{
			symbol = '!';
		}
		else if (auto s = std::dynamic_pointer_cast<Essence>(f))
		{
			symbol = '!';
		}
		else if (auto s = std::dynamic_pointer_cast<Lava>(f))
		{
			symbol = '!';
		}
	}
	ASSERT_EQ('!', symbol);
}

TEST(Damage, GetTest)
{
	ForGolem f;
	Characteristics ch = f.make_characteristics("../../../../Files/Golem.txt");
	Golem g(ch);
	Creator_Creature cr;
	DirectorForFile d;
	Orc orc;
	Creature c = orc.make_orc(d, cr);
	std::shared_ptr<Alive> al = std::make_shared<Alive>(std::move(c));
	Cell cell;
	auto health = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	al->get_creature().get_characteristic().set_characteristic(Atrributes_Names::current_health_, health);
	cell.add_selection(al);
	ASSERT_EQ(health, al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_));
	auto take = health - g.get_characteristics().get_meaning(Atrributes_Names::damage_);
	g.using_ability(cell, 0);
	bool meaning = al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_) == take ||
		al->get_creature().get_characteristic().get_meaning(Atrributes_Names::current_health_) ==
		al->get_creature().get_characteristic().get_meaning(Atrributes_Names::max_health_);
	ASSERT_TRUE(meaning);
}