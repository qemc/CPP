#include "Player.h"
#include "Enemy.h"
#include "Soldiers.h"
#include "Game.h"
#include "Bullets.h"
#include "Walls.h"
#include "Bonus.h"
#include "Fireplace.h"
#include "Ammo.h"
#include "Stats.h"
#include "Start.h"
#include <string>

#include <SFML/Audio.hpp>


#include "map_reader.h"
using namespace std;
using namespace sf;

Vector2f Player::m_pos;
Clock Soldiers::movement;


int main() {

	Stats stats;

	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(700, 800), "Steal the tank!", Style::Default, settings);
	Event event;
	window.setFramerateLimit(60);

	Player player;
	Texture background_t;
	background_t.loadFromFile("background.png");
	Sprite background;
	background.setTexture(background_t);


	SoundBuffer ss;
	ss.loadFromFile("imigrant.ogg");

	Sound sound;
	sound.setBuffer(ss);

	sound.getLoop();



	vector<Texture>textures;

	for (int i = 0; i < 3; i++) {

		Texture texture;
		texture.loadFromFile(to_string(i+1) + "map.png");
		textures.emplace_back(texture);

	}
	Start start_m(textures);





	Image image;
	//image.loadFromFile("map1.png");

	vector<string>maps = { "map1.png","map2.png","map3.png"};


	Color red(237, 28, 36);
	Color yellow(255, 242, 0);
	Color grey(112, 146, 190);
	Color blue(0, 162, 232);

	Vector2f cords_set_pos;
	Vector2f current_pos;
	
	// tank texture upload

	Texture tank_texture;
	tank_texture.loadFromFile("tank.png");

	Game game(tank_texture);

	Sprite sprite;
	sprite.setTexture(tank_texture);
	
	//ammo texture upload
	Texture ammo_texture;
	ammo_texture.loadFromFile("ammo.png");
	
	//fireplace texture upload
	Texture fire_texture;
	fire_texture.loadFromFile("fireplace.png");

	//fireplace animation variables
	IntRect sourceSprite(0, 0, 64, 128);
	int choose_sprite_x = 64;
	int choose_sprite_y = 128;
	//clocks
	Clock fireplace_clock;
	Clock shoot_clock;
	//reading map variables
	vector<Vector2f>cords_pos;
	vector<CircleShape> corners;
	vector<Walls>rectangles;
	vector<Vector2f> ecord_pos;
	vector<Enemy> soldiers;
	vector<unique_ptr<Bonus>> bonus;
	vector<Fireplace>fire;




	



	
	//setting player circles
	player.set_circles();



	bool start = false;
	bool menu = true;
	


	

	//main loop
	while (window.isOpen()) {
		sound.play();

		
		

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}
		//starting loop


		while (menu == true) {

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
					break;
				}
			}
				
			start_m.update(window.mapPixelToCoords(Mouse::getPosition(window)));

		


			for (int i = 0; i < 3; i++) {


				if (Mouse::isButtonPressed(Mouse::Left)&&start_m.maps[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {

					image.loadFromFile("map"+to_string(i+1)+".png");

					rectangles = read_walls(image);
					soldiers = read_enemies(image);
					bonus = read_bonus(image, fire_texture, ammo_texture);
					game.setPosition(set_destination(image));
					start = true;
					menu = false;
					stats.game_clock.restart();
					game.win = false;
				}

			}

			window.clear();
		
			window.draw(background);
			window.draw(start_m);


			window.display();

		}
		// game loop
		while (start == true) {

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
					break;
				}
			}
			window.clear();
			window.draw(background);
			//enemy
			for (auto& s : soldiers) {
				s.get_dir_vec(player.main.getPosition());
				s.update();
				s.control(player);
				s.move_();
				window.draw(s);
				game.shoot(player, s);

			}



			//deleting deal enemy
			for (auto s = soldiers.begin(); s != soldiers.end();) {


				if (s->hp <= 0) {
					s = soldiers.erase(s);
				}
				else {
					++s;
				}

			}

			//player functions
			player.update();
			player.get_dir_vec_player(window.mapPixelToCoords(Mouse::getPosition(window)));
			player.m_pos = window.mapPixelToCoords(Mouse::getPosition(window));
			player.control();
			window.draw(player);

			//walls functions

			for (auto& s : rectangles) {

				if (player.main.getGlobalBounds().intersects(s.getGlobalBounds())) {

					s.collision(player);
				}
				window.draw(s);
				s.bullet_collision(player);
			}

			//bonus funcitons and drawing
			for (auto& s : bonus) {

				if (s->is_ammo == false) {

					if (fireplace_clock.getElapsedTime().asSeconds() > 0.10) {

						Fireplace& some_fireplace = dynamic_cast<Fireplace&>(*s.get());

						sourceSprite.left = choose_sprite_x;
						choose_sprite_x += 64;
						choose_sprite_y += 64;

						for (const auto& g : bonus) {
							if (g->is_ammo == false) {

								g->setTextureRect(sourceSprite);
							}
						}
						if (choose_sprite_x == 512) {
							choose_sprite_y += 64;
							choose_sprite_x = 64;

						}
						if (choose_sprite_y == 512) {
							choose_sprite_y = 64;
							choose_sprite_x = 64;

						}
						some_fireplace.add_hp(player);
						fireplace_clock.restart();
					}
				}

				if (s->is_ammo == false) {

					Fireplace& some_fireplace = dynamic_cast<Fireplace&>(*s.get());
					some_fireplace.add_hp(player);
				}
				else {
					Ammo& some_ammo = dynamic_cast<Ammo&>(*s.get());
					some_ammo.add_ammo(player);
				}
				window.draw(*s);
			}

			//deleting 
			for (auto itr = bonus.begin(); itr != bonus.end();) {
				Bonus& some_bonus = dynamic_cast<Bonus&>(*itr->get());
				if (some_bonus.is_ammo == true && some_bonus.getGlobalBounds().intersects(player.main.getGlobalBounds())) {

					itr = bonus.erase(itr);
				}
				else {
					++itr;
				}
			}
			stats.update(player);
			window.draw(stats);
			window.draw(game);

			window.display();

			Soldiers::movement.restart();

			if (game.win == true) {

				start = false;
				soldiers.clear();
				player.ammo = 50;
				player.hp = 5;
				menu = true;
				
				rectangles.clear();
				bonus.clear();
				player.velocity.x = 0;
				player.velocity.x = 0;
				player.main.setPosition(50, 650);

				start_m.result.setString("you won");




			}


			if (player.hp == 0) {
				game.lost == true;

				start = false;
				soldiers.clear();
				player.ammo = 50;
				player.hp = 5;
				menu = true;

				rectangles.clear();
				bonus.clear();
				player.velocity.x = 0;
				player.velocity.x = 0;
				player.main.setPosition(50, 650);

				start_m.result.setString("you lost");


			}


		}
	}





	return 0;
}
