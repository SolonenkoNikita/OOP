#ifndef _Controler_H_
#define _Controler_H_

#include <memory>

#include <Room/Room.h>
#include <Base/Base.h>
#include <Cell/Cell.h>
#include <Player/Player.h>
#include <Controler/Controler.hpp>

class ControlerPlayer : public Controler
{
private:
	std::shared_ptr<Room> room_;

	std::shared_ptr<Player> player_;

	Direction direction_;
public:

	ControlerPlayer() = default;

	ControlerPlayer(std::shared_ptr<Player> player, std::shared_ptr<Room> room, Direction dir);

	ControlerPlayer& set_dir(int x, int y);

	std::shared_ptr<Room> get_room(); 

	std::shared_ptr<Player> get_player();

	Direction& get_dir();

	void move(Direction& direction) override;

	void using_ability(size_t, Coordinate&) override;
};

#endif