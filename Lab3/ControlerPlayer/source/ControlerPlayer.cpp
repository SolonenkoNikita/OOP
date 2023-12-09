#include "ControlerPlayer/ControlerPlayer.h"

ControlerPlayer::ControlerPlayer(std::shared_ptr<Player> player, std::shared_ptr<Room> room, Direction dir)
{
	direction_ = std::move(dir);
	room_ = std::move(room);
	player_ = std::move(player);
}

std::shared_ptr<Room> ControlerPlayer::get_room()
{
	return room_;
}

std::shared_ptr<Player> ControlerPlayer::get_player()
{
	return player_;
}

Direction& ControlerPlayer::get_dir()
{
	return direction_;
}

ControlerPlayer& ControlerPlayer::set_dir(int x, int y)
{
	direction_.get_coordinate().x = x;
	direction_.get_coordinate().y = y;
	return *this;
}

void ControlerPlayer::using_ability(size_t mean, Coordinate& cor)
{
	Cell& cell = room_->get_cell(cor);
	player_->using_ability(cell, mean);
}

void ControlerPlayer::move(Direction& direction)
{
	if (direction.x() + direction_.x() >= room_->get_matrix()->size_matrix() || direction.x() + direction_.x() < 0 ||
		direction.y() + direction_.y() >= room_->get_matrix()->size_line() || direction.y() + direction_.y() < 0)
	{
		return;
	}
	Coordinate cor(direction.x() + direction_.x(), direction.y() + direction_.y());
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
	direction_.get_coordinate().x = direction.x() + direction_.x();
	direction_.get_coordinate().y = direction.y() + direction_.y();
	room_->get_cell(direction_.get_coordinate()).add_selection(player_);
}