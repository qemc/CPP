#pragma once
#include "RuchomySprite.h"


class Pacman:public RuchomySprite
{
public:

	Vector2f p_velocity;
	Pacman(const Texture& textrue);
	void control();
	bool rusz = false;

	int hp = 3;
	int points = 0;


};



