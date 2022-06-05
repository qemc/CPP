#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/system.hpp>
#include <vector>


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


int main() {

	RenderWindow window(VideoMode(700, 700), "sfml");

	window.setFramerateLimit(60);

	Event event;

	Image image;
	

	image.loadFromFile("map6.png");
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


	cout << cords_pos.size() << endl;

	for(int i = 0; i < cords_pos.size(); i++) {
		cout << cords_pos[i].x << " " << cords_pos[i].y << endl;

		for (int j = 0; j < cords_pos.size(); j++) {

			if (cords_pos[i].y == cords_pos[j].y) {

				for (int x = 0; x < cords_pos.size(); x++) {

					if (cords_pos[j].x == cords_pos[x].x ) {

						for (int o = 0; o < cords_pos.size(); o++) {

							if (cords_pos[x].y == cords_pos[o].y && cords_pos[i].x == cords_pos[o].x) {

								cout << "prost" << endl;

								rectangles.emplace_back(Rectangle(Vector2f(cords_pos[i]), Vector2f(cords_pos[j].x - cords_pos[i].x, cords_pos[o].y - cords_pos[i].y)));
								break;

							}

						}

					}
				}


			}



		}


	}


	//for (int i = 0; i < cords_pos.size(); i++) {
	//	cout << cords_pos[i].x << " " << cords_pos[i].y << endl;

	//	for (int j = 0; j < cords_pos.size(); j++) {

	//		if (cords_pos[i].y == cords_pos[j].y && i != j) {

	//			for (int x = 0; x < cords_pos.size(); x++) {

	//				if (cords_pos[j].x == cords_pos[x].x && j != x) {

	//					for (int o = 0; o < cords_pos.size(); o++) {

	//						if (cords_pos[x].y == cords_pos[o].y && cords_pos[i].x == cords_pos[o].x) {

	//							cout << "prost" << endl;

	//							rectangles.emplace_back(Rectangle(Vector2f(cords_pos[i]), Vector2f(cords_pos[j].x - cords_pos[i].x, cords_pos[o].y - cords_pos[i].y)));


	//						}
	//					}

	//				}
	//			}


	//		}



	//	}


	//}


	//for (int s = 0; s < cords_pos.size(); s++) {
	//	for (uint16_t j = 1; j < 699; j++) {
	//		for (uint16_t i = 1; i < 699; i++) {

	//			if (image.getPixel() == Color::Black && image.getPixel(i - 1, j + 1) != Color::Black && image.getPixel(i, j + 1) == Color::Black && image.getPixel(i - 1, j) == Color::Black) {
	//				//cout << "XD" << endl;
	//				cords_pos.emplace_back(Vector2f(i, j));

	//			}



	//		}
	//	}
	//}
	//

	
	//for (uint16_t j = 0; j < image.getSize().y; j++) {
	//	for (uint16_t i = 0; i < image.getSize().x; i++) {


	//for (uint16_t k = i; k < 700; k++) {
	//	if (image.getPixel(k, j) != Color::Black) {
	//		break;
	//	}
	//	if (image.getPixel(k, j - 1) != Color::Black) {
	//		i_++;
	//	}

	//}

	//for (uint16_t k = j; k < 700; k++) {
	//	if (image.getPixel(i, k) != Color::Black) {
	//		break;
	//	}
	//	if (image.getPixel(j - 1, k) != Color::Black) {
	//		j_++;
	//	}
	//}
	//		if (image.getPixel(i, j) == Color::Black && image.getPixel(i + 1, j) != Color::Black && image.getPixel(i, j + 1) != Color::Black) {

	//			cords_pos.emplace_back(Vector2f(i, j));
	//			//cout << i << " " << j << endl;
	//			int _i = i;
	//			int _j = j;
	//			float i_ = 0;
	//			float j_ = 0;
	//			while (image.getPixel(_i, j) == Color::Black && image.getPixel(_i, j + 1) != Color::Black) {
	//				//image.setPixel(_i, j, Color::Transparent);
	//				i_--;
	//				_i--;
	//			}
	//			while (image.getPixel(i, _j) == Color::Black && image.getPixel(i + 1, _j) != Color::Black) {
	//				j_--;
	//				_j--;
	//			}
	//			//cout << i_ << " - " << j_ << endl;

	//			rectangles.emplace_back(Rectangle(Vector2f(_i, _j), Vector2f(abs(i_), abs(j_))));

	//		}





	//	}
	//}






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


		window.display();


	}


	return 0;
}