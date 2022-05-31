#include "Owoc.h"
#include "Duch.h"
#include "Pacman.h"




int main() {



	srand(time(NULL));
	

	//window /events

	RenderWindow window(VideoMode(800, 800), "sfml - spaceship");
	window.setFramerateLimit(60);
	Event event;
	bool game = true;
	bool is_paused = false;

	// pacman

	Texture p_texture;
	p_texture.loadFromFile("pacman.png");
	Pacman pacman(p_texture);

	//owoc
	Texture o_texture;
	o_texture.loadFromFile("owoc.png");

	//duch
	Texture d_texture;
	d_texture.loadFromFile("duch.png");
	

	vector<unique_ptr<RuchomySprite>> figures;

	Clock s_clock;

	for (int i = 0; i < 20; i++) {

		Vector2f position(rand() % (window.getSize().x - 100), (rand() % (window.getSize().y - 100)) + i * 10);
		figures.emplace_back(make_unique<Duch>(Duch(d_texture, position)));


	}


	for (int i = 0; i < 5; i++) {
		figures.emplace_back(make_unique<Owoc>(Owoc(o_texture)));


	}

	Vector2f scale;

	// some_space_bugs position randomizer v1

	for (int i = 0; i < figures.size(); i++) {

		RuchomySprite& some_shape = dynamic_cast<RuchomySprite&>(*figures[i].get());

		if (pacman.getGlobalBounds().intersects(some_shape.getGlobalBounds())) {

			while (pacman.getGlobalBounds().intersects(some_shape.getGlobalBounds())) {

				Vector2f position(rand() % (window.getSize().x - 100), (rand() % (window.getSize().y - 100)) + i * 10);

				some_shape.setPosition(position);

			}
		}

	}




	// some_space_bugs position randomizer v2
	for (int i = 0; i < figures.size(); i++) {

		RuchomySprite& some_shape = dynamic_cast<RuchomySprite&>(*figures[i].get());

		for (int j = 0; j < figures.size(); j++) {

			Sprite& some_shape2 = dynamic_cast<Sprite&>(*figures[j].get());

			if (some_shape.getGlobalBounds().intersects(some_shape2.getGlobalBounds()) && j != i) {

				while (some_shape.getGlobalBounds().intersects(some_shape2.getGlobalBounds())) {

					Vector2f position(rand() % (window.getSize().x - 100), (rand() % (window.getSize().y - 100)) + i * 10);

					some_shape.setPosition(position);

				}
			}
		}
	}

	Vector2f mouse_pos;





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


			if (Mouse::isButtonPressed(Mouse::Left)) {
				mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));
			}




			window.clear();

			for (const auto& s : figures) {

				RuchomySprite& some_figure = dynamic_cast<RuchomySprite&>(*s.get());

				if (some_figure.getScale().x < 1) {
					Duch& some_duch = dynamic_cast<Duch&>(*s.get());
					some_duch.animuj(some_duch.d_velocity);
				}
				else {
					Owoc& some_owoc = dynamic_cast<Owoc&>(*s.get());

					if (some_owoc.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && s_clock.getElapsedTime().asSeconds() > 0.25 && some_owoc.getScale().x < 8) {

						Vector2f increase_scale(some_owoc.getScale().y * 2, some_owoc.getScale().y * 2);
						some_owoc.setScale(increase_scale);

						s_clock.restart();
					}


					some_owoc.animuj(some_owoc.o_velocity);
				}



				window.draw(*s);
			}
			

			for (auto itr = figures.begin(); itr != figures.end();) {
				RuchomySprite& some_figure = dynamic_cast<RuchomySprite&>(*itr->get());
				if (some_figure.getGlobalBounds().intersects(pacman.getGlobalBounds())) {
					if (some_figure.getScale().x != 1) {
						pacman.hp--;
						pacman.setPosition(384, 385);
					}
					else {
						pacman.points+=100;
					}


					itr = figures.erase(itr);
				}
				else {
					++itr;
				}


			}





			pacman.control();
			window.draw(pacman);
			window.display();


			if (pacman.points == 500) {
				cout << "WYGRANA" << endl;
				game = false;
				break;
			}
			
			if (pacman.hp == 0) {
				cout << "PRZEGRANA" << endl;
				game = false;
				break;
			}



		}

	}
	return 0;
}