#include "Controler/Controler.h"

Controler::Controler(std::shared_ptr<Player> player, std::shared_ptr<Room> room)
{
	room_ = std::move(room);
	player_ = std::move(player);
}

void Controler::using_ability(size_t mean, Coordinate cor)
{
	Cell& cell = room_->get_cell(cor);
	player_->using_ability(cell, mean);
}

void Controler::move(Direction& direction)
{
	room_->add_cell(std::move(room_->get_cell(direction.get_coordinate())));
	direction_ = std::move(direction);
}