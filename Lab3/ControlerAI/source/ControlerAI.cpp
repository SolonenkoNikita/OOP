#include "ControlerAI/ControlerAI.h"

#include <cmath>


ControlerAI::ControlerAI(std::shared_ptr<Player> player, std::shared_ptr<Room> room, Direction dir) //: rng_(rd_()), dist_(std::uniform_int_distribution<>(1, 9))
{
	//rng_.seed(::time(NULL));
	direction_ = std::move(dir);
	room_ = std::move(room);
	player_ = std::move(player);
	count_ = 0;
}

//int ControlerAI::roll()
//{
//	return dist_(rng_);
//}

std::shared_ptr<Room> ControlerAI::get_room()
{
	return room_;
}

Direction& ControlerAI::get_dir()
{
	return direction_;
}

ControlerAI& ControlerAI::set_dir(int x, int y)
{
	direction_.get_coordinate().x = x;
	direction_.get_coordinate().y = y;
	return *this;
}

void ControlerAI::using_ability(size_t mean, Coordinate& cor)
{
	//auto i = roll();
	Cell& cell = room_->get_cell(cor);
	player_->using_ability(cell, mean);
}

void ControlerAI::move(Direction& direction)
{
	if (player_->get_id() == 8)
	{
		return;
	}
	Coordinate cor(direction.x(), direction.y());
	for (auto& v : room_->get_cell(cor).get_content())
	{
		if (auto content = std::dynamic_pointer_cast<Obstacle>(v))
		{
			if (content->is_hard())
			{
				return;
			}
		}
	}
	room_->get_cell(direction_.get_coordinate()).delete_selection(player_);
	direction_.get_coordinate().x = direction.x();
	direction_.get_coordinate().y = direction.y();
	room_->get_cell(direction_.get_coordinate()).add_selection(player_);
}