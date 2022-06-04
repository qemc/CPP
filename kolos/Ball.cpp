#include "Ball.h"



Ball::Ball(const Texture& texture, const IntRect& choose_sprite) {

	setPosition(400, 400);
	setTexture(texture);
	setTextureRect(choose_sprite);

	uniform_int_distribution<int> random_int(1,4);
	random_device rd;
	mt19937 randomNumbers(rd());

	//random_int(randomNumbers) - losowa liczba z przedzia³u wy¿ej
	int rand_int = random_int(randomNumbers);


	if (rand_int == 1) {
		b_velocity.x = 2;
		b_velocity.y = 4;
	}
	else if(rand_int == 2) {
		b_velocity.x = -2;
		b_velocity.y = 4;
	}
	else if (rand_int == 3) {
		b_velocity.x = 2;
		b_velocity.y = -4;
	}
	else if (rand_int == 4) {
		b_velocity.x = -2;
		b_velocity.y = -4;
	}



}

void Ball::movement() {

	move(b_velocity);


}

void Ball::movement_c() {


	

}