#pragma once
#include "AnimatedSprite.h"
class Spaceship:public AnimatedSprite
{
public:
	bool rusz = false;
	Vector2f mouse_pos;
	void move_();
	Vector2f movement;
	Spaceship(const Texture& texture);
	void colision();
	bool rectangle_collisiotn(const RectangleShape &rectangle);
	int points = 0;
	int _hp;


};

