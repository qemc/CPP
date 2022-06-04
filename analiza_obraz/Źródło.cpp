#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/system.hpp>
#include <vector>


using namespace std;
using namespace  sf;

int main() {

	RenderWindow window(VideoMode(1478, 739), "sfml");

	window.setFramerateLimit(60);

	Event event;

	Image image;

	image.loadFromFile("map.png");
	Texture texture;

	texture.loadFromImage(image);

	Sprite sprite;

	vector<Vector2f>cords_pos;
	vector<Vector2f>cords_size;
	Vector2f cords_set_pos;
	//Vector2f cords_size;

	sprite.setTexture(texture);
	cout << texture.getSize().x << endl;
	cout << texture.getSize().y << endl;

	vector<CircleShape> corners;



	for (uint16_t j = 0; j < image.getSize().y; j++) {
		for (uint16_t i = 0; i < image.getSize().x; i++) {

			if (image.getPixel(i, j) == Color::Black && image.getPixel(i - 1, j) == Color::White && image.getPixel(i, j - 1) == Color::White) {

				cords_pos.emplace_back(Vector2f(i, j));
				cout << i << " " << j << endl;
				uint16_t _i = i;
				uint16_t _j = j;
				float i_ = 0;
				float j_ = 0;
				while (image.getPixel(_i, j) == Color::Black) {
					i_++;
					_i++;
				}
				while (image.getPixel(i, _j) == Color::Black) {
					j_++;
					_j++;
				}
				cout << i_ << " - " << j_ << endl;
			}





		}
	}


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
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	


		window.draw(sprite);



		for (int i = 0; i < corners.size(); i++) {
			window.draw(corners[i]);
		

		}




		window.display();


	}


	return 0;
}