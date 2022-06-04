#include "Ball.h"
#include "Paddle.h"






using namespace std;
using namespace sf;

int main() {




	Clock clock_q;
	Clock a_clock;
	Clock r_clock;
	Clock clock_res;
	Clock clock_p;

	float choose_sprite = 11;

	while (true) {

		srand(time(NULL));

		ContextSettings settings;
		settings.antialiasingLevel = 8;

		RenderWindow window(VideoMode(800, 800), "SFML - kolokwium", Style::Default, settings);
		window.setFramerateLimit(60);
		Event event;



		bool game = true;


		//ball
		Texture b_texture;
		b_texture.loadFromFile("Ball.png");
		IntRect sourceSprite(11, 11, 28, 28);
		Ball ball(b_texture, sourceSprite);
		vector<RectangleShape>points_p;

		vector<RectangleShape>points_l;
		for (int i = 0; i < 3; i++) {

			points_l.emplace_back(RectangleShape());

			points_l[i].setSize(Vector2f(30, 30));
			points_l[i].setFillColor(Color::Transparent);
			points_l[i].setPosition(0, 10 + ((i * 3) * 30));


			points_p.emplace_back(RectangleShape());

			points_p[i].setSize(Vector2f(30, 30));
			points_p[i].setFillColor(Color::Transparent);
			points_p[i].setPosition(770, 10 + ((i * 3) * 30));


		}




		//paddle

		Texture p_texture;

		p_texture.loadFromFile("paddle.png");


		Paddle paddle_r(p_texture, Vector2f(720, 650));


		Paddle paddle_l(p_texture, Vector2f(80, 650));










		while (window.isOpen()) {

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
					break;
				}
			}

			while (game == true) {

				while (window.pollEvent(event)) {
					if (event.type == Event::Closed) {
						window.close();
						break;
					}
				}
				window.clear();


				if (a_clock.getElapsedTime().asSeconds() > 0.25) {

					sourceSprite.left = choose_sprite;
					choose_sprite += 50;

					ball.setTextureRect(sourceSprite);

					if (choose_sprite == 161) {
						choose_sprite = 11;
					}
					a_clock.restart();


				}

				if (Mouse::isButtonPressed(Mouse::Left)) {
					paddle_r.rusz = true;
					paddle_r.mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));
					//mouse = window.mapPixelToCoords(Mouse::getPosition(window));


				}



				if (ball.getPosition().x - ball.getGlobalBounds().width >= 800) {
					ball.setPosition(400, 400);
					uniform_int_distribution<int> random_int(1, 4);
					random_device rd;
					mt19937 randomNumbers(rd());

					//random_int(randomNumbers) - losowa liczba z przedzia³u wy¿ej
					int rand_int = random_int(randomNumbers);


					if (rand_int == 1) {
						ball.b_velocity.x = 4;
						ball.b_velocity.y = 3;
					}
					else if (rand_int == 2) {
						ball.b_velocity.x = -4;
						ball.b_velocity.y = 3;
					}
					else if (rand_int == 3) {
						ball.b_velocity.x = 4;
						ball.b_velocity.y = -3;
					}
					else if (rand_int == 4) {
						ball.b_velocity.x = -4;
						ball.b_velocity.y = -3;
					}
					if (clock_p.getElapsedTime().asSeconds() > 0.5) {
						paddle_l.points++;
						cout << paddle_l.points << " - punkty lewej paletki" << endl;
						clock_p.restart();

						points_l[paddle_l.points - 1].setFillColor(Color::Red);


					}


				}

				if (ball.getPosition().x + ball.getGlobalBounds().height <= 0) {
					ball.setPosition(400, 400);
					uniform_int_distribution<int> random_int(1, 4);
					random_device rd;
					mt19937 randomNumbers(rd());

					//random_int(randomNumbers) - losowa liczba z przedzia³u wy¿ej
					int rand_int = random_int(randomNumbers);


					if (rand_int == 1) {
						ball.b_velocity.x = 2;
						ball.b_velocity.y = 6;
					}
					else if (rand_int == 2) {
						ball.b_velocity.x = -2;
						ball.b_velocity.y = 6;
					}
					else if (rand_int == 3) {
						ball.b_velocity.x = 2;
						ball.b_velocity.y = -6;
					}
					else if (rand_int == 4) {
						ball.b_velocity.x = -2;
						ball.b_velocity.y = -6;
					}
					if (clock_p.getElapsedTime().asSeconds() > 0.5) {
						paddle_r.points++;
						cout << paddle_r.points << " - punkty prawej paletki" << endl;
						clock_p.restart();

						points_p[paddle_r.points].setFillColor(Color::Red);

					}


				}
				if (ball.getPosition().y - ball.getGlobalBounds().height >= 800) {
					ball.b_velocity.y = -abs(ball.b_velocity.y);
					ball.b_velocity.x = -abs(ball.b_velocity.y);
				}
				if (ball.getPosition().y + ball.getGlobalBounds().height <= 0) {
					ball.b_velocity.y = abs(ball.b_velocity.y);
					ball.b_velocity.x = abs(ball.b_velocity.y);
				}





				for (int i = 0; i < 3; i++) {
					window.draw(points_l[i]);
					window.draw(points_p[i]);
				}

				paddle_l.control_k();
				paddle_r.control_m();
				ball.movement();
				ball.movement_c();

				window.draw(ball);

				window.draw(paddle_r);

				window.draw(paddle_l);


				if (paddle_l.points > 2) {
					game = false;
					cout << "wygra³ lewy" << endl;
					
				}


				if (paddle_r.points > 2) {
					game = false;
					cout << "wygra³ prawy" << endl;
					
				}
				if (r_clock.getElapsedTime().asSeconds() > 15) {
					ball.b_velocity.x = 2 * ball.b_velocity.x;
					ball.b_velocity.y = 2 * ball.b_velocity.y;
					r_clock.restart();
				}


				if (Keyboard::isKeyPressed(Keyboard::Key::P) && clock_res.getElapsedTime().asSeconds() > 1) {
					game = false;


					clock_res.restart();
				}
							
				if (Keyboard::isKeyPressed(Keyboard::Key::R) && clock_q.getElapsedTime().asSeconds() > 1) {
					
					
					clock_q.restart();
					window.clear();
					break;
				}

				window.display();



			}



			if (Keyboard::isKeyPressed(Keyboard::Key::P) && clock_res.getElapsedTime().asSeconds() > 1) {
				game = true;


				clock_res.restart();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::R)) {
				break;


			}



		}
	}
	return 0;
}