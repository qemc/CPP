#include "Duch.h"


Duch::Duch(const Texture& texture, const Vector2f& position) {

	setTexture(texture);
	setPosition(position);

	setScale(0.99, 1);

	uniform_int_distribution<int> random_int(0,100);
	random_device rd;
	mt19937 randomNumbers(rd());

	if (random_int(randomNumbers) < 50) {
		d_velocity.x = 2;
	}
	else {
		d_velocity.x = -2;
	}

	d_velocity.y = 0;

}