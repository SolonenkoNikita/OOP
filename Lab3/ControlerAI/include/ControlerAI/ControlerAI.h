#ifndef _ControlerAI_H_
#define _ControlerAI_H_

#include <memory>
#include <random>
#include <time.h>
#include <ctime>

#include <Room/Room.h>
#include <Player/Player.h>
#include <Cell/Cell.h>
#include <Controler/Controler.hpp>

class ControlerAI : public Controler
{
private:
	std::shared_ptr<Room> room_;

	std::shared_ptr<Player> player_;

	std::vector<Coordinate> way_;

	Direction direction_;

	size_t count_;

	/*std::random_device rd_;

	typedef std::mt19937 MyRng;

	MyRng rng_;

	std::uniform_int_distribution<int> dist_;

	int roll();*/
public:

	ControlerAI() = default;

	ControlerAI(std::shared_ptr<Player> player, std::shared_ptr<Room> room, Direction dir);

	ControlerAI set_count(size_t count)
	{
		count_ = count;
		return *this;
	}

	size_t get_count()
	{
		return count_;
	}

	size_t get_count() const
	{
		return count_;
	}

	ControlerAI& set_dir(int x, int y);

	std::shared_ptr<Room> get_room();

	Direction& get_dir();

	ControlerAI& set_way(std::vector<Coordinate> v)
	{
		way_ = std::move(v);
		return *this;
	}

	std::vector<Coordinate>& get_way()
	{
		return way_;
	}

	const std::vector<Coordinate>& get_way() const
	{
		return way_;
	}

	void move(Direction& direction) override;

	void using_ability(size_t, Coordinate&) override;
};

#endif