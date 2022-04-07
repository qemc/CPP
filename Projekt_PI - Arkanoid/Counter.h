#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <vector>
//klasa która odpowiada za dzia³anie banera bocznego
using namespace std;
using namespace sf;

class Counter:public Drawable
{
private:

	float x, y;
	Font font1;
	Font font2;
	Text punkty;
	Text rekord;
	Text bot_lvl_text;
	Text bot_lvl_lbl;
	Text punkty_lbl;
	Text pozostale_zycia;
	Text pozostale_zycia_lbl;
	Text retry;
	void draw(RenderTarget& target, RenderStates state) const override;
	void update();
	void update1();
	void update2();
	void best();

public:

	Counter(float _x = 900, float _y = 50);
	void updater();
	~Counter() = default;
	void update_all();
	void hide();
};

