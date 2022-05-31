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


class RuchomySprite:public Sprite
{
public:


	RuchomySprite() = default;
	virtual ~RuchomySprite() = default;

	virtual void animate() {}
	void animuj(const Vector2f& velocity);





};

