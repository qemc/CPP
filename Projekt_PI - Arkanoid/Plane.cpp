#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <vector>
#include "Plane.h";
using namespace std;
using namespace sf;
//					(KLASA PLANE)
Gracz::Gracz(float k_x, float k_y) {

	x = k_x;
	y = k_y;
	//					(SAMOLOT)
	textura_samolotu.loadFromFile("plane.png");//import textury
	samolot_gracz.setTexture(textura_samolotu);//ustawianie tekstury na samolot
	samolot_gracz.setOrigin(60, 60);//ustawianie punktu odniesienia na œrodek w clu u³atwienia dalszej pracy
	samolot_gracz.setPosition(Vector2f(x, y));//ustawienie bazowej pozycji 
	//					(STRZELANIE)
	textura_pocisku.loadFromFile("bullet.png");
	pocisk.setOrigin(5, 5);
	pocisk.setRadius(10.f);
	pocisk.setTexture(&textura_pocisku);
	pocisk.setOutlineColor(Color::Magenta);
	pocisk.setOutlineThickness(2.f);
	pocisk.setFillColor(Color::Red);
	pociski.push_back(CircleShape(pocisk));


}
//metoda poznalazj¹ca wyœwietliæ obraz
void Gracz::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->samolot_gracz, state);

}

float Gracz::left() {
	return this->samolot_gracz.getPosition().x - 50;
}

float Gracz::right() {
	return this->samolot_gracz.getPosition().x + 50;
}

float Gracz::top() {
	return this->samolot_gracz.getPosition().y - 35;
}
float Gracz::bottom() {
	return this->samolot_gracz.getPosition().y + 35;
}
void Gracz::odswiez() {
	this->samolot_gracz.move(predkosc);
	this->ogranicz_strzal++;
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 30) {
		predkosc.x = -predkosc_samolotu;
		this->textura_samolotu.loadFromFile("plane2-l.png");//import textury
		this->samolot_gracz.setTexture(textura_samolotu);//ustawianie tekstury na samolot

	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 770) {
		this->predkosc.x = predkosc_samolotu;
		this->textura_samolotu.loadFromFile("plane2-r.png");//import textury
		this->samolot_gracz.setTexture(textura_samolotu);//ustawianie tekstury na samolot

	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && ogranicz_strzal >= 14) {
		



		if (this->pociski.size()%2==0) {
			this->pocisk.setPosition(this->samolot_gracz.getPosition().x + 30, this->samolot_gracz.getPosition().y);

		}
		else {
			pocisk.setPosition(samolot_gracz.getPosition().x - 30, this->samolot_gracz.getPosition().y);
		}
		this->pociski.push_back(CircleShape(this->pocisk));
		
		


		this->ogranicz_strzal = 0;
		this->textura_samolotu.loadFromFile("plane.png");//import textury
		this->samolot_gracz.setTexture(textura_samolotu);//ustawianie tekstury na samolot



	}
	else {
		predkosc.x = 0;
		this->textura_samolotu.loadFromFile("plane.png");//import textury
		this->samolot_gracz.setTexture(textura_samolotu);//ustawianie tekstury na samolot
	}


	for (size_t t = 0; t < this->pociski.size(); t++) {
		this->pociski[t].move(0.f, -10.f);

		if (this->pociski[t].getPosition().y <= 10) {


			this->pociski.erase(this->pociski.begin() + t);
		}

	}
	}



//								(KLASA ENEMY)


Bot::Bot() {
	

	texture.loadFromFile("enemy.png");//import textury
	bot.setTexture(&texture);
	bot.setOrigin(60, 60);
	bot.setSize(Vector2f(120.f, 120.f));


	//enemies.push_back(RectangleShape(enemy));

}



void Bot::spw() {
	if (ogranicz_bot >= 108 - (10 * (Bot::bot_poziom)+1)) {

		bot.setPosition((rand() % int(800 - bot.getSize().x) + 50), 0.f);
		boty.push_back(RectangleShape(bot));
		ogranicz_bot = 0;
	}
}

void Bot::odswiez()
{


	if (this->ogranicz_bot < 148 - (10 * (Bot::bot_poziom)+1)) {
		this->ogranicz_bot++;
	}
	for (size_t t = 0; t < this->boty.size(); t++) {
		this->boty[t].move(0.f, bot_poziom);
		if (this->boty[t].getGlobalBounds().intersects(Gracz::samolot_gracz.getGlobalBounds())) {
			cout << "k";
		}

		if (this->boty[t].getPosition().y > 800) {

			this->boty.erase(this->boty.begin() + t);
			cout << "ough";
			city_hp--;
		}
	}

	this->spw();
}


