#include "Game/Game.hpp"

Game::Game(ControlerPlayer controler, std::vector<ControlerAI> cr)
{
	controler_player_ = std::move(controler);
	vector_ai_ = std::move(cr);
}

sf::Texture Game::create_texture(size_t id, std::vector<std::string>& ar)
{
	sf::Image image;
	image.loadFromFile("../../../../images/" + ar[id]);
	sf::Texture text;
	text.loadFromImage(image);
	return text;
}

sf::Sprite Game::create_sprite(int x, int y, sf::Texture& text)
{
	Coordinate cor(x, y);
	sf::Sprite sprite;
	sprite.setTexture(text);
	sprite.setPosition(x * 32, y * 32);
	return sprite;
}

void Game::create_room(const std::string& filename, std::vector<std::shared_ptr<Base>>& v)
{
	std::ifstream in(filename);
	int key;
	if (in.is_open())
	{
		for (int i = 0; i < controler_player_.get_room()->get_matrix()->size_matrix(); i++)
		{
			for (int j = 0; j < controler_player_.get_room()->get_matrix()->size_line(); j++)
			{
				in >> key;
				Coordinate cor(i, j);
				int count = 0;
				for (auto it = v.begin(); it != v.end(); it++, count++)
				{
					if ((*it)->get_id() == key)
					{
						controler_player_.get_room()->get_cell(cor).add_selection(v[count]);
						if ((*it)->get_id() == 1)
						{
							controler_player_.get_dir().get_coordinate().x = i;
							controler_player_.get_dir().get_coordinate().y = j;
							continue;
						}
						else if(auto x = std::dynamic_pointer_cast<DamageCaused>(*it))
						{
							if (auto b = std::dynamic_pointer_cast<Door>(*it))
							{
								continue;
							}
							Direction dir(cor);
							auto player = std::dynamic_pointer_cast<Player>(v[count]);
							ControlerAI controler(player, controler_player_.get_room(), dir);
							vector_ai_.emplace_back(std::move(controler));
						}
					}
				}
			}
		}
	}
	in.close();
}

void Game::create_game()
{
	Creator_Creature c;
	DirectorForFile d;
	Orc orc;
	Goblin goblin;
	ForGolem forgolem;
	Characteristics golems_ch = forgolem.make_characteristics("../../../../Files/Golem.txt");
	std::vector<std::shared_ptr<Base>> vectores;
	vectores.emplace_back(std::make_shared<Lava>(1));
	vectores.emplace_back(std::make_shared<Alive>(orc.make_orc(d, c), 2));
	vectores.emplace_back(std::make_shared<Alive>(goblin.make_goblin(d, c), 12));
	vectores.emplace_back(controler_player_.get_player());
	vectores.emplace_back(std::make_shared<Floor>());
	vectores.emplace_back(std::make_shared<Wall>());
	vectores.emplace_back(std::make_shared<Golem>(std::move(golems_ch)));
	vectores.emplace_back(std::make_shared<Door>());
	vectores.emplace_back(std::make_shared<Essence>());
	vectores.emplace_back(std::make_shared<Skeleton>(goblin.make_goblin(d, c)));
	vectores.emplace_back(std::make_shared<Zombie>(orc.make_orc(d, c)));
	create_room("../../../../FileForRoom/FileForRoom.txt", vectores);
}

ControlerPlayer& Game::get_controler()
{
	return controler_player_;
}

Direction Game::get_direction()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return { -1, 0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return { 1 , 0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return { 0, -1 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return { 0,  1 };
	}
	return { 0, 0 };
}

size_t Game::get_num()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		return 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		return 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		return 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		return 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		return 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		return 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		return 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		return 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		return 9;
	}
}

std::vector<std::vector<Coordinate>> Game::get_search()
{
	std::vector<std::vector<Coordinate>> vv;
	for (int i = 0; i < vector_ai_.size(); i++)
	{
		Search sear;
		Coordinate cordin(vector_ai_[i].get_dir().x(), vector_ai_[i].get_dir().y());
		std::vector<Coordinate> vec = sear.search(*controler_player_.get_room()->get_matrix(), cordin, controler_player_.get_dir().get_coordinate());
		vv.emplace_back(vec);
	}
	return vv;
}

void Game::draw(sf::RenderWindow& window, VectorForImages& v)
{
	int flag = 0;
	sf::Music music;
	music.openFromFile("../../../../Music/heroes.ogg");
	music.play();
	std::vector<std::vector<Coordinate>> vv = get_search();
	sf::Time halfSecond = sf::milliseconds(500);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Direction dir, old_dir = controler_player_.get_dir();
		window.clear();
		dir = get_direction();
		controler_player_.move(dir);
		if (old_dir != dir)
		{
			/*for (auto& vec : vv)
			{
				vec.clear();
			}
			vv.clear();*/
			vv = get_search();
		}
		for (int i = 0; i < 1; i++)
		{
			if (vector_ai_[i].get_count() > vv[i].size())
			{
				vector_ai_[i].set_count(0);
				continue;
			}
			if (vv[i][vector_ai_[i].get_count()] == controler_player_.get_dir())
			{
				continue;
			}
			int j = vector_ai_[i].get_count();
			Direction di(vv[i][j]);
			j++;
			vector_ai_[i].move(di);
			vector_ai_[i].set_count(j);
		}
		//std::cout << vector_ai_[0].get_dir().x() << ' ' << vector_ai_[0].get_dir().y() << '\n';
		std::cout << controler_player_.get_dir().x() << ' ' << controler_player_.get_dir().x() << '\n';
		int number = get_num();
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			int x = event.mouseButton.x / 32;
			int y = event.mouseButton.y / 32;
			Coordinate coor(x, y);
			if (number == 2)
			{
				controler_player_.using_ability(number, coor);
			}
			if(number != 2 && (fabs(x - controler_player_.get_dir().x()) <= 1 || fabs(y - controler_player_.get_dir().x()) <= 1))
			{
				controler_player_.using_ability(number, coor);
			}
			for (auto& content : controler_player_.get_room()->get_cell(coor).get_content())
			{
				if (auto creature = std::dynamic_pointer_cast<DamageCaused>(content))
				{
					if (creature->is_died())
					{
						creature->die(controler_player_.get_room()->get_cell(coor));
					}
				}
			}
		}
		if (flag != 1)
		{
			for (int i = 0; i < controler_player_.get_room()->get_matrix()->size_matrix(); i++)
			{
				for (int j = 0; j < controler_player_.get_room()->get_matrix()->size_line(); j++)
				{
					Coordinate cor(i, j);
					sf::Texture text = create_texture(0, v.get_vector());
					sf::Sprite sprite = create_sprite(i, j, text);
					window.draw(sprite);
					for (auto& celka : controler_player_.get_room()->get_cell(cor).get_content())
					{
						if (celka->get_id() != 0)
						{
							sf::Texture t = create_texture(celka->get_id(), v.get_vector());
							sf::Sprite sp = create_sprite(i, j, t);
							window.draw(sp);
						}
						if (auto g = std::dynamic_pointer_cast<Lava>(celka))
						{
							g->reaction(controler_player_.get_room()->get_cell(cor));
						}
					}
				}
			}
		}
		if (controler_player_.get_player()->get_id() == 8)
		{
			window.clear();
			sf::Image image;
			image.loadFromFile("../../../../images/game_over.png");
			sf::Texture text;
			text.loadFromImage(image);
			sf::Sprite sprite;
			sprite.setTexture(text);
			window.draw(sprite);
			flag = 1;
		}
		window.display();
	}
}

std::vector<ControlerAI>& Game::get_vector_ai()
{
	return vector_ai_;
}

void Game::start()
{
	create_game();
	VectorForImages v("../../../../FileForImages/File.txt");
	sf::RenderWindow window(sf::VideoMode(480, 320), "");
	window.setFramerateLimit(60);
	draw(window, v);
}