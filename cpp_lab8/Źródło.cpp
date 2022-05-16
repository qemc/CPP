//CPP
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//CLASSES
#include "CustomRectangleShape.h"
//NAMESPACES
using namespace std;
using namespace sf;

//MAIN
int main() {

	


	//WINDOW
	RenderWindow window(VideoMode(1000, 1000), "SFML");
	window.setFramerateLimit(60);

	vector<CustomRectangleShape> rectangles;



	for (int i = 0; i < 10; i++) {
		srand(time(NULL));
		Vector2f size(120.0, 60.0);
		Vector2f position(rand() % (window.getSize().x - 120), rand() % (window.getSize().y - 60)+i*10);

		rectangles.emplace_back(CustomRectangleShape(size, position));


		rectangles[i].setFillColor(Color(
			rectangles[i].randomize_color().x,
			rectangles[i].randomize_color().y,
			rectangles[i].randomize_color().z)
		);
		rectangles[i].set_speed();
		rectangles[i].randomize_move_dir();


	}

	vector<CustomRectangleShape> rectangles_dis;

	//cout << my_rectangle.randomize(-3, 7).x << " " << my_rectangle.randomize(-3, 3).y << endl; --> DZIALA

	int ile = 0;



	while (ile < 600) {
		for (int i = 0; i < rectangles.size(); i++) {
			for (int j = 0; j < rectangles.size(); j++) {
				if (rectangles[i].getGlobalBounds().intersects(rectangles[j].getGlobalBounds()) && i != j) {


					rectangles[i].setPosition(std::rand() % (window.getSize().x - 120), rand() % (window.getSize().y - 60));
					break;
				}

				ile++;

			}

			cout << ile << endl;
		}
	}


	//EVENTS


	//WINDOW LOOP	
	while (window.isOpen()) {
		Event event;
		//EVENT LOOP
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}
		//MAIN BODY





		//WINDOW CLEAR
		window.clear();
		//DRAWING






		for (int j = 0; j < rectangles.size(); j++) {

			rectangles[j].animate();

			rectangles[j].get_mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));
			window.draw(rectangles[j]);
			
			
			rectangles[j].select();
			rectangles[j].unselect();
	
		}

		




		window.display();
	}






	return 0;
}

