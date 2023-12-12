#include <Orc/Orc.h>
#include <DirectorForFile/DirectorForFile.h>
#include <Creator_Creature/Creator_Creature.h>
#include <Alive/Alive.h>
#include <Creature/Creature.h>
#include <Necromancer/Necromancer.h>
#include <Room/Room.h>
#include <fstream>
#include <VectorForImages/VectorForImages.h>
#include <ControlerPlayer/ControlerPlayer.h>
#include <Game/Game.hpp>
#include <Lava/Lava.h>
#include <UnResponsive/UnResponsive.h>
#include <Golem/Golem.h>
#include <MakeCharacteristicForGolem/MakeCharacteristicForGolem.h>
//#include <Search/Search.hpp>

int main()
{
	Necromancer n;
	Creator_Creature c;
	DirectorForFile d;
	Direction dir;
	Creature cr_necr = n.make_necromancer(d, c);
	std::shared_ptr<Player> player = std::make_shared<Alive>(std::move(cr_necr), 1);
	Matrix<Cell> m(10, 15);
	Room room(std::make_shared<Matrix<Cell>>(std::move(m)));
	ControlerPlayer controler(player, std::make_shared<Room>(std::move(room)), dir);
	std::vector<ControlerAI> vect;
	Game g(controler, vect);
	try
	{
		g.start();
	}
	catch (...)
	{
		return 1;
	}
	return 0;
}