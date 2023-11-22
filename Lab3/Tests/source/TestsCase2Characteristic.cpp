#include <gtest/gtest.h>

#include <Characteristic/Characteristic.h>

TEST(DefaultÑð, GetTest)
{
	Characteristics characterictic;
	characterictic.set_characteristic(Atrributes_Names::current_health_, 10);
	characterictic.set_characteristic(Atrributes_Names::max_health_, 20);
	characterictic.set_characteristic(Atrributes_Names::current_mana_, 10);
	characterictic.set_characteristic(Atrributes_Names::max_mana_, 20);
	characterictic.set_characteristic(Atrributes_Names::level_, 1);
	characterictic.set_characteristic(Atrributes_Names::experience_, 10);
	characterictic.set_characteristic(Atrributes_Names::damage_, 15);
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::current_health_));
	ASSERT_EQ(20, characterictic.get_meaning(Atrributes_Names::max_health_));
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::current_mana_));
	ASSERT_EQ(20, characterictic.get_meaning(Atrributes_Names::max_mana_));
	ASSERT_EQ(1, characterictic.get_meaning(Atrributes_Names::level_));
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::experience_));
	ASSERT_EQ(15, characterictic.get_meaning(Atrributes_Names::damage_));
}

TEST(InitialiazerCH, GetTest)
{
	Characteristics characterictic{
		{Atrributes_Names::current_health_, 10},
	{Atrributes_Names::max_health_, 20},
	{Atrributes_Names::current_mana_, 10},
	{Atrributes_Names::max_mana_, 20},
	{Atrributes_Names::level_, 1},
	{Atrributes_Names::experience_, 10},
	{Atrributes_Names::damage_, 15}
	};
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::current_health_));
	ASSERT_EQ(20, characterictic.get_meaning(Atrributes_Names::max_health_));
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::current_mana_));
	ASSERT_EQ(20, characterictic.get_meaning(Atrributes_Names::max_mana_));
	ASSERT_EQ(1, characterictic.get_meaning(Atrributes_Names::level_));
	ASSERT_EQ(10, characterictic.get_meaning(Atrributes_Names::experience_));
	ASSERT_EQ(15, characterictic.get_meaning(Atrributes_Names::damage_));
	characterictic.set_characteristic(Atrributes_Names::current_health_, 15);
	characterictic.set_characteristic(Atrributes_Names::max_health_, 25);
	characterictic.set_characteristic(Atrributes_Names::current_mana_, 15);
	characterictic.set_characteristic(Atrributes_Names::max_mana_, 25);
	characterictic.set_characteristic(Atrributes_Names::level_, 15);
	characterictic.set_characteristic(Atrributes_Names::experience_, 150);
	characterictic.set_characteristic(Atrributes_Names::damage_, 12);
	ASSERT_EQ(15, characterictic.get_meaning(Atrributes_Names::current_health_));
	ASSERT_EQ(25, characterictic.get_meaning(Atrributes_Names::max_health_));
	ASSERT_EQ(15, characterictic.get_meaning(Atrributes_Names::current_mana_));
	ASSERT_EQ(25, characterictic.get_meaning(Atrributes_Names::max_mana_));
	ASSERT_EQ(15, characterictic.get_meaning(Atrributes_Names::level_));
	ASSERT_EQ(150, characterictic.get_meaning(Atrributes_Names::experience_));
	ASSERT_EQ(12, characterictic.get_meaning(Atrributes_Names::damage_));
}