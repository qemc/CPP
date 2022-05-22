#include "Asteroid.h"

Asteroid::Asteroid(const Vector2f& position, const Texture& texture) {
	setPosition(position);
	setTexture(texture);
	setScale(0.125, 0.125);
	
	uniform_int_distribution<int> random_int(-4, 4);
	random_device rd;
	mt19937 randomNumbers(rd());

	float x_ = random_int(randomNumbers);
	float y_ = random_int(randomNumbers);





	asteroid_velocity.x = x_ ;
	asteroid_velocity.y = y_ ;

	
}

void Asteroid::move_() {
	move(asteroid_velocity.x * 100 * AnimatedSprite::a_time.asSeconds(),asteroid_velocity.y * 100 * AnimatedSprite::a_time.asSeconds());
}

void Asteroid::colision() {


	uniform_int_distribution<int> random_int(0, 800);
	random_device rd;
	mt19937 randomNumbers(rd());


	if (getPosition().x - getGlobalBounds().width >= 800) {
		setPosition(0, random_int(randomNumbers));
	}

	if (getPosition().x + getGlobalBounds().height <= 0) {
		setPosition(800, random_int(randomNumbers));

	}
	if (getPosition().y - getGlobalBounds().height >= 800) {
		setPosition(random_int(randomNumbers), 0);
	}
	if (getPosition().y + getGlobalBounds().height <= 0) {
		setPosition(random_int(randomNumbers), 800);
	}


}