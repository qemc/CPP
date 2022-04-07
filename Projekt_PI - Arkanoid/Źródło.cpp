#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Plane.h"
#include <cstdlib>
#include"Counter.h"
#include <vector>


using namespace std;
using namespace sf;

//zmienne statyczne klas
float Bot::pkt_enemy;
float Bot::pkt_gracz;
float Bot::bot_poziom =2;

float Bot::city_hp = 5;
int main() {



	//                 (DEKLARACJE OBIEKTÓW KLAS):
	RenderWindow window(VideoMode(1000, 800), "The Battle Of England");
	Event event;
	Gracz plane1;
	Bot enemy1;
	Counter c1;
	Texture texturebg;
	texturebg.loadFromFile("bg.png");
	texturebg.setRepeated(false);
	window.setFramerateLimit(75);
	bool game = true;
	
	Sprite sprite(texturebg);
	sprite.setTextureRect(IntRect(0, 0, 800, 800));

	//pêtla odpowiadaj¹ca za wyœwitlania okna
	while (true) {
	
		window.clear(Color::Black);
		window.draw(sprite);
		window.draw(plane1);
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				break;
			}
		}
		while (game == true) {
			if (Bot::city_hp > 0) {
				window.clear();
				window.draw(c1);
				c1.hide();
				//pêtla, daj¹ca mo¿liwoœæ operowania na oknie
				while (window.pollEvent(event)) {
					if (event.type == Event::Closed) {
						window.close();
						break;
					}
				}
				window.draw(sprite);
				window.draw(plane1);
				//pêtla rysuj¹ca samoloty
				for (size_t i = 0; i < enemy1.boty.size(); i++) {
					window.draw(enemy1.boty[i]);
				}
				//pêtla rysuj¹ca pociski
				for (size_t i = 0; i < plane1.pociski.size(); i++) {
					window.draw(plane1.pociski[i]);
				}
				plane1.odswiez();
				enemy1.odswiez();
				//pêtla sprawdzaj¹ca kolizjê 
				for (size_t t = 0; t < plane1.pociski.size(); t++) {

					for (size_t d = 0; d < enemy1.boty.size(); d++) {

						if (plane1.pociski[t].getGlobalBounds().intersects(enemy1.boty[d].getGlobalBounds())) {

							plane1.pociski.erase(plane1.pociski.begin() + t);
							enemy1.boty.erase(enemy1.boty.begin() + d);
							Bot::pkt_gracz++;
							cout << Bot::pkt_gracz << endl;
							cout << Bot::bot_poziom;
							if (Bot::pkt_enemy > 1000) {
								Bot::bot_poziom++;
								//cout << _vv;
								Bot::pkt_enemy = 0;
							}
							break;

						}
					}
				}
				Bot::pkt_enemy++;
				c1.update_all();
				window.display();
			}
			else {
				c1.updater();
				game = false;
				Bot::pkt_gracz = 0;
				Bot::bot_poziom = 2;
				Bot::pkt_enemy = 0;
				Bot::city_hp = 5;
				enemy1.boty.clear();
				plane1.pociski.clear();
				
				

			}
		}
		if (game == false) {
			window.draw(c1);
			window.display();
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				game = true;
				cout << "dziala";
				plane1.samolot_gracz.setPosition(Vector2f(400.f, 740.f));
				
			}
		}
	}
		return 0;
	}
