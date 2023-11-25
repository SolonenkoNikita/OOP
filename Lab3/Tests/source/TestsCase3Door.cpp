#include <gtest/gtest.h>

#include <Door/Door.h>
#include <OpenDoor/OpenDoor.h>
#include <Characteristic/Characteristic.h>

TEST(DoorCase, GetTest)
{
	Door door;
	ASSERT_EQ(false, door.is_open());
	door.open();
	ASSERT_EQ(true, door.is_open());
	door.close();
	ASSERT_EQ(false, door.is_open());
}

TEST(DoorCaseWithCell, GetTest)
{
	Door door;
	Cell cell;
	door.die(cell);
	for (auto& content : cell.get_content())
	{
		if(auto reaction = dynamic_pointer_cast<Door>(content))
		{
			ASSERT_EQ(true, reaction->is_open());
			break;
		}
	}
	door.revival(cell);
	for (auto& content : cell.get_content())
	{
		if (auto reaction = dynamic_pointer_cast<Door>(content))
		{
			ASSERT_EQ(false, reaction->is_open());
			break;
		}
	}
}

TEST(OPENDOOR, GetTest)
{
	OpenDoor open;
	Characteristics ch;
	Cell cell;
	Door door;
	cell.add_selection(std::make_shared<Door>(door));
	open.apply(ch, cell);
	for (auto& content : cell.get_content())
	{
		if (auto reaction = dynamic_pointer_cast<Door>(content))
		{
			ASSERT_EQ(true, reaction->is_open());
			break;
		}
	}
}

