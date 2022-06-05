#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/system.hpp>
#include <vector>
#include <math.h>


using namespace std;
using namespace  sf;



class Rectangle :public RectangleShape {
public:

	Rectangle(const Vector2f& position, const Vector2f& size) {
		setPosition(position);
		setSize(size);
		setFillColor(Color::Green);
	}

};

class Soldier :public CircleShape {
public:

	Vector2f range;
	bool vert;

	Vector2f velocity;


	Soldier(const Vector2f& range_, const Vector2f &position, bool vert_) {

		setPosition(position);
		range = range_;
		setFillColor(Color::Green);
		setRadius(5);
		setOrigin(5, 5);
		
		vert = vert_;

		if (vert == true) {
			velocity.x = 0;
			velocity.y = 3;
		}
		else {
			velocity.x = 3;
			velocity.y = 0;
		}
		

	}


	void move_() {



		
		if (vert == false) {

			if (this->getPosition().x < range.x) {

				velocity.x = abs(velocity.x);

			}
			if (this->getPosition().x > range.y) {

				velocity.x = -abs(velocity.x);

			}

		}
		else {
			if (this->getPosition().y < range.x) {

				velocity.y = abs(velocity.y);

			}
			if (this->getPosition().y > range.y) {

				velocity.y = -abs(velocity.y);

			}
		}

		this->move(velocity);

	}


};


int main() {

	RenderWindow window(VideoMode(700, 700), "sfml");

	window.setFramerateLimit(60);

	Event event;

	Image image;
	

	image.loadFromFile("map9.png");
	Texture texture;

	texture.loadFromImage(image);

	Sprite sprite;
	//sprite.setScale(1.1, 1.1);

	vector<Vector2f>cords_pos;
	vector<Vector2f>cords_size;
	Vector2f cords_set_pos;


	

	//Vector2f cords_size;

	sprite.setTexture(texture);
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


	vector<Rectangle>rectangles;

	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == Color::Black && (image.getPixel(i, j - 1) != Color::Black|| j - 1 == 0) && (image.getPixel(i - 1, j) != Color::Black || i - 1==0)) {
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


	//cout << cords_pos.size() << endl;

	for(int i = 0; i < cords_pos.size(); i++) {
		//cout << cords_pos[i].x << " " << cords_pos[i].y << endl;

		for (int j = 0; j < cords_pos.size(); j++) {

			if (cords_pos[i].y == cords_pos[j].y) {

				for (int x = 0; x < cords_pos.size(); x++) {

					if (cords_pos[j].x == cords_pos[x].x ) {

						for (int o = 0; o < cords_pos.size(); o++) {

							if (cords_pos[x].y == cords_pos[o].y && cords_pos[i].x == cords_pos[o].x) {

								//cout << "prost" << endl;

								rectangles.emplace_back(Rectangle(Vector2f(cords_pos[i]), Vector2f(cords_pos[j].x - cords_pos[i].x, cords_pos[o].y - cords_pos[i].y)));
								break;

							}

						}

					}
				}


			}



		}


	}


	
	//																					 ENEMMY DRAWING


	Color red(233, 30, 99);

	vector<CircleShape> ecorners;

	vector<Vector2f> ecord_pos;

	vector<Soldier> soldiers;



	for (uint16_t j = 1; j < 700; j++) {
		for (uint16_t i = 1; i < 700; i++) {

			if (image.getPixel(i, j) == red && (image.getPixel(i, j - 1) != red || j - 1 == 0) && (image.getPixel(i - 1, j) != red || i - 1 == 0)) {
				//cout << "XD" << endl;
				ecord_pos.emplace_back(Vector2f(i, j));

				int i_ = i;
				int j_ = j;
				

				while (image.getPixel(i_, j) == red && image.getPixel(i_, j - 1) != red) {
					i_++;
				}
				cout <<" X: "<< i_ - i << endl;
				while (image.getPixel(i, j_) == red && image.getPixel(i - 1, j_) != red) {
					j_++;
				}
				cout <<" Y: "<< j_ - j << endl;

				if (i_-i > j_-j) {
					soldiers.emplace_back(Vector2f(i, i_), Vector2f(i_, j - (j - j_) / 2), false);
				}
				else {
					soldiers.emplace_back(Vector2f(j, j_), Vector2f(i - (i - i_) / 2, j), true);
				}

				
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


		for (int i = 0; i < rectangles.size(); i++) {
			window.draw(rectangles[i]);


		}

		for (int i = 0; i < soldiers.size(); i++) {
			soldiers[i].move_();
			window.draw(soldiers[i]);


		}

		window.display();


	}


	return 0;
}