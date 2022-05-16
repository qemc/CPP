#pragma once
//CPP
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//NAMESPACES
using namespace std;
using namespace sf;

//CLASSES
class  CustomRectangleShape: public RectangleShape
{
public:
	
	CustomRectangleShape(const Vector2f& size, const Vector2f& position);
	void randomize_move_dir();
	Vector3i randomize_color();
	void set_speed();
	Vector2f velocity;
	void animate();

	
	

	void select();
	void unselect();

	Vector2f get_mouse_pos;
	


private:
	float velocity_x = 1;
	float velocity_y = 1;
	bool is_selected = false;



	

};

