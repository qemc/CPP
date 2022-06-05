#pragma once

//CPP
#include <iostream>

#include "Bullets.h"
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Soldiers:public CircleShape
{
public:

	static Clock a_clock;
	static Time a_time;
	Soldiers() = default;
	virtual ~Soldiers() = default;
	//Soldier
	CircleShape aim;
	CircleShape main;

	//CircleShape range;

	Vector2f base_position;
	Vector2f dirVec;


	void get_dir_vec(const Vector2f& mouse_pos);

	float angle(Vector2f dirVec);

	void set_circles();

	void update();

	void draw(RenderTarget& target, RenderStates state) const override;

	Vector2f shootDir;
	Vector2f mouse_pos;
	Vector2f current_pos;

	vector<Bullets> bullets_;

	Vector2f norm(const Vector2f& x, const Vector2f& y);

	
	
	Vector2f set_bullet_spedd();




};

