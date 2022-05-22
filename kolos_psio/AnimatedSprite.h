#pragma once

//cpp libs
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
//sfml libs
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;




class AnimatedSprite:public Sprite
{
public:
	static Clock a_clock;
	static Time a_time;
	AnimatedSprite() = default;
	virtual ~AnimatedSprite() = default;

	virtual void animate(){}




};

