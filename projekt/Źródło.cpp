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


	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(700, 700), "Steal the tank!", Style::Default, settings);
	Event event;
	window.setFramerateLimit(60);

	Player player;

	Image image;
	image.loadFromFile("map9.png");

	Color red(233, 30, 99);
	
	Vector2f cords_set_pos;
	Vector2f current_pos;


	Clock shoot_clock;
	


	vector<Vector2f>cords_pos;
	vector<CircleShape> corners;
	vector<Walls>rectangles;
	vector<Vector2f> ecord_pos;
	vector<Enemy> soldiers;

	//reading walls form image
	

	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j - 1) != Color::Black || j - 1 == 0) && (image.getPixel(i - 1, j) != Color::Black || i - 1 == 0)) {
				
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}



	for (uint16_t j = 0; j < 699; j++) {
		for (uint16_t i = 0; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j + 1) != Color::Black || j + 1 == 699) && (image.getPixel(i + 1, j) != Color::Black || i + 1 == 699)) {

				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}

	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 0; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j - 1) != Color::Black || j - 1 == 0) && (image.getPixel(i + 1, j) != Color::Black || i + 1 == 699)) {
			
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}


	for (uint16_t j = 0; j < 699; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j + 1) != Color::Black || j + 1 == 699) && (image.getPixel(i - 1, j) != Color::Black || i - 1 == 0)) {
				
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}

	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i + 1, j - 1) != Color::Black && image.getPixel(i, j - 1) == Color::Black && image.getPixel(i + 1, j) == Color::Black) {
				
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}



	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i - 1, j - 1) != Color::Black && image.getPixel(i, j - 1) == Color::Black && image.getPixel(i - 1, j) == Color::Black) {
				
				cords_pos.emplace_back(Vector2f(i, j));

			}
		}
	}


	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i + 1, j + 1) != Color::Black && image.getPixel(i, j + 1) == Color::Black && image.getPixel(i + 1, j) == Color::Black) {
				
				cords_pos.emplace_back(Vector2f(i, j));
			}
		}
	}


	for (uint16_t j = 1; j < 699; j++) {
		for (uint16_t i = 1; i < 699; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i - 1, j + 1) != Color::Black && image.getPixel(i, j + 1) == Color::Black && image.getPixel(i - 1, j) == Color::Black) {
				
				cords_pos.emplace_back(Vector2f(i, j));
			}
		}
	}


	

	for (int i = 0; i < cords_pos.size(); i++) {

		for (int j = 0; j < cords_pos.size(); j++) {

			if (cords_pos[i].y == cords_pos[j].y && i!=j) {

				for (int x = 0; x < cords_pos.size(); x++) {

					if (cords_pos[j].x == cords_pos[x].x && j!=x) {

						for (int o = 0; o < cords_pos.size(); o++) {

							if (cords_pos[x].y == cords_pos[o].y && cords_pos[i].x == cords_pos[o].x && o !=x) {

								rectangles.emplace_back(Walls(Vector2f(cords_pos[i]), Vector2f(cords_pos[j].x - cords_pos[i].x, cords_pos[o].y - cords_pos[i].y)));
								break;

							}
						}
					}
				}
			}
		}
	}


	//reading enemies form image

	for (uint16_t j = 1; j < 700; j++) {

		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == red && (image.getPixel(i, j - 1) != red || j - 1 == 0) && (image.getPixel(i - 1, j) != red || i - 1 == 0)) {

				ecord_pos.emplace_back(Vector2f(i, j));

				int i_ = i;
				int j_ = j;


				while (image.getPixel(i_, j) == red && image.getPixel(i_, j - 1) != red) {
					i_++;
				}
				while (image.getPixel(i, j_) == red && image.getPixel(i - 1, j_) != red) {
					j_++;
				}

				if (i_ - i > j_ - j) {
					soldiers.emplace_back(Vector2f(i, i_), Vector2f(i_, j - (j - j_) / 2), false, Vector2f((i_ - i),(j_-j)), Vector2f(i, j));
				}
				else {
					soldiers.emplace_back(Vector2f(j, j_), Vector2f(i - (i - i_) / 2, j), true, Vector2f((i_ -i) ,(j_ - j)),Vector2f(i,j));
				}
			}
		}
	}

	
	//setting player circles
	player.set_circles();


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}

		window.clear();

	

		//enemy
		for (auto& s : soldiers) {
			s.get_dir_vec(player.main.getPosition());
			s.update();
			s.control(player);
			s.move_();
			window.draw(s);
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
		
	
		window.display();
	}





	return 0;
}
