#include "AnimatedSprite.h"
#include "Asteroid.h"
#include "Fly.h"
#include "Spaceship.h"


using namespace std;
using namespace sf;



Clock AnimatedSprite::a_clock;
Time AnimatedSprite::a_time;
int Spaceship::_hp = 100;


Vector2f randomize_corner() {
	if (rand() % 100 <= 25) { return Vector2f(0, 0); }
	if (rand() % 100 <= 50) { return Vector2f(650, 0); }
	if (rand() % 100 <= 75) { return Vector2f(0, 725); }
	if (rand() % 100 <= 100) { return Vector2f(650, 725); }

}




int main() {
	//objects

	RectangleShape destination;
	destination.setSize(Vector2f(150, 75));
	destination.setFillColor(Color::Red);

	RectangleShape hp;
	hp.setPosition(Vector2f(0, 790));
	hp.setFillColor(Color::Green);
	hp.setSize(Vector2f(800, 10));


	//window
	RenderWindow window(VideoMode(800, 800), "SFML kolokwium");


	//Event
	Event event;


	// clocks
	Clock clock_animation;
	Clock clock_corner;
	Clock clock_collision;
	Clock clock_restart;
	Clock clock_hp;
	Clock clock_pause;


	bool is_paused = false;
	//fly_texture
	Texture fly_texture;
	fly_texture.loadFromFile("fly.png");
	IntRect sourceSprite(0, 0, 32, 32);
	float choose_sprite = 32;

	//spaceship
	Texture spaceship_texture;
	spaceship_texture.loadFromFile("spaceship.png");
	Spaceship spaceship(spaceship_texture);


	//asteroid_texture
	Texture asteroid_texture;
	asteroid_texture.loadFromFile("asteroid.png");
	

	//BULDING OBJECTS
	vector<unique_ptr<Sprite>> some_space_bugs;
	//ASTEROID
	for (int i = 0; i < 15; i++) {
		srand(time(NULL));

		Vector2f position(rand() % (window.getSize().x - 100), (rand() % (window.getSize().y - 100)) + i * 10);
		some_space_bugs.emplace_back(make_unique<Asteroid>(Asteroid(position, asteroid_texture)));
		Sprite& some_shape = dynamic_cast<Sprite&>(*some_space_bugs[i].get());
		some_shape.setOrigin(Vector2f(0, 0));

	}
	//FLY

	for (int i = 0; i < 5; i++) {
		srand(time(NULL));

		Vector2f position(rand() % (window.getSize().x - 100) , (rand() % (window.getSize().y - 100) ) + i * 10);
		some_space_bugs.emplace_back(make_unique<Fly>(Fly(position, fly_texture, sourceSprite)));

	}


	//Ranomize positions v2
	for (int i = 0; i < some_space_bugs.size();i++) {
	
		Sprite& some_shape = dynamic_cast<Sprite&>(*some_space_bugs[i].get());

			for (int k = 0; k < some_space_bugs.size(); k++) {
				Sprite& some_shape2 = dynamic_cast<Sprite&>(*some_space_bugs[k].get());

				if (some_shape.getGlobalBounds().intersects(some_shape2.getGlobalBounds()) && i != k) {
					while (some_shape.getGlobalBounds().intersects(some_shape2.getGlobalBounds())) {

						some_shape2.setPosition(std::rand() % (window.getSize().x - 30), rand() % (window.getSize().y - 30));
					}
				}


			}


	}
	for (int i = 0; i < some_space_bugs.size(); i++) {

		for (int k = 0; k < some_space_bugs.size(); k++) {
			Sprite& some_shape2 = dynamic_cast<Sprite&>(*some_space_bugs[k].get());

			if (spaceship.getGlobalBounds().intersects(some_shape2.getGlobalBounds()) && i != k) {
				while (spaceship.getGlobalBounds().intersects(some_shape2.getGlobalBounds())) {

					some_shape2.setPosition(std::rand() % (window.getSize().x - 30), rand() % (window.getSize().y - 30));
				}
			}


		}


	}

	//variables
	bool game=true;
	Vector2f mouse;

	while (window.isOpen()) {
		
		
		//event loop
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}
		//game loop
		while (game==true) {
			Time time_animation = clock_animation.getElapsedTime();
			AnimatedSprite::a_time = AnimatedSprite::a_clock.getElapsedTime();
			Time time_colision = clock_collision.getElapsedTime();
			//window geme event
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
					break;
				}
			}




			
			window.clear();
			//getting mouse position for spaceship movement
			if (Mouse::isButtonPressed(Mouse::Left)) {
				spaceship.rusz = true;
				spaceship.mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));
				mouse = window.mapPixelToCoords(Mouse::getPosition(window));

			}
			


			//drawing section

			//drawing flyes & asteroids
			for (const auto& s : some_space_bugs) {

				AnimatedSprite& some_shape = dynamic_cast<AnimatedSprite&>(*s.get());
				if (some_shape.getScale().y == 1) {


					if (time_animation.asSeconds() > 1) {

						sourceSprite.left = choose_sprite;

						choose_sprite += 32;

						for (const auto& g : some_space_bugs) {
							Sprite& some_shape = dynamic_cast<Sprite&>(*g.get());
							if (some_shape.getScale().y == 1) {
								some_shape.setTextureRect(sourceSprite);
							}
						}

						if (choose_sprite == 512) {
							choose_sprite = 32;
						}
						time_animation = clock_animation.restart();



					}
					Fly& some_fly = dynamic_cast<Fly&>(some_shape);
					some_fly.chasing(spaceship);
				}
				else {
					Asteroid& some_asteroid = dynamic_cast<Asteroid&>(some_shape);

					some_asteroid.colision();
					some_asteroid.move_();
				}
				//spaceship collsion
				if (spaceship.getGlobalBounds().intersects(some_shape.getGlobalBounds())) {

					cout << "ala" << endl;
					some_shape.setPosition(std::rand() % (window.getSize().x - 30), rand() % (window.getSize().y - 30));

					if (some_shape.getScale().x == 1) {

						spaceship._hp -= 30;


					}
					else {
						spaceship._hp -= 10;

					}

				}

				if (some_shape.getGlobalBounds().contains(mouse)) {
					
					some_shape.setPosition(std::rand() % (window.getSize().x - 30), rand() % (window.getSize().y - 30));
				}


				window.draw(*s);

				


			}

			if (clock_corner.getElapsedTime().asSeconds() > 5 || spaceship.rectangle_collisiotn(destination) == true) {

				destination.setPosition(randomize_corner());
				clock_corner.restart();
			}

	

			spaceship.move_();
			spaceship.colision();
		
			hp.setSize(Vector2f((spaceship._hp * 800) / 100, 100));
			window.draw(hp);
			window.draw(destination);
		
			AnimatedSprite::a_time = AnimatedSprite::a_clock.restart();
			
			window.draw(spaceship);
			window.display();


			if (spaceship._hp <= 0) {
				cout << "PRZEGRANA" << endl;
				game = false;
			
			}
			if (spaceship.points == 4) {
				cout << "WYGRANA" << endl;
				game = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::Key::W) && clock_hp.getElapsedTime().asSeconds() > 1) {

				spaceship._hp += 10;
				clock_hp.restart();
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::E) && clock_pause.getElapsedTime().asSeconds() > 1 && is_paused == false) {

				is_paused = true;
				game = false;
				clock_pause.restart();
			}
			cout << spaceship.getTexture()->getSize().x << " " << spaceship.getTexture()->getSize().x << endl;
		}


		if (Keyboard::isKeyPressed(Keyboard::Key::Q) && clock_restart.getElapsedTime().asSeconds() > 1) {

			game = true;
			spaceship._hp = 100;
			spaceship.setPosition(380, 380);
			spaceship.rusz = false;
			clock_restart.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::E) && clock_pause.getElapsedTime().asSeconds() > 1 && is_paused == true) {
			is_paused = false;
			game = true;
			clock_pause.restart();
			spaceship.rusz = false;
		}



		window.display();


	}


	



}
