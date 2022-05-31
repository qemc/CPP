#include "Owoc.h"



Owoc::Owoc(const Texture& texture) {

	setTexture(texture);

	int pos_x = rand() % 800;

	setPosition(Vector2f(pos_x,0));


	uniform_int_distribution<int> random_int(1, 4);
	random_device rd;
	mt19937 randomNumbers(rd());

	o_velocity.x = 0;
	o_velocity.y = random_int(randomNumbers);

}


