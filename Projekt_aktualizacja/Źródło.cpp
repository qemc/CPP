#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/system.hpp>
#include <vector>
#include <math.h>
#include <algorithm>

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
	RenderWindow window(VideoMode(700, 700), "Steal the tank!", Style::Default, settings);
	Event event;
	window.setFramerateLimit(60);

	Player player;
	Game game;




	Image image;
	image.loadFromFile("map9.png");
	Texture texture;
	texture.loadFromImage(image);
	Sprite sprite;
	sprite.setTexture(texture);
	//sprite.setScale(1.1, 1.1);

	vector<Vector2f>cords_pos;
	vector<Vector2f>cords_size;
	Vector2f cords_set_pos;




	//Vector2f cords_size;


	cout << texture.getSize().x << endl;
	cout << texture.getSize().y << endl;

	vector<CircleShape> corners;


	for (uint16_t j = 0; j < 700; j++) {
		for (uint16_t i = 0; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Transparent) {



				image.setPixel(i, j, Color::White);


			}
		}
	}


	vector<Walls>rectangles;

	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j - 1) != Color::Black || j - 1 == 0) && (image.getPixel(i - 1, j) != Color::Black || i - 1 == 0)) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}



	for (uint16_t j = 0; j < 699; j++) {
		for (uint16_t i = 0; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j + 1) != Color::Black || j + 1 == 699) && (image.getPixel(i + 1, j) != Color::Black || i + 1 == 699)) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}

	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 0; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j - 1) != Color::Black || j - 1 == 0) && (image.getPixel(i + 1, j) != Color::Black || i + 1 == 699)) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}


	for (uint16_t j = 0; j < 699; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j + 1) != Color::Black || j + 1 == 699) && (image.getPixel(i - 1, j) != Color::Black || i - 1 == 0)) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}

	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i + 1, j - 1) != Color::Black && image.getPixel(i, j - 1) == Color::Black && image.getPixel(i + 1, j) == Color::Black) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}



	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i - 1, j - 1) != Color::Black && image.getPixel(i, j - 1) == Color::Black && image.getPixel(i - 1, j) == Color::Black) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}


	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i + 1, j + 1) != Color::Black && image.getPixel(i, j + 1) == Color::Black && image.getPixel(i + 1, j) == Color::Black) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));
			}
		}
	}


	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i - 1, j + 1) != Color::Black && image.getPixel(i, j + 1) == Color::Black && image.getPixel(i - 1, j) == Color::Black) {
				//cout << "XD" << endl;
				cords_pos.emplace_back(Vector2f(i, j));
			}
		}
	}


	cout << cords_pos.size() << endl;

	for (int i = 0; i < cords_pos.size(); i++) {
		//cout << cords_pos[i].x << " " << cords_pos[i].y << endl;

		for (int j = 0; j < cords_pos.size(); j++) {

			if (cords_pos[i].y == cords_pos[j].y && i!=j) {

				for (int x = 0; x < cords_pos.size(); x++) {

					if (cords_pos[j].x == cords_pos[x].x && j!=x) {

						for (int o = 0; o < cords_pos.size(); o++) {

							if (cords_pos[x].y == cords_pos[o].y && cords_pos[i].x == cords_pos[o].x && o !=x) {

								//cout << "prost" << endl;

								rectangles.emplace_back(Walls(Vector2f(cords_pos[i]), Vector2f(cords_pos[j].x - cords_pos[i].x, cords_pos[o].y - cords_pos[i].y)));
								cout << cords_pos[i].x << " - " << cords_pos[i].y << " " << cords_pos[j].x - cords_pos[i].x << " - " << cords_pos[o].y - cords_pos[i].y << endl;
								break;

							}
						}
					}
				}
			}
		}
	}








	vector<Walls>walls(rectangles);
	cout << "size_w" << walls.size() << endl;

	int rec_size = rectangles.size();


	auto compare = [](const Walls& a, const Walls& b) {


		if (a.getGlobalBounds().left != b.getGlobalBounds().left) {

			return a.getGlobalBounds().left > b.getGlobalBounds().left;

		} 	
		if (a.getGlobalBounds().left == b.getGlobalBounds().left) {

			return a.getGlobalBounds().width > b.getGlobalBounds().width;
		}

		
	};

	sort(rectangles.begin(), rectangles.end(), compare);

	for (int i =0; i < rec_size-1; i++) {
		int j = i + 1;
		if (rectangles[i].getGlobalBounds().width == rectangles[j].getGlobalBounds().width ) {
			//delete rectangles[i];

		}

		
	

		
		//walls.erase(walls.begin()+i);

	}

	int j = 1;

	for (auto itr = rectangles.begin(); itr != rectangles.end();) {



		if (itr->getGlobalBounds().width == rectangles[j].getGlobalBounds().width) {
			itr = rectangles.erase(itr);

		}
		++itr;
		j++;

	}







	//enemy drawing 

	//Image image1;
	////image1.loadFromFile("map.png");

	//Texture texture1;
	//texture1.loadFromImage(image1);
	//Sprite sprite1;
	//sprite1.setTexture(texture1);

	



	Color red(233, 30, 99);

	vector<CircleShape> ecorners;

	vector<Vector2f> ecord_pos;

	vector<Enemy> soldiers;



	for (uint16_t j = 1; j < 700; j++) {

		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == red && (image.getPixel(i, j - 1) != red || j - 1 == 0) && (image.getPixel(i - 1, j) != red || i - 1 == 0)) {
				cout << "XD" << endl;
				ecord_pos.emplace_back(Vector2f(i, j));

				int i_ = i;
				int j_ = j;


				while (image.getPixel(i_, j) == red && image.getPixel(i_, j - 1) != red) {
					i_++;
				}
				cout << " X: " << i_ - i << endl;
				while (image.getPixel(i, j_) == red && image.getPixel(i - 1, j_) != red) {
					j_++;
				}
				cout << " Y: " << j_ - j << endl;

				if (i_ - i > j_ - j) {
					soldiers.emplace_back(Vector2f(i, i_), Vector2f(i_, j - (j - j_) / 2), false, Vector2f((i_ - i),(j_-j)), Vector2f(i, j));
				}
				else {
					soldiers.emplace_back(Vector2f(j, j_), Vector2f(i - (i - i_) / 2, j), true, Vector2f((i_ -i) ,(j_ - j)),Vector2f(i,j));
				}
			}
		}
	}




	cout << soldiers.size()<<" sizeeeeee" << endl;

	Clock shoot_clock;



	vector<Bullets> bullets;
	Vector2f mouse_pos;
	Vector2f current_pos;
	Vector2f shootDir;


	

	//vector<Walls> walls;
	cout << rectangles.size()<< "size" << endl;


	//Walls wall(Vector2f(0, 0), Vector2f(25, 555));
	//wall.setFillColor(Color::Red);
	
	
	player.set_circles();


	for (int i = 0; i < cords_pos.size(); i++) {

		corners.emplace_back(CircleShape(3));
		corners[i].setFillColor(Color::Red);
		corners[i].setOrigin(3, 3);
		corners[i].setPosition(cords_pos[i]);

	}
	


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}

		window.clear();

		


		current_pos = player.aim.getPosition();

		
		

	


		for (int i = 0; i < soldiers.size(); i++) {
			soldiers[i].get_dir_vec(player.main.getPosition());
			soldiers[i].update();
			game.update(player, soldiers[i]);
			soldiers[i].control(player);

			soldiers[i].move_();


			window.draw(soldiers[i]);
		}

		
		
		
		player.update();

		player.get_dir_vec_player(window.mapPixelToCoords(Mouse::getPosition(window)));

		player.m_pos = window.mapPixelToCoords(Mouse::getPosition(window));
		player.control();
		
		
		
		


		for (int i = 0; i < rectangles.size(); i++) {

		
			
				if (player.main.getGlobalBounds().intersects(rectangles[i].getGlobalBounds())) {

					rectangles[i].collision(player);
					

				}

			
			window.draw(rectangles[i]);
			

		}

		for (auto& s : rectangles) {
			s.bullet_collision(player);
		}

		for (int i = 0; i < corners.size(); i++) {
			window.draw(corners[i]);


		}

		
		
		window.draw(player);
		//window.draw(sprite1);
		window.display();
	}





	return 0;
}
