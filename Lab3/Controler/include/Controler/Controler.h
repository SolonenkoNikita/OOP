#ifndef _Controler_H_
#define _Controler_H_

#include <memory>

#include <Room/Room.h>
#include <Base/Base.h>
#include <Cell/Cell.h>
#include <Player/Player.h>

class Controler
{
private:

	std::shared_ptr<Room> room_;

	std::shared_ptr<Player> player_;

	Direction direction_;
public:

	Controler(std::shared_ptr<Player> player, std::shared_ptr<Room> room);

	void move(Direction& direction);

	void using_ability(size_t, Coordinate);
};

#endif