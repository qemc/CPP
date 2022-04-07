#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace sf;

//klasa samolotu, który jest poruszany przez gracza
class Gracz:public Drawable
{
private:
	float x, y;
	Texture textura_samolotu;
	Texture textura_pocisku;
	const float predkosc_samolotu = 15.f;
	Vector2f predkosc{ predkosc_samolotu, 0.f };
	CircleShape pocisk;
	int ogranicz_strzal = 0;
	float left();
	float right();
	float top();
	float bottom();
	void draw(RenderTarget& target, RenderStates state) const override;
public:
	Sprite samolot_gracz;
	vector<CircleShape> pociski;
	//o tego momentu w dó³ do zmiany nazwy funkcji na wszelki wypadek 
	void odswiez();

	Gracz(float k_x = 400.f, float k_y = 740.f);
	~Gracz() = default;




};
//klasa wrogich samolotów
class Bot :public Gracz {
private:
	Texture texture;
	int ogranicz_bot = 0;
public:
	vector<RectangleShape> boty;
	RectangleShape bot;

	static float pkt_gracz;
	static float pkt_enemy;
	static float bot_poziom;

	static float city_hp;
	void spw();
	Bot();
	~Bot() = default;
	void odswiez();




};


