#pragma once
#include "Menu.h"



class Stats :public Menu
{

public:

	Clock game_clock;
	Stats();
	Font font;
	void update(const Player& player/*, const Enemy& enemy*/);
	int mins = 0;





};

