#pragma once
#include <iostream>


//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Bullets:public CircleShape
{
private:
	
	Vector2f player_shoot_pos;
	int bullets_hp = 2;

public:

	Vector2f velocity;

	Bullets(const Vector2f &position, const Vector2f& velocity_,const Vector2f& m_pos);	
};

