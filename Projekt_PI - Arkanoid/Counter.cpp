#include "Counter.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include "Plane.h"
#include <cstdlib>
#include <fstream>
#include <vector>

Counter::Counter(float _x,float _y) {

	x = _x;
	y = _y;
	//³adowanie czcionek
	font1.loadFromFile("font.ttf");
	font2.loadFromFile("font.ttf");
	
	//baner poziom przeciwnika
	bot_lvl_lbl.setCharacterSize(24);
	bot_lvl_lbl.setFillColor(sf::Color::White);
	bot_lvl_lbl.setStyle(Text::Bold);
	bot_lvl_lbl.setPosition(x - 90, y - 30);
	bot_lvl_lbl.setFont(font1);
	bot_lvl_lbl.setString("enemy lvl:");

	//baner punkty gracza
	punkty_lbl.setCharacterSize(24);
	punkty_lbl.setFillColor(sf::Color::White);
	punkty_lbl.setStyle(Text::Bold);
	punkty_lbl.setPosition(x - 90, 120 );
	punkty_lbl.setFont(font2);
	punkty_lbl.setString("points:");
	//baner pozosta³e punkty zdrowia
	pozostale_zycia_lbl.setCharacterSize(24);
	pozostale_zycia_lbl.setFillColor(sf::Color::White);
	pozostale_zycia_lbl.setStyle(Text::Bold);
	pozostale_zycia_lbl.setPosition(x - 93, 300);
	pozostale_zycia_lbl.setFont(font2);
	pozostale_zycia_lbl.setString("lives left:");



}
//funkcja daj¹ca mo¿liwoœæ rysowania poszczególnych elementów klasy, obiektem jest ca³ywyœwietlany sidebar 
void Counter::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->punkty, state);
	target.draw(this->bot_lvl_text, state);
	target.draw(this->bot_lvl_lbl, state);
	target.draw(this->punkty_lbl, state);
	target.draw(this->pozostale_zycia, state);
	target.draw(this->pozostale_zycia_lbl, state);
	target.draw(this->rekord, state);
	target.draw(this->retry, state);

}
//update dla baneru z opisem, oraz pozosta³ych punktów zdrowia
void Counter::update1() {
	bot_lvl_text.setCharacterSize(24);
	bot_lvl_text.setFillColor(sf::Color::White);
	bot_lvl_text.setStyle(Text::Bold);
	bot_lvl_text.setPosition(x- 90,y+20);
	bot_lvl_text.setFont(font2);
	bot_lvl_text.setOrigin(bot_lvl_text.getCharacterSize() / 2, bot_lvl_text.getCharacterSize() / 2);


	pozostale_zycia.setCharacterSize(24);
	pozostale_zycia.setFillColor(sf::Color::White);
	pozostale_zycia.setStyle(Text::Bold);
	pozostale_zycia.setPosition(x- 90, y+300);
	pozostale_zycia.setFont(font2);
	pozostale_zycia.setOrigin(pozostale_zycia.getCharacterSize() / 2, pozostale_zycia.getCharacterSize() / 2);
}
//update dla punktów
void Counter::update2() {
	
	punkty.setCharacterSize(24);
	punkty.setFillColor(sf::Color::White);
	punkty.setStyle(Text::Bold);
	punkty.setPosition(x-90, y+120);
	punkty.setFont(font1);
	punkty.setOrigin(punkty.getCharacterSize() / 2, punkty.getCharacterSize() / 2);


}

//update dla zmiennych wyswietlanych [pkt zdrowia, pkt]
void Counter::update() {
	float ss = Bot::pkt_gracz;
	float ss2 = Bot::bot_poziom -1;
	float ss3 = Bot::city_hp;
	
	int s = (int)ss;
	int s2 = (int)ss2;
	int s3 = (int)ss3;
	punkty.setString(" " + to_string(s));
	bot_lvl_text.setString(" " + to_string(s2));
	pozostale_zycia.setString(" "+to_string(s3));
	

}

//update baneru "PRESS SPACE TO RETRY"
void Counter::updater() {

	retry.setCharacterSize(24);
	retry.setFillColor(sf::Color::White);
	retry.setStyle(Text::Bold);
	retry.setPosition(x- 90, y + 495);
	retry.setFont(font1);
	retry.setOrigin(retry.getCharacterSize() / 2, retry.getCharacterSize() / 2);
	retry.setString(" Press\n space\n to retry");



	
}

//zarz¹dzaj¹ca najlepszym wynikiem w grze
void Counter::best() {

	fstream plik;
	plik.open("wynik.txt", ios::in | ios::out);
	string line;
	string line1;
	string bestt;

	(getline(plik, line));
	plik.close();

	int ll = stoi(line);

	if (ll < Bot::pkt_gracz) {
		ofstream plik1;
		plik1.open("wynik.txt", ios::trunc);
		plik1.close();
		plik.open("wynik.txt", ios::in | ios::out);
		plik << Bot::pkt_gracz;
		plik.close();
		plik.open("wynik.txt", ios::in | ios::out);

		(getline(plik, line1));
		bestt = line1;
		plik.close();
	}
	else {
		bestt = line;
	}
	rekord.setCharacterSize(24);
	rekord.setFillColor(sf::Color::White);
	rekord.setStyle(Text::Bold);
	rekord.setPosition(x - 90, y + 395);
	rekord.setFont(font1);
	rekord.setOrigin(rekord.getCharacterSize() / 2, rekord.getCharacterSize() / 2);
	rekord.setString(" top_score:\n "+bestt);
}
void Counter::update_all() {

	this->update();
	this->update1();
	this->update2();
	this->best();

}
void Counter::hide() {
	retry.setString("");
}