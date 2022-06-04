#pragma once
//cpp
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cstdlib>
#include <time.h>
//sfml
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;


class AnimatedSprite :public Sprite
{
public:
	AnimatedSprite() = default;
	virtual ~AnimatedSprite() = default;

	virtual void animate() {}




};
