//CPP
#include <iostream>
#include <math.h>
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//CLASSES
#include "Player.h"
#include "Enemy.h"
#include "Soldiers.h"
#include "Game.h"
#include "Bullets.h"
#include "Walls.h"

using namespace std;
using namespace sf;


Vector2f Player::m_pos;


int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Player player;
	Game game;
	Enemy enemy;



	Clock shoot_clock;



	vector<Bullets> bullets;
	Vector2f mouse_pos;
	Vector2f current_pos;
	Vector2f shootDir;


	vector<Vector2f>positions{ Vector2f(150, 600), Vector2f(650, 400) };

	vector<Walls> walls;

	for (int i = 0; i < positions.size(); i++) {

		walls.emplace_back(Walls(positions[i], false));

	}


	RenderWindow window(VideoMode(800, 800), "Steal the tank!",Style::Default,settings);
	Event event;
	window.setFramerateLimit(60);
	
	player.set_circles();
	


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}

		window.clear();


		current_pos = player.aim.getPosition();

		
		enemy.get_dir_vec(player.main.getPosition());


		
		
		enemy.update();
		player.update();

		player.get_dir_vec_player(window.mapPixelToCoords(Mouse::getPosition(window)));

		player.m_pos = window.mapPixelToCoords(Mouse::getPosition(window));
		//cout << player.m_pos.x << " " << player.m_pos.y << endl;
		//cout << (window.mapPixelToCoords(Mouse::getPosition(window))).x << " " << (window.mapPixelToCoords(Mouse::getPosition(window))).x << endl;
		player.control();
		
		//for (int i = 0; i < positions.size(); i++) {

		//	walls[i].collision(player);
		//}
		game.update(player, enemy);
		enemy.control(player);


		for (int i = 0; i < positions.size(); i++) {

			if (player.main.getGlobalBounds().intersects(walls[i].getGlobalBounds())) {

				walls[i].collision(player);
	
			}
			walls[i].bullet_collision(player);
			window.draw(walls[i]);
		}

		window.draw(player);
		window.draw(enemy);
		window.display();
	}





	return 0;
}
