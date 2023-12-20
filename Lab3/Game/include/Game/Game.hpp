#ifndef _Game_HPP_
#define _Game_HPP_

#include <ControlerPlayer/ControlerPlayer.h>
#include <ControlerAI/ControlerAI.h>
#include <Orc/Orc.h>
#include <DirectorForFile/DirectorForFile.h>
#include <Creator_Creature/Creator_Creature.h>
#include <Alive/Alive.h>
#include <Creature/Creature.h>
#include <Necromancer/Necromancer.h>
#include <Room/Room.h>
#include <VectorForImages/VectorForImages.h>
#include <SFML/Graphics.hpp>
#include <UnResponsive/UnResponsive.h>
#include <MakeCharacteristicForGolem/MakeCharacteristicForGolem.h>
#include <Lava/Lava.h>
#include <Search/Search.hpp>
#include <Golem/Golem.h>
#include <Goblin/Goblin.hpp>
#include <SFML/Audio.hpp>
#include <Plagin/Plagin.hpp>
#include <ConcurrentQueue/ConrurrentQueue.hpp>

#include <fstream>
#include <vector>
#include <future>


class Game
{
private:
	ControlerPlayer controler_player_;

	std::vector<ControlerAI> vector_ai_;

	std::mutex mutex_;

	sf::Texture create_texture(size_t id, std::vector<std::string>& ar);

	sf::Sprite create_sprite(int x, int y, sf::Texture& text);

	void create_room(const std::string& filename, std::vector < std::shared_ptr<Base>>& v);

	ControlerPlayer& get_controler();

	Direction get_direction();

	std::vector<ControlerAI>& get_vector_ai();

	std::vector<std::vector<Coordinate>> get_search();

	size_t get_num();

	void create_game();

	void filling_path();

	void draw(sf::RenderWindow& window, VectorForImages& v);

public:

	Game(ControlerPlayer controler, std::vector<ControlerAI> cr);

	void start();

};

#endif