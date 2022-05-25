#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>


using namespace std;
using namespace sf;

const float PI = 3.14159265359f;
//CALCULATE ROTATION ANGLE
float angle(Vector2f dirVec) {

	float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	dirVec.x = (dirVec.x) / magSquare;
	dirVec.y = (dirVec.y) / magSquare;

	return acos(dirVec.x) * (180 / PI);

}


//NORMALIZE VECTOR

Vector2f normalize(const Vector2f& x, const Vector2f& y) {

	Vector2f all(abs(x.x - y.x), abs(x.y - y.y));


	float sqr = sqrt(((y.x - x.x) * (y.x - x.x)) + (y.y - x.y) * (y.y - x.y));

	return Vector2f(all.x / sqr, all.y / sqr);


}

int main() {
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(800, 800), "Steal the tank!",Style::Default,settings);
	Event event;
	Clock clock;
	Clock clock_shoot;

	//AIM CIRCLE
	CircleShape aim_circle(4);
	aim_circle.setFillColor(Color::Red);
	aim_circle.setOrigin(aim_circle.getRadius(), 20);


	//MAIN CIRCLE
	CircleShape main_circle(10);
	main_circle.setFillColor(Color::Transparent);
	main_circle.setOutlineColor(Color::White);
	main_circle.setOutlineThickness(2);
	main_circle.setOrigin(10, 10);
	main_circle.setPosition(400, 400);
	
	vector<CircleShape>bullets;
	Vector2f mouse_pos;
	Vector2f shootDir;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}
		//DIRECTION VECTOR
		Vector2f dirVec(Mouse::getPosition(window).x - main_circle.getPosition().x, Mouse::getPosition(window).y - main_circle.getPosition().y);

		aim_circle.setPosition(main_circle.getPosition());
		
		
		window.clear();



		if (Mouse::isButtonPressed(Mouse::Left)&&clock_shoot.getElapsedTime().asSeconds() >0.5f) {

			bullets.emplace_back(CircleShape(6));
			
			mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));

			for (int i = 0; i < bullets.size(); i++) {

				bullets[i].setFillColor(Color::Red);
				bullets[i].setPosition(aim_circle.getPosition());
			}
			for (int i = 0; i < bullets.size(); i++) {
				if (mouse_pos.x < bullets[i].getPosition().x && mouse_pos.y < bullets[i].getPosition().y) {

					shootDir.x = -500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).x;
					shootDir.y = -500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).y;

				}
				else
					if (mouse_pos.x > bullets[i].getPosition().x && mouse_pos.y < bullets[i].getPosition().y) {

						shootDir.x = 500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).x;
						shootDir.y = -500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).y;
					}
					else
						if (mouse_pos.x < bullets[i].getPosition().x && mouse_pos.y > bullets[i].getPosition().y) {

							shootDir.x = -500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).x;
							shootDir.y = 500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).y;

						}
						else
							if (mouse_pos.x > bullets[i].getPosition().x && mouse_pos.y > bullets[i].getPosition().y) {

								shootDir.x = 500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).x;
								shootDir.y = 500 * clock.getElapsedTime().asSeconds() * normalize(mouse_pos, bullets[i].getPosition()).y;
							}


				

			}
			clock_shoot.restart();

			
			

		
		}




		

		//DRAWING





		for (int i = 0; i < bullets.size(); i++) {

			window.draw(bullets[i]);
			bullets[i].move(shootDir);

		}


		//SETTING AIM ROTATION
		if (dirVec.y < 0) {
			aim_circle.setRotation(90 - angle(dirVec));
		}
		else {
			aim_circle.setRotation(90 + angle(dirVec));
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			main_circle.move(0, -500*clock.getElapsedTime().asSeconds());
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
			main_circle.move(0, 500 * clock.getElapsedTime().asSeconds());
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
			main_circle.move(-500 * clock.getElapsedTime().asSeconds(),0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
			main_circle.move(500 * clock.getElapsedTime().asSeconds(),0);
		}


		


		window.draw(main_circle);
		window.draw(aim_circle);


				
		
		
		window.display();
		clock.restart();
	}
		
		
		





	return 0;
}